//
//  main.cpp
//  不容易系列之一
//
//  Created by APTX on 1/3/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
long long F[21];

int main(int argc, const char * argv[]) {
    F[1] = 0;
    F[2] = 1;
    for(int i = 3; i <= 20; i++){
        F[i] = (i-1)*F[i-1] + (i-1)*F[i-2];
    }
    int n;
    while (cin >> n) {
        printf("%lld\n", F[n]);
    }
    return 0;
}
