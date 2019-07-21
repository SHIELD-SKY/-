//
//  main.cpp
//  质因数的个数
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//2007 年清华大学计算机研究生机试真题

#include <iostream>
using namespace std;

bool mark[100001];
int prime[100001];
int primeSize;

void init(){
    
    for(int i = 1; i <= 10000; i++){
        mark[i] = false;
    }
    
    primeSize = 0;
    
    for(int i = 2; i <= 100000; i++){
        if(mark[i] == true) continue;
        prime[primeSize++] = i;
        if(i >= 1000 ) continue; //i == 46349时，  j = i*i溢出，为避免进入下边for循环。。
        for(int j = i * i; j <= 100000; j += i){
            mark[j] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    init();
    int n;
    while(cin >> n){
        int ansPrime[30];//按顺序保存分解出的素因数
        int ansSize = 0;//分解出素因数的个数
        int ansNum[30];//保存分解出的素因数对应的幂指数
        
        for(int i = 0; i < primeSize; i++){
            if(n % prime[i] == 0){
                ansPrime[ansSize] = prime[i];
                ansNum[ansSize] = 0;
                while(n % prime[i] == 0){
                    ansNum[ansSize]++;
                    n /= prime[i];
                }
                ansSize++;
                if(n == 1) break; //若已被分解成1,则分解提前终止
            }
        }
        
        if(n != 1){  //若测试完2到100000内所有素因数,n仍未被分解至1,则剩余的因数 一定是n一个大于100000的素因数
            ansPrime[ansSize] = n;//记录该大素因数
            ansNum[ansSize++] = 1;//其幂指数只能为1
        }
        int ans = 0;
        for(int i = 0; i < ansSize; i++){
            ans += ansNum[i];
        }
        cout << ans << endl;
    }
    return 0;
}
