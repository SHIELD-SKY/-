//
//  main.cpp
//  采药
//
//  Created by APTX on 2/3/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/OpenJ_Bailian-2773
//
//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//using namespace std;
//#define INF 0x7fffffff
//struct E{
//    int w;
//    int v;
//}list[101];
//int dp[101][1001];
//
//int main(int argc, const char * argv[]) {
//    int s, n;
//    while (scanf("%d%d", &s, &n) != EOF) {
//        for(int i = 1; i <= n; i++){
//            scanf("%d%d", &list[i].w, &list[i].v);
//        }
//        for(int i = 0; i <= s; i++){
//            dp[0][i] = 0;
//        }
//        for(int i = 1; i <= n; i++){
//            for(int j = s; j >= list[i].w; j--){
//                dp[i][j] = max(dp[i-1][j], dp[i-1][j-list[i].w]+list[i].v);
//            }
//            for(int j = list[i].w-1; j >= 0; j--)
//                dp[i][j] = dp[i-1][j];
//        }
//        printf("%d\n", dp[n][s]);
//    }
//    return 0;
//}

#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 0x7fffffff

struct E {
    int w;
    int v;
}list[101];

int dp[1001];
int main(){
    int s, n;
    while (scanf("%d%d", &s, &n) != EOF) {
        for(int i = 1; i <= n; i++){
            scanf("%d%d", &list[i].w, &list[i].v);
        }
        for(int i = 0; i <= s; i++){
            dp[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = s; j >= list[i].w; j--){
                dp[j] = max(dp[j], dp[j-list[i].w] + list[i].v);
            }
        }
        printf("%d\n", dp[s]);
    }
    return 0;
}
