//
//  main.cpp
//  还是畅通工程
//
//  Created by APTX on 23/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-1233
//MST

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace  std;
#define N 101

int Tree[N];

int findRoot(int x){
    if(Tree[x] == -1) return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

struct Edge{
    int a, b;
    int cost;
    bool operator < (const Edge &A) const{
        return cost < A.cost;
    }
}edge[6000];

int main(int argc, const char * argv[]) {
    int n;
    while ((cin >> n) && (n != 0)) {
        for(int i = 1; i <= n*(n-1)/2; i++){
            cin >> edge[i].a >> edge[i].b >> edge[i].cost;
        }
        sort(edge+1, edge+1+n*(n-1)/2);
        for(int i = 1; i <= n; i++){
            Tree[i] = -1;
        }
        int ans = 0;
        for(int i = 1; i <= n*(n-1)/2; i++){
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if(a != b){    //若属于不同集合，则选该边
                Tree[a] = b; //合并边
                ans += edge[i].cost; //累加权值
            }
        }
        cout << ans << endl;
    }
    return 0;
}
