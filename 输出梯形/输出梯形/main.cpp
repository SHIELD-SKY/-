//
//  main.cpp
//  输出梯形
//
//  Created by APTX on 22/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int h;
    while (cin >> h) {
        int maxLine = h + (h - 1) * 2;
        for(int i = 1; i <= h; i++){
            
            for(int j = 1; j <= maxLine; j++){
                
                if(j < maxLine - (h + (i-1) * 2) + 1)
                    cout << " ";
                else
                    cout << "*";
            }
            cout << endl;
        }
    }
    return 0;
}
