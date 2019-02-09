//
//  main.cpp
//  字符串处理-文本规范化
//
//  Created by APTX on 7/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://blog.csdn.net/kobebryantlin0/article/details/54919692

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long  ll;
const int maxn = 100 + 10;
char s[maxn];

int main(int argc, const char * argv[]) {
    while (scanf("%s", s) == 1) {
        int  len = strlen(s);
        int j = 0;
        for(int i = 0; i < len; i++)
        {
            if(s[i] != '#' || (i-1>=0 && s[i-1]!='#')){
                s[j++] = s[i];
            }
        }
        if(s[j-1] == '#') j--;
        s[j] = '\0';
        printf("%s\n", s);
        
    }
    return 0;
}
