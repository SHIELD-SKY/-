//
//  main.cpp
//  统计同成绩学生人数
//
//  Created by APTX on 22/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//
//https://vjudge.net/problem/HDU-1235

#include <iostream>

#include <cstring>


using namespace std;

//int score[100+5];

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n && n != 0) {
        int score[100+5] = {0};
        //memset(score, 0, sizeof(score));
        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            score[tmp]++;
        }
        int num;
        cin >> num;
        cout << score[num] << endl;
    }
    return 0;
}
