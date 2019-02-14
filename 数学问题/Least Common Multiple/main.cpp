//
//  main.cpp
//  Least Common Multiple
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b == 0? a : gcd(b, a%b);
}

int main(int argc, const char * argv[]) {
    int x, n;
    while (cin >> n) {
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            ans = ans  / gcd(ans, x) * x;
        }
        cout << ans << endl;
    }
    return 0;
}
