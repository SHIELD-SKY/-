//
//  main.cpp
//  非常可乐
//
//  Created by APTX on 28/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-1495
//BFS

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

struct N{
    int a, b, c;
    int t;
};
queue<N> Q;
bool mark[101][101][101];

void AtoB(int &a, int sa, int &b, int sb){
    if(sb-b >= a){
        b += a;
        a = 0;
    }
    else{
        a -= sb-b;
        b = sb;
    }
}

int BFS(int s, int n, int m){
    while (Q.empty() == false) {
        N now = Q.front();
        Q.pop();
        int a, b, c;
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(a, s, b, n);
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;
            
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(b, n, a, s);
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t+1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(a, s, c, m);
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(c, m, a, s);
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(b == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(b, n, c, m);
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return tmp.t;
            Q.push(tmp);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        AtoB(c, m, b, n);
        if(mark[a][b][c] == false){
            mark[a][b][c] = true;
            N tmp;
            tmp.a = a;
            tmp.b = b;
            tmp.c = c;
            tmp.t = now.t + 1;
            if(a == s/2 && b == s/2) return tmp.t;
            if(c == s/2 && b == s/2) return tmp.t;
            if(a == s/2 && c == s/2) return  tmp.t;
            Q.push(tmp);
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int s, n, m;
    while (cin >> s >> n >> m) {
        if(s == 0) break;
        if(s % 2 == 1){
            puts("NO");
            continue;
        }
        for(int i = 0; i <= s; i++){
            for(int j = 0; j <= n; j++){
                for(int k = 0; k <= m; k++){
                    mark[i][j][k] = false;
                }
            }
        }
        N tmp;
        tmp.a = s;
        tmp.b = 0;
        tmp.c = 0;
        tmp.t = 0;
        while (Q.empty() == false) {
            Q.pop();
        }
        Q.push(tmp);
        mark[s][0][0] = true;
        int rec = BFS(s, n, m);
        if(rec == -1)
            puts("NO");
        else printf("%d\n", rec);
    }
    return 0;
}
