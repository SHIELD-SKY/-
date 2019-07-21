//
//  main.cpp
//  叠框
//
//  Created by APTX on 1/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-2074

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char * argv[]) {
    int outPutBuf[82][82];
    char a, b;
    int n;
    bool firstCase = true;
    
    while (scanf("%d %c %c", &n, &a, &b) == 3) {
        
        if (firstCase == true) {
            firstCase = false;
        }
        else printf("\n");
        
        for (int i = 1, j = 1; i <= n; i += 2, j++) {//利用 初始值为 1 的循环指示变量 i 来表示边长长度，并在每次循环结束后加 2
            int x = n / 2 + 1, y = x;
            
           // x  -= j - 1; y -= j - 1;
            x = x - j + 1; y = y - j + 1;    ///计算每个圈右上角点的坐标
            
            char c = j % 2 == 1 ? a : b;
            
            for(int k = 1; k <= i; k++)
            {
                outPutBuf[x + k - 1][y] = c;  //左边赋值
                outPutBuf[x][y + k -1] = c; //上
                outPutBuf[x + i - 1][y + k - 1] = c; //右
                outPutBuf[x + k - 1][y + i - 1] = c; //下
            }
        }
        if (n != 1) {
            outPutBuf[1][1] = ' ';
            outPutBuf[n][1] = ' ';
            outPutBuf[1][n] = ' ';
            outPutBuf[n][n] = ' ';
        }
        for (int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++){
                printf("%c", outPutBuf[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
