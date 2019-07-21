//
//  main.cpp
//  Stucked Keyboard
//
//  Created by APTX on 8/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//http://www.dengdengoj.cc/problem.php?id=1063

#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000+10;
char s[maxn];
int cnt[256];  //cnt[i]保存i(ASCILL码）出现的连续次数
int ok[256];    //ok[i] == 1表示i 是个好的字符
int printed[256];  //printed[i]表示i已经被作为坏字符输出

int main(int argc, const char * argv[]) {
    int k;
    while (scanf("%d%s", &k, s) == 2) {
        memset(ok, 0, sizeof(ok));
        memset(cnt, 0, sizeof(cnt));
        memset(printed, 0, sizeof(printed));
        
        int len = strlen(s);
        for(int i = 0; i < len; i++){
            cnt[s[i]]++;
            if(i+1 < len && s[i]!=s[i+1]){
                if(cnt[s[i]]%k != 0){
                    ok[s[i]] = 1;
                }
                cnt[s[i]] = 0;
            }
        }
        if(cnt[s[len-1]]%k!=0) ok[s[len-1]] = 1;
        
        for(int i = 0; i < len; i++){
            if(ok[s[i]] == 0 && printed[s[i]] == 0){
                printf("%c", s[i]);
                printed[s[i]] = 1;
            }
        }
        printf("\n");
        for(int i = 0; i < len; i++)
        {
            printf("%c", s[i]);
            if(ok[s[i]] == 0) i += k-1; //坏的字符每k个只输出一次，因为前面的输出过一次，剩下的k-1个跳过
        }
        printf("\n");
    }
    return 0;
}
