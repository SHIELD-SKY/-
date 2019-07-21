//
//  main.cpp
//  最长上升子序列
//
//  Created by APTX on 1/3/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/CSU-1047

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1010];
int f[1010];

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            f[i] = 1;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(a[i] > a[j] && f[i] < f[j]+1){
                    f[i] = f[j] + 1;
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans = max(ans, f[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
