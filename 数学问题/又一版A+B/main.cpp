//
//  main.cpp
//  又一版A+B
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-1877

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    long long a, b;
    int m;
    while (cin >> m && m) {
        cin >> a >> b;
        a = a + b;
        int ans[50], size = 0;
        do{
            ans[size++] = a % m;
            a /= m;
        }while(a != 0);
        
        for(int i = size - 1; i >= 0; i--){
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
