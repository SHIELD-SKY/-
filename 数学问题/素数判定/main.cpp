//
//  main.cpp
//  素数判定
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool judge(int x){
    if(x <= 1) return false;
    int bound = (int)sqrt(x) + 1;
    for(int i = 2; i < bound; i++){
        if(x % i == 0) return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    int x;
    while (cin >> x) {
        puts(judge(x)? "yes" : "no");
    }
    return 0;
}
