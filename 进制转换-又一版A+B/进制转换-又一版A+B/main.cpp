//
//  main.cpp
//  进制转换-又一版A+B
//
//  Created by APTX on 9/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
using namespace std;
void jin(int n, int k, int* a, int& cnt)
{
    //将十进制正整数n转换为k进制后保存在数组a中
    cnt = 0;
    if(n == 0) {        //n等于0，转换后就一个零
        a[cnt++] = 0;
    }
  
    while (n>0) {      //非零
        a[cnt++] = n % k;
        n /= k;
    }
}
int main(int argc, const char * argv[]) {
    int k, a, b;
    int num[20], cnt;
    while (scanf("%d%d%d", &k, &a, &b)==3 && k) {
        jin(a+b, k, num, cnt);
        for(int i = cnt-1; i >=0; i--){
            printf("%d", num[i]);
        }
        printf("\n"); 
    }
    return 0;
}
