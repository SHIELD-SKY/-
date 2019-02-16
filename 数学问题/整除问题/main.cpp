//
//  main.cpp
//  整除问题
//
//  Created by APTX on 15/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//2011 年上海交通大学计算机研究生机试真题

#include <iostream>
#include <cstring>
using namespace std;

bool mark[1010];
int prime[1010];
int primeSize;

void init(){
    primeSize = 0;
    for(int i = 2; i <= 1000; i++){
        if(mark[i]) continue;
        //mark[i] = true;
        prime[ primeSize++ ] = i;
        for(int j = i * i; j <= 1000; j += i){
            mark[j] = true;
        }
    }
}

int cnt[1010];//cnt[i]用来表示,prime[i]所保存的素数在n!中的因子数,即n!分解素因数后,素因子prime[i]所对应的幂指数，可能为0
int cnt2[1010];//cnt2[i]用来表示,prime[i]所保存的素数在a中的因子数

int main(int argc, const char * argv[]) {
    int n,a;
    init();
    while (cin >> n >> a) {
        for(int i = 0; i < primeSize; i++){
            cnt[i] = cnt2[i] = 0;
        }
        
        for(int i = 0; i < primeSize; i++){ //对n!分解素因数,遍历每一个0到1000 的素数!!!!!!!!!!!!!!!!!!!!!!!!!!
            int t = n;//用临时变量t保存n的值
            while (t) { //确定素数prime[i]在n中的因子数
                cnt[i] += t / prime[i];
                t = t / prime[i];
            }//依次计算t / prime[i]^k,累加其值,直到t / prime[i]^k变为0
        }
        
        int ans = 123123123;//答案初始值为一个大整数,为取最小值做准备
        
        for(int i = 0; i < primeSize; i++){
            while (a % prime[i] == 0) {
                cnt2[i]++;
                a /= prime[i];
            }//计算a中素因数prime[i]对应的幂指数
            
            if(cnt2[i] == 0) continue;//若该素数不能从a中分解到,即其对应幂指数为0,则其不影响整除性,跳过
            if(cnt[i] / cnt2[i] < ans){ //计算素数prime[i]在两个数中因子数的商
                ans = cnt[i] / cnt2[i];//统计这些商的最小值
            }
        }
        cout << ans << endl;
    }
    return 0;
}
