//
//  main.cpp
//  最短路径问题
//
//  Created by APTX on 25/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-3790
//此题有坑，重边！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <vector>
//using namespace std;
//struct E{
//    int next;
//    int c;
//    int cost;
//};
//vector<E> edge[1001];
//int Dis[1001];
//int cost[1001];
//bool mark[1001];
//
//int main(int argc, const char * argv[]) {
//    int n, m;
//    int S, T;
//    while (scanf("%d%d",&n,&m)!=EOF) {
//        if(n == 0 && m == 0) break;
//        for(int i = 1; i <= n; i++) edge[i].clear();
//        while (m--) {
//            int a, b, c, cost;
//           // cin >> a >> b >> c >> cost;
//            scanf("%d%d%d%d", &a, &b, &c, &cost);
//            if( c < edge[a][b].c){
//                E tmp;
//                tmp.c = c;
//                tmp.cost = cost;
//                tmp.next = b;
//                edge[a].push_back(tmp);
//                tmp.next = a;
//                edge[b].push_back(tmp);
//            }
//            else if(c == edge[a][b].c)
//            {
//                if(cost < edge[a][b].cost){
//                    E tmp;
//                    tmp.c = c;
//                    tmp.cost = cost;
//                    tmp.next = b;
//                    edge[a].push_back(tmp);
//                    tmp.next = a;
//                    edge[b].push_back(tmp);
//                }
//            }
//        }
//        //cin >> S >> T;
//        scanf("%d%d", &S, &T);
//        for(int i = 1; i <= n; i++){
//            Dis[i] = -1;
//            mark[i] = false;
//        }
//        Dis[S] = 0;
//        mark[S] = true;
//        int newP = S;
//        for(int i = 1; i < n; i++){
//            for(int j = 0; j < edge[newP].size(); j++){
//                int t = edge[newP][j].next;
//                int c = edge[newP][j].c;
//                int co = edge[newP][j].cost;
//                if(mark[t] == true) continue;
//                if(Dis[t] == -1 || Dis[t] > Dis[newP]+c || (Dis[t] == Dis[newP]+c && cost[t] > cost[newP]+co)){//比较大小时,将距离相同但花费更短也作为更新 的条件之一
//                    Dis[t] = Dis[newP]+c;
//                    cost[t] = cost[newP]+co;
//                }
//            }
//            int min = 123123123;
//            for(int j = 1; j <= n; j++){//选择最小值,选择时不用考虑花费的因素,因为距离最近的点的花费已经不可能由于经过其它点而发生改变了
//                if(mark[j] == true) continue;
//                if(Dis[j] == -1) continue;
//                if(Dis[j] < min){
//                    min = Dis[j];
//                    newP = j;
//                }
//            }
//            mark[newP] = true;
//        }
//        printf("%d %d\n", Dis[T], cost[T]);
//    }
//    return 0;
//}

//
//#include <cstdio>
//#include <vector>
//using namespace std;
//
//struct E{
//    int next;
//    int c;
//    int cost;
//};
//vector<E> edge[1001];
//int Dis[1001];
//int cost[1001];
//bool mark[1001];
//int main(){
//    int n, m;
//    int S, T;
//    while (scanf("%d%d", &n, &m) != EOF) {
//        if(n == 0 && m == 0) break;
//        for(int i = 1; i <= n; i++) edge[i].clear();
//        while (m--) {
//            int a, b, c, cost;
//            scanf("%d%d%d%d", &a, &b, &c, &cost);
//            E tmp;
//            tmp.c = c;
//            tmp.cost = cost;
//            tmp.next = b;
//            edge[a].push_back(tmp);
//            tmp.next = a;
//            edge[b].push_back(tmp);
//        }
//        scanf("%d%d", &S, &T);
//        for(int i = 1; i <= n; i++){
//            Dis[i] = -1;
//            mark[i] = false;
//        }
//        Dis[S] = 0;
//        mark[S] = true;
//        int newP = S;
//        for(int i = 1; i < n; i++){
//            for(int j = 0; j < edge[i].size(); j++){
//                int t = edge[newP][j].next;
//                int c = edge[newP][j].c;
//                int co = edge[newP][j].cost;
//                if(mark[t] == true) continue;
//                if(Dis[t] == -1 || Dis[t] > Dis[newP]+c || (Dis[t] == Dis[t]+c && cost[t] > cost[newP]+co)){
//                    Dis[t] = Dis[newP] + c;
//                    cost[t] = cost[newP] + co;
//                }
//            }
//           int min = 123123123;
//           for(int j = 1; j <= n; j++){
//               if(mark[j] == true) continue;
//               if(Dis[j] == -1) continue;
//               if(Dis[j] < min){
//                   min = Dis[j];
//                   newP = j;
//               }
//           }
//            mark[newP] = true;
//        }
//        printf("%d %d\n", Dis[T], cost[T]);
//    }
//    return 0;
//}

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#define INF 0x3f
using namespace std;
int map[1001][1001];
int cost[1001][1001];
int fee[1001];
int Dis[1001];
int mark[1001];
int S, T;
int n, m;
//int test[10];
void Dijstra(int S){
    Dis[S] = 0;
    fee[S] = 0;
    while (true) {
        int v = -1;
        for(int i = 1; i <= n; i++){
            if(!mark[i] && ((v == -1) || Dis[i] < Dis[v])) {
                v = i;
            }
        }
        if(v == -1) break;
        mark[v] = 1;
        for (int i = 1; i <= n; i++) {
            if(i == v) continue;
            if(Dis[i] > Dis[v] + map[v][i]){
                Dis[i] =  Dis[v] + map[v][i];
                fee[i] = fee[v] + cost[v][i];
            }
            if(Dis[i] == Dis[v] + map[v][i] && fee[i] > fee[v] + cost[v][i]){
                fee[i] = fee[v] + cost[v][i];
            }
        }
    }
}

int main(){

 //   memset(test, 0, sizeof(test)); //memset是按字节填充
    
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == 0 || m == 0) break;
        memset(map, INF, sizeof(map));
        memset(Dis, INF, sizeof(Dis));
        memset(mark, 0, sizeof(mark));
        memset(cost, INF, sizeof(cost));
        memset(fee, INF, sizeof(fee));
        while (m--) {
            int a, b, len, co;
            scanf("%d%d%d%d", &a, &b, &len, &co);
            if(len < map[a][b]){
                map[a][b] = map[b][a] = len;
                cost[a][b] = cost[b][a] = co;
            }
            else if(len == map[a][b] && co < cost[a][b]){
                cost[a][b] = cost[b][a] = co;
            }
        }
        scanf("%d%d", &S, &T);
        Dijstra(S);
        printf("%d %d\n", Dis[T], fee[T]);
    
    }
//    for(int i = 0; i < 10; i++){
//        cout << map[i][i] << endl;
//    }
    return 0;
    
}
