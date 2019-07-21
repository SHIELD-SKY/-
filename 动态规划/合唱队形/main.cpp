//
//  main.cpp
//  合唱队形
//
//  Created by APTX on 1/3/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/OpenJ_Bailian-2711
//两边LIS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[102];
int f1[102];
int f2[102];

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        memset(f1, 0, sizeof(f2));
        memset(f2, 0, sizeof(f2));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            f1[i] = 1;
            f2[i] = 1;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(a[i] > a[j]){
                    f1[i] = max(f1[i], f1[j]+1);
                }
            }
        }

        
        for(int i = n-1; i >= 1; i--){
            for(int j = n; j > i; j--){
                if(a[i] > a[j]){
                    f2[i] = max(f2[i], f2[j] + 1);
                }
            }
        }
        int maxn = 0;
        for(int i = 1; i <= n; i++){
            maxn = max(maxn, f1[i]+f2[i]-1);
        }
   
        cout << n-maxn << endl;
    }
    return 0;
}
