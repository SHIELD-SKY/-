//
//  main.cpp
//  谁是你的潜在朋友
//
//  Created by APTX on 22/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int n, m;
    
    while (cin >> n >> m) {
    
        int human[200+10] = {0};
        int book[200 + 10] = {0};
        
        for(int i = 1; i <= n; i++)
        {
            cin >> human[i];
            book[human[i]]++;
        }
        
        for(int i = 1; i < n; i++)
        {
            if(book[human[i]] > 1)
            {
                cout << book[human[i]] - 1 << endl;
            }
            else cout << "BeiJu" << endl;
        }
        
        if(book[human[n]] > 1) //处理最后一个，不输出回车
        {
            cout << book[human[n]] - 1;
        }
        else cout << "BeiJu";
    }
    return 0;
}
