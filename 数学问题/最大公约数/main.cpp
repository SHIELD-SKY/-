//
//  main.cpp
//  最大公约数
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main(int argc, const char * argv[]) {
    int a, b;
    while (cin >> a >> b) {
        cout << gcd(a, b) << endl;
    }
    return 0;
}
