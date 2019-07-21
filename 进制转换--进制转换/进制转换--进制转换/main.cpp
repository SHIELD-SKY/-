//
//  main.cpp
//  进制转换--进制转换
//
//  Created by APTX on 9/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
using namespace std;
void jin(int n, int k, int* a, int& cnt){
    cnt = 0;
    if(n == 0){
        a[cnt++] = 0;
    }
    while (n > 0) {
        a[cnt++] = n % k;
        n /= k;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int a[20], cnt;
    while (scanf("%d", &n) == 1) {
        jin(n, 16, a, cnt);
        for(int i = cnt-1; i >= 0; i--)
        {
            if(a[i]>=10){
                printf("%c", a[i]-10+'A');
            }
            else{
                printf("%d", a[i]);
            }
        }
        printf("H\n");
    }
    return 0;
}
