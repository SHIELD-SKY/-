//
//  main.cpp
//  打印极值点下标
//
//  Created by APTX on 2/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//
//https://vjudge.net/problem/OpenJ_Bailian-2691

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int buf[85];

int main(int argc, const char * argv[]) {
    int n, m;
    cin >> n;
    while (n--) {
        memset(buf, 0.5, sizeof(buf));
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin  >> buf[i];
        }
        
        for(int i = 0; i < m; i++)
        {
            if(i == 0) {
                if(buf[i] != buf[1]){
//                    if(m > 1) cout << 0 << " " ;      //这地方想细了， 反而Presentation Error
//                    else cout << 0;
                    cout << 0 << " ";
                }
            }
            else if((i == m-1) && buf[i] != buf[i-1]) {cout << m-1;}
            else if((buf[i] < buf[i-1] && buf[i] < buf[i+1]) || (buf[i] > buf[i-1] && buf[i] > buf[i+1]))
            {
                cout << i << " ";
            }
        }
        //if(n>1) {cout << endl;} //同上
        cout << endl;
    }
    return 0;
}

/*
3
10
10 12 12 11 11 12 23 24 12 12
15
12 12 122 112 222 211 222 221 76 36 31 234 256 76 76
15
12 14 122 112 222 222 222 221 76 36 31 234 256 76 73
*/
