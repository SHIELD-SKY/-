//
//  main.cpp
//  FatMouse' Trade
//
//  Created by APTX on 3/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//贪心思想
//https://vjudge.net/problem/HDU-1009

#include <iostream>
#include  <cstdio>
#include <algorithm>
using namespace std;

struct goods {
    double j;
    double f;
    double s;
    bool operator< (const goods &A) const{
        return s > A.s;
    }
}buf[1005];

int main(int argc, const char * argv[]) {
    double m;
    int n;
    while (scanf("%lf%d", &m, &n) != EOF) {
        
        if(m == -1 && n == -1) break;
        for(int i = 0; i < n; i++)
        {
            scanf("%lf%lf", &buf[i].j, &buf[i].f);
            buf[i].s = buf[i].j / buf[i].f;
        }
        sort(buf, buf+n);
        int idx = 0;
        double ans = 0;
        while (m > 0 && idx < n) {
            if(m > buf[idx].f)
            {
                ans += buf[idx].j;
                m -= buf[idx].f;
            }
            else{
                ans += buf[idx].j * m / buf[idx].f;
                m = 0;
            }
            idx++;
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}
