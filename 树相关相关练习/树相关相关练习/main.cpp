//
//  main.cpp
//  树相关相关练习
//
//  Created by APTX on 13/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//哈弗曼树

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        while (!Q.empty()) Q.pop();
        for(int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            Q.push(x);
        }
        
        int ans = 0;
        while (Q.size() > 1) {
            int a = Q.top();
            Q.pop();
            int b = Q.top();
            Q.pop();
            ans += a + b;      //该父亲结点必为非叶子结点,固累加其权值 !!!!!!!!!所有构造得到的中间结点(即哈夫曼树上非叶子结点)的权值和即为该哈夫曼树 的带权路径和。
            Q.push(a+b);
        }
        cout << ans << endl;
    }
    return 0;
}
