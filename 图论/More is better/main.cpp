//
//  main.cpp
//  More is better
//
//  Created by APTX on 23/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
#define N 10000001
int Tree[N];
int findRoot(int x){
    if(Tree[x] == -1) return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int sum[N];

int main(int argc, const char * argv[]) {
    int n;
    while (scanf("%d", &n) != EOF) {
        for(int i = 1; i < N; i++){
            Tree[i] = -1;
            sum[i] = 1;
        }
        while (n--) {
            int a, b;
            scanf("%d%d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b){
                Tree[a] = b;
                sum[b] += sum[a];
            }
        }
        int ans = 1;
        for(int i =1 ; i <= N; i++){
            if(Tree[i] == -1 && sum[i] > ans) ans = sum[i];
        }
        cout << ans << endl;
    }
    
    return 0;
}
