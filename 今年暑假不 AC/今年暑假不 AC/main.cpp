//
//  main.cpp
//  今年暑假不 AC
//
//  Created by APTX on 5/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-2037
//贪心

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct program{
    int startTime;
    int endTime;
    bool operator < (const program &A) const{
        return endTime < A.endTime;
    }
} buf[100];

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n &&n != 0) {
        for(int i = 0; i < n; i++)
        {
            cin >> buf[i].startTime >> buf[i].endTime;
        }
        
        sort(buf, buf + n);
        int currentTime = 0, ans = 0;
        
        for(int i = 0; i < n; i++){
            if (currentTime <= buf[i].startTime) {
                currentTime = buf[i].endTime;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
