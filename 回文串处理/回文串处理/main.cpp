//
//  main.cpp
//  回文串处理
//
//  Created by APTX on 7/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
using namespace std;
typedef long long  ll;
const int maxn = 5000 +10;
char s[maxn];

int main(int argc, const char * argv[]) {
    while (scanf("%s", s) == 1) {
        int len = strlen(s);
        int ans = 0;
        //思路一：枚举所有子串，判断该子串是否为回文串，时间复杂度o(n^3)
//        for(int i  = 0; i < len; i++){
//            for(int j = i; j < len; j++){
//                int ok = 1;
//                for(int p = i, q = j; p <= q; p++, q--){
//                    if(s[p] != s[q]){
//                        ok = 0;
//                        break;
//                    }
//                }
//             if(ok) ans++;
//            }
//        }
        //思路二： 利用子串之间的依赖关系，枚举所有串的中心点，从中心点往两端扩展，来判断更长的子串是否为回文串
        for(int i = 0; i  < len; i++){
            int num = 0;
            while(i-num >= 0 && i+num <= len && s[i+num] == s[i-num]) num++;
            ans += num;
            num = 0;
            while(i-num >= 0 && i+1+num <= len && s[i-num] == s[i+1+num]) num++;
            ans+=num;
        }
        printf("%d\n", ans);
    }
    return 0;
}
