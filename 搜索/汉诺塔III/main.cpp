//
//  main.cpp
//  汉诺塔III
//
//  Created by APTX on 28/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-2064

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long F(int num){
    if(num == 1) return 2;
    else
        return 3 * F(num-1) + 2;
}
int main(int argc, const char * argv[]) {
    int n;
    while(cin >> n){
        printf("%lld\n", F(n));
    }
    return 0;
}
