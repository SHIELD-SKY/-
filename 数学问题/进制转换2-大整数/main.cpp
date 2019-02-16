//
//  main.cpp
//  进制转换2-大整数
//
//  Created by APTX on 16/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstring>
#define maxDigits 100
using namespace std;

struct bigInteger{
    int digit[maxDigits];
    int size;
    void init(){
        for(int i = 0; i < maxDigits; i++) digit[i] = 0;
        size = 0;
    }
    
    void set(int x){
        init();
        do{
            digit[size++] = x % 10000;
            x /= 10000;
        }while( x != 0);
    }
    void output(){
        for(int i = size - 1; i >= 0; i--){
            if(i != size - 1) printf("%04d", digit[i]);
            else printf("%d", digit[i]);
        }
        printf("\n");
    }
    
    bigInteger operator * (int x) const{
        bigInteger ret;
        ret.init();
        int carry = 0;
        for(int i = 0; i < size; i++){
            int tmp = x * digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size++] = tmp;
        }
        if(carry != 0){
            ret.digit[ret.size++] = carry;
        }
        return ret;
    }
    bigInteger operator + (const bigInteger &A) const{
        bigInteger ret;
        ret.init();
        int carry = 0;
        for(int i = 0; i < A.size || i < size; i++){
            int tmp = A.digit[i] + digit[i] + carry;
            carry = tmp / 10000;
            tmp %= 10000;
            ret.digit[ret.size++] = tmp;
        }
        if(carry != 0){
            ret.digit[ret.size++] = carry;
        }
        return ret;
    }
    bigInteger operator / (int x) const{
        bigInteger ret;
        ret.init();
        int remainder = 0;//余数
        for(int i = size - 1; i >= 0; i--){//从最高位至最低位依次完成计算
            int t = (remainder * 10000 + digit[i]) / x; //计算当前位数值加上高位剩余的余数的和对x求得的商
            int r = (remainder * 10000 + digit[i]) % x; //计算当前位数值加上高位剩余的余数的和对x求模后得的余数
            ret.digit[i] = t;//保存本位的值
            remainder = r;//保存至本位为止的余数
        }
        ret.size = 0;//返回高精度整数的size初始值为0,即当所有位数字都为0 时,digit[0]代表数字0,作为最高有效位,高精度整数即为数字0
        for(int i = 0; i < maxDigits; i++){
            if(digit[i] != 0) ret.size = i;
        }
        ret.size++;
        return ret;
    }
    int operator % (int x) const{
        int remainder = 0;
        for(int i = size - 1; i >= 0; i--){
            int  t = (remainder * 10000 + digit[i]) / x;
            int r = (remainder * 10000 + digit[i]) % x;
            remainder = r;  //过程同高精度整数对普通整数求商
        }
        return remainder;
    }
}a, b, c;

char str[10000];
char ans[10000];


int main(int argc, const char * argv[]) {
    int n, m;
    while (cin >> m >> n) {
        cin >> str;//输入m进制数
        int L = strlen(str);
        a.set(0);//a初始值为0,用来保存转换成10进制的m进制数
        b.set(1);//b初始值为1,在m进制向10进制转换的过程中,依次代表每一位的权重
        for(int i = L - 1; i >= 0; i--){   //由低位至高位转换m进制数至相应的10进制数
            int t;
            if(str[i] >= '0' && str[i] <= '9'){
                t = str[i] - '0';
            }
            else t = str[i] - 'A' + 10; //确定当前位字符代表的数字
            a = a + b * t; //累加当前数字乘当前位权重的积
            b = b * m;//计算下一位权重
        }
        int size = 0;
        do{
            int t = a % n;
            if(t >= 10) ans[size++] = t - 10 + 'a';
            else ans[size++] = t + '0';
            a = a / n;
        }while( a.digit[0] != 0 || a.size != 1);
        for(int i= size - 1; i >= 0; i--) printf("%c", ans[i]);
        printf("\n");
    }
    return 0;
}
