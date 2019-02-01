//
//  main.cpp
//  Repeater
//
//  Created by APTX on 1/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//POJ 3768

//#include <stdio.h>
//#include <string.h>
//#include <math.h>
//char a[3002][3002];//图形
//char asdf;//分形图形中的字符
//char b[6];//输入用的
//int num,n;
//int flag[6][6];//本组数据是标记用的
//void dayin(int cur,int x,int y)
//{
//    if(cur==0)
//    {
//        a[x][y]=asdf;
//        return ;
//    }
//    int s=pow(n,cur-1);
//    for(int i=0; i<n; i++)//这就是遍历标记数组
//    {
//        for(int j=0; j<n; j++)
//        {
//            if(flag[i][j]==1)//如果没有运行就不采取操作
//                dayin(cur-1,x+i*s,y+j*s);
//        }
//    }
//}
//int main()
//{
//    while(~scanf("%d",&n))
//    {
//        getchar();
//        if(n==0) break;
//        memset(a,' ',sizeof(a));
//        memset(flag,0,sizeof(flag));
//
//        for(int i=0; i<n; i++)
//        {
//            gets(b);
//            for(int j=0; j<n; j++)//遍历图形 并标记
//            {
//                if(b[j]!=' ')
//                {
//                    asdf=b[j];
//                    flag[i][j]=1; //标记
//                }
//            }
//        }
//
//        int m;
//        scanf("%d",&m);
//        int s=pow(n,m);
//        dayin(m,1,1);
//        for(int i=1; i<=s; i++)//这步主要是控制格式
//        {
//            a[i][s+1]='\0';
//            puts(a[i]+1);//切记一定要用puts 并且交G++ 否则无限TLE 其实对比输入优化算法 发现对字符串处理函数的耗时是最短了
//        }
//    }
//}

//188ms, 9548kB
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
using namespace std;

char a[3002][3002];
int flag[6][6] = {false};
int n, m;
char  symbol;

void dayin(int cur, int x, int y)
{
    if(cur == 0) // cur==0时，这一个元素一定有符号， 因为是一直按有符号的往下递归的
    {
        a[x][y] = symbol;
        return;
    }
    int s = pow(n, cur-1);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(flag[i][j]){ //只处理有符号的， 根据这种思想，一直往下递归
                dayin(cur-1, x+i*s, y+j*s);
            }
        }
}

int main()
{
    while ((cin >> n) && n != 0) {
        getchar();
        memset(a, ' ', sizeof(a));
        memset(flag, 0, sizeof(flag));
        
        for(int i = 0; i < n; i++)
        {
            string line;
            getline(cin, line);
            
            for (int j = 0; j < n; j++) {
                if(line[j] != ' '){
                    flag[i][j] = 1;
                    symbol = line[j];
                }
            }
        }

        cin >> m;
        int s = pow(n, m);
        dayin(m, 1, 1);
        for(int i = 1; i <= s; i++)
        {
            a[i][s+1] = '\0';  //puts函数 把字符串和一个换行符输出，因此加斜杠零表示字符串尾, 实际上，经测试，cout 也需要加斜杠零
            //cout << "111111";
            cout << a[i] + 1 << endl;
            //puts(a[i]+1);
        }

    }
}



//
//int main()
//{
//    string line;
//    getline(cin, line);
//
//    cout << line[2];
//}

