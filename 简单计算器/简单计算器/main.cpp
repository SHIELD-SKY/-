//
//  main.cpp
//  简单计算器
//
//  Created by APTX on 13/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

char str[220];  //保存表达式字符串
int mat[][5] = { //优先级矩阵,若mat[i][j] == 1，则表示i号运算符优先级大于j号运算符，运算符编码规则为+为1号，-为2号，*为3号，/为4号,我们人为添加在表达式首尾的标记 运算符为0号
    1,0,0,0,0,
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0,
};
stack<int> op;    //运算符栈,保存运算符编号
stack<double> in;   //数字栈,运算结果可能存在浮点数,所以保存元素为double

void getOp(bool &reto, int &retn, int &i){   //获得表达式中下一个元素函数,若函数运行结束时,引用变量reto为true,则表示该元素为一个运算符,其编号保存在引用变量retn中; 否则，表示该元素为一个数字，其值保存在引用变量retn中.引用变量i表示遍历到的字符串下标
    if(i == 0 && op.empty() == true){  //若此时遍历字符串第一个字符,且运算符栈 为空,我们人为添加编号为0的标记字符
        reto = true;
        retn = 0;
        return;
    }
    if(str[i] == 0)
    {
        reto = true;
        retn = 0;
        return;
    }
    if(str[i] >= '0' && str[i] <= '9'){
        reto = false;
    }
    else{
        reto = true;
        if(str[i] == '+'){
            retn = 1;
        }
        else if(str[i] == '-'){
            retn = 2;
        }
        else if(str[i] == '*'){
            retn = 3;
        }
        else if(str[i] == '/'){
            retn = 4;
        }
        i += 2; //i递增,跳过该运算字符和该运算字符后的空格
        return;
    }
    retn = 0;
    for(;str[i] != ' ' && str[i] != 0; i++)//若字符串未被遍历完,且下一个字 符不是空格,则依次遍历其后数字,计算当前连续数字字符表示的数值
    {
        retn *= 10;
        retn += str[i] - '0';
    }
    if(str[i] == ' ')  //若其后字符为空格,则表示字符串未被遍历完
        i++;   //i递增.跳过该空格
    
    return;
    
}

int main(int argc, const char * argv[]) {
    while (gets(str)) {
        if(str[0] == '0' && str[1] == 0) break;
        bool retop;
        int retnum;
        int idx = 0;
        while(!op.empty()) op.pop();
        while(!in.empty()) in.pop();
        while (true) {
            getOp(retop, retnum, idx);
            if(retop == false){
                in.push((double)retnum);
            }
            else{
                double tmp;
                if(op.empty() == true || mat[retnum][op.top()] == 1) {   //若运算符堆栈为空或者当前遍历到的运算符优先级大于栈顶运算符,将该运算符压入运算符堆栈
                    op.push(retnum);
                }
                else {
                    while (mat[retnum][op.top()] == 0) {//只要当前运算符优先级 小于栈顶元素运算符,则重复循环
                        int ret = op.top();
                        op.pop();
                        double b = in.top();
                        in.pop();
                        double a = in.top();
                        in.pop();
                        if(ret == 1) tmp = a + b;
                        else if( ret == 2) tmp = a - b;
                        else if(ret == 3) tmp = a * b;
                        else tmp = a / b;
                        in.push(tmp);
                    }
                    op.push(retnum);
                }
            }
            if(op.size() == 2 && op.top() == 0) break;
        }
        printf("%0.2lf\n", in.top());
    }
    return 0;
}
