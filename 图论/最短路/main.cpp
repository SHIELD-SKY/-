//
//  main.cpp
//  最短路
//
//  Created by APTX on 25/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-2544
//Floyd

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans[101][101];

int main(int argc, const char * argv[]) {
    int n, m;
    while (cin >> n >> m && n && m) {
       // if(n == 0 && m == 0) break;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) {
                ans[i][j] = -1;
            }
            ans[i] [i] = 0;
        }
        while (m--) {
            int a, b, c;
            cin >> a >> b >>c;
            ans[a][b] = ans[b][a] = c;
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                   // ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                    if(ans[i][k] == -1 || ans[k][j] == -1) continue;
                    if(ans[i][j] == -1 || ans[i][k]+ans[k][j] < ans[i][j])
                        ans[i][j] = ans[i][k] + ans[k][j];
                }
            }
        }
        cout << ans[1][n] << endl;
    }
    return 0;
}
