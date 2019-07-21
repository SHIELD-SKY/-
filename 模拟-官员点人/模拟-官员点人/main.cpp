//
//  main.cpp
//  模拟-官员点人
//
//  Created by APTX on 9/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>

const int maxn = 25;
int flag[maxn];

void shu(int &a, int t, int d, int n){
    //在a上沿d方向走t步
    while (t--) {
        do{
            a += d;
            if(a > n) a = 1;
            if(a < 1) a = n;
        }while(flag[a]);  //flag[a] == 1表示a所指这个人不在队伍里，这一步不算，继续走
    }
}
int main(int argc, const char * argv[]) {
    int n, k, m;
    while (scanf("%d%d%d",&n, &k, &m) == 3) {
        memset(flag, 0, sizeof(flag)); //初始化为0表示全部在队伍里
        int a = n, b = 1;   //初始化所指位置
        int left = n;  //队伍里剩余的人
        while (left > 0) {
            
            shu(a, k, 1, n);  //a 从小到大数
            shu(b, m, -1, n); //b从大往小数
            flag[a] = flag[b] = 1;
            if(a == b) {
                printf("%d", a);
                left--;
            }
            else {
                printf("%d %d", a, b);
                left -= 2;
            }
            if (left) {
                printf(",");
            }
            else printf("\n");
        }
    }
    
    return 0;
}
