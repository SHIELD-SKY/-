//
//  main.cpp
//  分数求和
//
//  Created by APTX on 9/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//http://www.dengdengoj.cc/problem.php?id=1109

#include <iostream>
using namespace std;

struct FenShu{
    int up;
    int down;
};

int gcd(int a, int b){
//    if(b > a){
//        a = a ^ b;
//        b = a ^ b;
//        a = a ^ b;
//    }
   // cout << a << " " << b << endl;
    return b == 0 ? a : gcd(b, a%b);
}

// a/b+c/d = (a*d+c*b)/b*d
FenShu add(FenShu a, FenShu b){
    FenShu sum;
    sum.up = a.up * b.down + b.up * a.down;
    sum.down = a.down * b.down;
    
    if(sum.up == 0) sum.down = 1;
    if(sum.down < 0){    //约定分子带负号
        sum.up = -sum.up;
        sum.down = -sum.down;
    }
    int m = gcd(abs(sum.up), abs(sum.down)); //分子分母的最大公约数
    //约分
    sum.up /= m;
    sum.down /= m;
    return sum;
}
int main(int argc, const char * argv[]) {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        FenShu ans = {0,1}, tmp;
        for(int i = 0; i < n; i++)
        {
            scanf("%d/%d", &tmp.up, &tmp.down);
            ans = add(ans, tmp);
        }
        if(ans.up == 0) printf("0\n");
        else if(abs(ans.up) % ans.down == 0) printf("%d\n", ans.up / ans.down);
        else if(abs(ans.up) > ans.down) printf("%d %d %d\n", ans.up / ans.down, abs(ans.up)%ans.down, ans.down);
        else printf("%d %d\n", ans.up, ans.down);
    }
    //cout << gcd(6, 12);
    return 0;
}
