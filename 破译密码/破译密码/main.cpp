//
//  main.cpp
//  破译密码
//
//  Created by APTX on 8/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/POJ-3749

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 200 + 10;
char s[maxn];

int main(int argc, const char * argv[]) {
    while (gets(s) && strcmp(s, "START") == 0) {
        gets(s);
        int len = strlen(s);
        for(int i = 0; i < len; i++)
        {
            if('A' <= s[i] && s[i] <= 'Z'){
                if(s[i] >= 'F'){
                    printf("%c", s[i]-5);
                }else{
                    printf("%c", s[i]+26-5);
                }
            }else{
                printf("%c", s[i]);
            }
        }
        printf("\n");
        gets(s);
    }
    return 0;
}
