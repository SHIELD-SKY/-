//
//  main.cpp
//  胜利大逃亡
//
//  Created by APTX on 27/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//BFS
//https://vjudge.net/problem/HDU-1253

#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
bool mark[50][50][50];
int maze[50][50][50];
struct N {
    int x, y, z;
    int t;
};
queue<N> Q;
int go[][3]={
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, 1,
    0, 0, -1
};
int BFS(int a, int b, int c){
    while (Q.empty() == false) {
        N now = Q.front();
        Q.pop();
        for(int i = 0; i < 6; i++){
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            int nz = now.z + go[i][2];
            if(nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c) continue;
            if(maze[nx][ny][nz] == 1) continue;
            if(mark[nx][ny][nz] == true) continue;
            
            N tmp;
            tmp.x = nx;
            tmp.y = ny;
            tmp.z = nz;
            tmp.t = now.t + 1;
            Q.push(tmp);
            mark[nx][ny][nz] = true;
            if(nx == a-1 && ny == b-1 && nz == c-1) return tmp.t;
        }
    }
    return -1;
}
int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                for(int k = 0; k < c; k++){
                    cin >> maze[i][j][k];
                    mark[i][j][k] = false;
                }
            }
        }
        while (Q.empty() == false) {
            Q.pop();//清空队列
        }
        mark[0][0][0] = true;
        N tmp;
        tmp.t = tmp.x = tmp.y = tmp.z = 0;
        Q.push(tmp);
        int rec = BFS(a, b, c);
        if(rec <= t) cout << rec << endl;
        else cout << -1 << endl;
    }
    return 0;
}
