//
//  main.cpp
//  素数
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
using namespace std;

int prime[10000];
int primeSize;
bool mark[10001];

void init(){
    for(int i = 1; i <= 10000; i++){
        mark[i] = false;
    }
    primeSize = 0;
    
    for(int i = 2; i <= 10000; i++){
        if(mark[i] == true) continue;
        prime[primeSize++] = i;
        for(int j = i * i; j <= 10000; j += i){
            mark[j] = true;
        }
    }
}



int main(int argc, const char * argv[]) {
    init();
    int n;
    while(cin >> n){
        bool isOutput = false;
        for(int i = 0; i < primeSize; i++){
            if(prime[i] < n && prime[i] % 10 == 1){
                if(isOutput == false){
                    isOutput = true;
                    cout << prime[i];
                }
                else cout << " " << prime[i];
            }
        }
        if(isOutput == false) {
            cout << "-1\n";
        }
        else cout << "\n";
    }
    return 0;
}
