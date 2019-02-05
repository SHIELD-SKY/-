//
//  main.cpp
//  迷瘴
//
//  Created by APTX on 5/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-2570
//贪心

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 105;

int c, n, v, w;
int buf[maxn];

int main(int argc, const char * argv[]) {
    cin >> c;
    while (c--) {
        cin >> n >> v >> w;
        for(int i = 0; i < n; ++i)
        {
            cin >> buf[i];
        }
        sort(buf, buf+n);
        int result = 0;
        double density = 0;
        int num = 0;
        for(int i = 0; i < n; ++i)
        {
            if(buf[0] > w) {cout << "0 0.00\n";break;}

            result += buf[i];
            num++;
            density = result*1.0 / num;  //1.0 十分重要！！！！！


            if(density <= w && i == n-1) {
                printf("%d %.2lf\n", num * v, density /  100.0);
                break;
            }

            if(i != 0 && density > w){

                result = result - buf[i];
                num--;

                if(num > 0){density = result*1.0 / num;}
                else density = result;

                printf("%d %.2lf\n", v * num, density/100.0);
                break;

            }
        }
    }
    return 0;
}


//int main()
//{
//    double ans1, ans2, ans3, ans4;
//    int result = 100, num = 100;
//    int a = 20, b = 100;
//    ans1 = result / num;
//    ans2 = result*1.0 / num;
//    ans3 = a / b;
//    ans4 = a * 1.0 / b;
//    cout << ans1 << endl << ans2 << endl << ans3 << endl<< ans4 << endl;
//    printf("%.2lf\n", ans1);
//    printf("%.2lf\n", ans2);
//    printf("%.2lf\n", ans3);
//    printf("%.2lf\n", ans4);
//
//}
///*
// 1
// 1
// 0
// 0.2
// 1.00
// 1.00
// 0.00
// 0.20
// */

