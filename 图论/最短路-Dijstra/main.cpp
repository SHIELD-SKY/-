//
//  main.cpp
//  最短路-Dijstra
//
//  Created by APTX on 25/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-2544


#include <iostream>
#include <vector>
using namespace std;
struct E {
    int next;
    int c;
};
vector<E> edge[101];       //邻接表
bool mark[101];         //标记,当mark[j]为true时表示结点j的最短路径长度已经得到,该结点已经加入集合K
int Dis[101];       //距离向量,当mark[i]为true时,表示已得的最短路径长度;否则,表示所有从结点1出发，经过已知的最短路径达到集合K中的某结点，再经过一条边到达结点i的路径中最短的距离


int main(int argc, const char * argv[]) {
    int n, m;
    while (cin >> n >> m && n && m) {
        for(int i = 1; i <= n; i++) edge[i].clear();
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            E tmp;
            tmp.c = c;
            tmp.next = b;
            edge[a].push_back(tmp);
            tmp.next = a;
            edge[b].push_back(tmp);     //将邻接信息加入邻接链表,由于原图为无向图,固每条边信息都要添加到其两个顶点的两条单链表中
        }
        for(int i = 1; i <= n; i++){        //初始化
            Dis[i] = -1;                        //所有距离为-1，即不可达
            mark[i] = false;                //所有结点不属于集合K
        }
        Dis[1] = 0;         //得到最近的点为结点1,长度为0
        mark[1] = true;         //将结点1加入集合K
        int newP = 1;       //集合K中新加入的点为结点1
        for(int i = 1; i < n; i++){
            for(int j = 0; j < edge[newP].size(); j++){
                int t = edge[newP][j].next;
                int c = edge[newP][j].c;
                if(mark[t] == true) continue;
                if(Dis[t] == -1 || Dis[t] > Dis[newP]+c)
                    Dis[t] = Dis[newP]+c;
            }
            int min = 123123123;
            for(int j = 1; j <= n; j++){
                if(mark[j] == true) continue;
                if(Dis[j] == -1) continue;
                if(Dis[j] < min){
                    min = Dis[j];
                    newP = j;
                }
            }
            mark[newP] = true;
        }
        cout << Dis[n] << endl;
    }
    return 0;
}
