//
//  main.cpp
//  人见人爱A^B
//
//  Created by APTX on 15/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-2035

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b;
    while (cin >> a >> b) {
        if( a == 0 && b == 0) break;
        int ans = 1;//保存最终结果变量,初始值为1
        while (b != 0) {//若b不为0，即对b转换二进制过程未结束
            if(b % 2 == 1){//若当前二进制位为1，则需要累乘a的2^k次至变量ans， 其中2^k次为当前二进制位的权重
                ans *= a;//最终结果累乘a
                ans %= 1000;//求其后三位数
            }
            
            b /= 2;//b除以2
            a *= a;//求下一位二进制位的权重，a求其平方，即从a的1次开始，依次求的a 的2次，a的4次...
            a %= 1000;//求a的后三位
        }//一边计算b的二进制值，一边计算a的2^k次，并将需要的部分累乘到变量ans上
        cout << ans << endl;
    }
    return 0;
}
