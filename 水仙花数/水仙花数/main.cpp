//
//  main.cpp
//  水仙花数
//
//  Created by APTX on 31/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int  table[10];
    int cnt = 0;
    for(int a = 1; a < 10; a++){
        for(int b = 0; b < 10; b++){
            for(int c = 0; c < 10; c++)
            {
                int x = a * 100 + b * 10 + c;
                if (x == a*a*a + b*b*b + c*c*c)
                    table[cnt++] = x;
            }
        }
    }
    
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        int flag = 0;
        for(int i = 0; i < cnt; i++)
        {
            if(n <= table[i] && table[i] <= m)
            {
                if(flag) printf(" ");
                flag = 1;
                printf("%d",table[i]);
            }
        }
        if(!flag) printf("no");
        printf("\n");
    }
    return 0;
}
