//
//  main.cpp
//  拦截导弹
//
//  Created by APTX on 1/3/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/OpenJ_Bailian-2945

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[26];
int f[26];

int main(int argc, const char * argv[]) {
    int n;
    while ( cin >> n) {
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            f[i] = 1;
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j < i; j++){
                if(a[j] >= a[i] && f[j]+1 > f[i]){
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
