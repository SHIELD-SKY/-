//
//  main.cpp
//  图论
//
//  Created by APTX on 22/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-1232
//并查集

#include <iostream>
#include <cstdio>
using namespace std;
#define N 1000

int Tree[N];

int findRoot(int x){
    if(Tree[x] == -1) return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(int argc, const char * argv[]) {
    int  n, m;
    while (cin >> n && n) {
        cin >> m;
        for(int i = 1; i <= n; i++) Tree[i] = -1;
        while (m--) {
            int a, b;
            cin >> a >> b;
            a = findRoot(a);
            b = findRoot(b);
            if(a != b) Tree[a] = b;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(Tree[i] == -1) ans++;
        }
        cout << ans-1 << endl;
    }
    return 0;
}
