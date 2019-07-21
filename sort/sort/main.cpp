//
//  main.cpp
//  sort
//
//  Created by APTX on 22/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//
//给你 n 个整数，请按从大到小的顺序输出其中前 m 大的数。
// 每组测试数据有两行，第一行有两个数 n,m(0<n,m<1000000)，第二行包含 n 个各不相同，且都处于区间[-500000,500000]的整数。
//对每组测试数据按从大到小的顺序输出前 m 大的数。

#include <iostream>
#include <cstdio>

using namespace std;

#define OFFSET 500000

int Hash[10000010];


int main(int argc, const char * argv[]) {
    int n, m;
    while (cin >> n >>m) {
        
        Hash[10000001] = {0};
        
        for (int i = 1; i<= n; i++) {
            int x;
            cin >> x;
            Hash[x + OFFSET] = 1;
        }
        
        for(int i = 500000; i >= -500000; i--)
        {
            if(Hash[i + OFFSET] == 1){
                cout << i;
                m--;
                if(m != 0) cout << " ";
                else {
                    cout << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
