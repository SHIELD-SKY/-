//
//  main.cpp
//  进制转换
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/OpenJ_Bailian-2710

#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, const char * argv[]) {
    int a, b;
    char str[40];
    while (cin >> a >> str >> b) {
        int tmp = 0, lenth = strlen(str), c = 1;//tmp为我们将要计算的a进制对 应的十进制数,lenth为字符串长度方便我们从低位到高位遍历每个数位上的数,c为各个数位的权重初始化为1,表示最低位数位权重为1,之后每位权重都是前一位权重的a倍
        for(int i = lenth -1; i >= 0; i--)
        {
            int x;
            if(str[i] >= '0' && str[i] <= '9'){
                x = str[i] - '0';
            }
            else if(str[i] >= 'a' && str[i] <= 'z'){
                x = str[i] - 'a' + 10;
            }
            else if(str[i] >= 'A' && str[i] <= 'Z'){
                x = str[i] - 'A' + 10;
            }
            tmp += x * c;
            c *= a;
        }
        char ans[40];
        int size = 0;
        do{
            int x = tmp % b;
            ans[size++] = (x < 10) ? x +'0' : x - 10 + 'A';
            tmp /= b;
        }while (tmp);
        
        for(int i = size-1; i >= 0; i--){
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
