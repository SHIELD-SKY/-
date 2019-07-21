//
//  main.cpp
//  计算反序数
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/OpenJ_Bailian-2885

#include <iostream>
using namespace std;

int reverse(int num)
{
    int tmp = num;
    int ans = 0;
    while (tmp) {
        ans = ans * 10 + tmp % 10;
        tmp /= 10;
    }
    return ans;
}

int main(int argc, const char * argv[]) {
  
    int i = 0;
    while(cin>>i)
    {
        if(i >= 0){cout << reverse(i) << endl;}
        else if(i < 0){ cout << '-' << reverse(-i) << endl; }
    }
    return 0;
}
