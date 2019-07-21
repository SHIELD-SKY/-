//
//  main.cpp
//  数学问题
//
//  Created by APTX on 14/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//特殊乘法

#include <iostream>
using namespace std;

//int main(int argc, const char * argv[]) {
//    cout << 10 % 3<< endl;
//    cout << 10 % (-3) << endl;
//    cout << (-10) % 3<< endl;
//    cout << (-10) % (-3) << endl;
//    return 0;
//}
///*
// 1
// 1
// -1
// -1
// */

//int main()
//{
//    int a, b;
//    while (cin >> a >> b) {
//        int buf1[20], buf2[20], size1 = 0, size2 = 0;
//        while (a != 0) {
//            buf1[size1++] = a % 10;
//            a /= 10;
//        }
//        while (b != 0) {
//            buf2[size2++] = b % 10;
//            b /= 10;
//        }
//        int ans = 0;
//        for(int i = 0; i < size1; i++){
//            for (int j = 0; j < size2; j++) {
//                ans += buf1[i] * buf2[j];
//            }
//        }
//        cout << ans;
//    }
//    return 0;
//}


int main()
{
    char a[11], b[11];
    while (cin >> a >> b) {
        int ans = 0;
        for(int i = 0; a[i] != 0; i++){
            for(int j = 0; b[j] != 0; j++){
                ans += (a[i] - '0') *(b[j] - '0');
            }
        }
        cout << ans << endl;
    }
}
