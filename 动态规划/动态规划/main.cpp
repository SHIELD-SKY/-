//
//  main.cpp
//  动态规划
//
//  Created by APTX on 28/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//N阶楼梯上楼问题

#include <iostream>
#include <cstdio>
using namespace std;

long long F[91];

int main(int argc, const char * argv[]) {
    F[1] = 1;
    F[2] = 2;
    for(int i = 3; i <= 90; i++){
        F[i] = F[i-1] + F[i-2];
    }
    int n;
    while (cin >> n) {
        printf("%lld\n",F[n]);
    }
    return 0;
}
