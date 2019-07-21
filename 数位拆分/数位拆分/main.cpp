//
//  main.cpp
//  数位拆分-数字
//
//  Created by APTX on 9/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1000 + 10;
char s[maxn]; //用字符数组接受“大数字”
int cnt[10]; //cnt[i]保存数字i出现的次数

int main(int argc, const char * argv[]) {
    while (scanf("%s", s) == 1) {
        int len = strlen(s);
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < len; i++){
            cnt[s[i]-'0']++;
        }
        int max = 0, ans;
        for(int i = 0; i < 10; i++){
            if(cnt[i] > max){
                max = cnt[i];
                ans = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
