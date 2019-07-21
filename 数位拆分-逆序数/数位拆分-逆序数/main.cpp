//
//  main.cpp
//  数位拆分-逆序数
//
//  Created by APTX on 9/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>

int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d",&n) == 1) {
        int m = 0;
        int tmp = n;
        while (tmp > 0) {
            m = m * 10 + tmp % 10;  //往前进位加上个位
            tmp = tmp / 10;     //擦除个位
        }
        if(m % n == 0){
            printf("%d*%d=%d\n", n,m/n,m);
        }
        else{
            printf("%d ", n);
            //打印m的前导零
            tmp = n;
            while (tmp > 10 && tmp % 10 == 0) {
                printf("0");
                tmp = tmp / 10;
            }
            printf("%d\n", m);
        }
    }
    return 0;
}
