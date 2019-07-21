//
//  main.cpp
//  找x
//
//  Created by APTX on 2/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//2010 年哈尔滨工业大学计算机研究生机试真题

#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, const char * argv[]) {
    int buf[200];
    int n;
    while (cin >> n) {
        for(int i = 0; i < n; i++)
        {
            cin >> buf[i];
        }
        
        int x, ans = -1;  //初始化小技巧，找不到的答案 用来初始化
        cin >> x;
        for (int i = 0; i < n; i++) {
            if(x == buf[i]){
                ans = i;
                break;
            }
        }
        cout << ans;
    }
    return 0;
}
