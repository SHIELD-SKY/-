//
//  main.cpp
//  蛇形填数
//
//  Created by APTX on 31/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
#define maxn 20

using namespace std;

int a[maxn][maxn];

int main(int argc, const char * argv[]) {
    int n, x, y, tot = 0;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    tot = a[x=0][y=n-1] = 1;
    while (tot < n*n) {
        while (x+1 < n && !a[x+1][y])  a[++x][y] = ++tot;
        while (y-1 >= 0 && !a[x][y-1] ) a[x][--y] = ++tot;
        while (x-1 >= 0 && !a[x-1][y])  a[--x][y] = ++tot;
        while (y+1 < n && !a[x][y+1]) a[x][++y] = ++tot;
    }
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
