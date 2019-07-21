//
//  main.cpp
//  A+B大整数
//
//  Created by APTX on 15/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//2010 年华中科技大学计算机研究生机试真题

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct bigInteger{
    int digit[1000];
    int size;
    void init(){
        for(int i = 0; i < 1000; i++) digit[i] = 0;
        size = 0;
    }

    void set(char str[]){//从字符串中提取整数
        init();//对结构体初始化
        int L = strlen(str);//计算字符串长度
        for(int i = L - 1, j = 0, t = 0, c = 1; i >= 0; i--){//从最后一个字符开始倒序遍历字符串,j控制每4个字符转换为一个数字存入数组,t临时保存字符转换为数字的中间 值,c表示当前位的权重,按1,10,100,1000顺序变化
            t += (str[i] - '0') * c;
            j++;
            c *= 10;
            if(j == 4 || i == 0){//若已经连续转换四个字符,或者已经到达最后一个字符
                digit[ size++ ] = t;
                j = 0;
                t = 0;
                c = 1;
            }
        }
    }
    void output(){
        bool flag = true;
        for(int i = size - 1; i >= 0; i--){
            if(flag && digit[i] == 0) {
                if(i == 0) cout << 0 << endl;
                continue;
            }
            if(flag) { printf("%d", digit[i]); flag = false;}
            else printf("%04d", digit[i]);
//            if(i != size - 1) printf("%04d", digit[i]);//若当前输出的数字不是最高位数字,用%04的输出前导0,即当前数字不足4位时由0补充,如输出110001的后四位数
//            else printf("%d", digit[i]);
        }
        printf("\n");
    }

    bigInteger operator + (const bigInteger &A) const {
        bigInteger ret;
        ret.init();
        int carry = 0;//进位,初试值为0
        for(int i = 0; i < A.size || i < size; i++){
            int tmp = A.digit[i] + digit[i] + carry;
            carry = tmp / 10000;    //计算该位的进位
            tmp %= 10000;
            ret.digit[ ret.size++ ] = tmp;
        }
        if(carry != 0){//计算结束后若最高位有进位
            ret.digit[ ret.size++ ] = carry;
        }
        return ret;
    }
    
    bigInteger operator - (const bigInteger &A) const{
        bigInteger ret;
        ret.init();
        int carry = 0; //借位
        for(int i = 0; i < size; i++){
            int tmp =  digit[i] - A.digit[i] - carry;
            if(tmp < 0) {tmp += 10000; carry = 1;}
            else {carry = 0;}
            ret.digit[ ret.size++ ] = tmp;
        }
        return ret;
    }
}a, b, c;

char str1[1002], str2[1002];

int main(int argc, const char * argv[]) {
    while (cin >> str1 >> str2) {
        a.set(str1); b.set(str2);
        c = a - b; //输入必须a > b
        c.output();
        c = a + b;
        c.output();
    }
    return 0;
}
