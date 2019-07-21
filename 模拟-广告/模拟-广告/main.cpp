//
//  main.cpp
//  模拟-广告
//
//  Created by APTX on 9/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
const int maxn = 110;
int a[maxn][maxn];     //a[i][j] == 0表示（i，j）没有被覆盖,  表示i 到 i+1， j到j+1的面积

int main(int argc, const char * argv[]) {
    int n, m, x1, y1, x2, y2;
    while (scanf("%d%d", &n, &m) == 2) {
        memset(a, 0, sizeof(a));
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            for (int i = x1; i < x2; i++) {
                for(int j = y1; j < y2; j++){
                    a[i][j] = 1;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 0){
                    ans++;
                }
            }
        }
     printf("%d\n", ans);
    }
    return 0;
}
