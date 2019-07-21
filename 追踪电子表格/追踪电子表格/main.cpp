//
//  main.cpp
//  追踪电子表格
//
//  Created by APTX on 9/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://cn.vjudge.net/problem/UVA-512

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
const int maxn = 60;
int a[maxn][maxn];        //电子表
int b[maxn][maxn];        //操作中的备份表
int op[maxn];             //op[i] == 1表示第i行（列）需要插入或删除
int r, c, n;

void Copy(int num1, int num2, int type)
{
    //将b表中的num2行（列）拷贝到a中的num1行（列）中，type == 'R',操作行，否则操作列
    if(type == 'R')
    {
        for(int i = 1; i <= c; i++){        //拷贝一行
            a[num1][i] = b[num2][i];
        }
    }else{
        for (int i = 1; i <= r; i++) {      //拷贝一列
            a[i][num1] = b[i][num2];
        }
    }
}

void insert(char type){
    //type==‘R'表示插入行，否则插入列
    memcpy(b, a, sizeof(a));            //将a表拷贝到b表
    int cnt2 = 0;                       //操作后表的行或者列的数量
    
    if(type == 'R'){
        for(int i = 1; i <= r; i++){
            if(op[i]){                  //拷贝一个空行
                Copy(++cnt2, 0, type);
            }
            Copy(++cnt2, i, type);      //拷贝第i行
        }
    }else{
        for(int i = 1; i <= c; i++){
            if(op[i]){                  //拷贝一个空列
                Copy(++cnt2, 0, type);
            }
            Copy(++cnt2, i, type) ;      //拷贝第i列
        }
    }
    if(type == 'R') r = cnt2;           //表操作完后的行或者列
    else c = cnt2;
}

void del(char type){
    //type==‘R'表示删除行，否则删除列
    memcpy(b, a, sizeof(a));            //将a表拷贝到b表
    int cnt2 = 0;                       //操作后表的行或者列的数量
    
    if(type == 'R'){
        for(int i = 1; i <= r; i++){
            if(!op[i]){                  //不需要删除的行就拷贝回去
                Copy(++cnt2, i, type);
            }
        }
    }else{
        for(int i = 1; i <= c; i++){
            if(!op[i]){                  //不需要删除的列就拷贝回去
                Copy(++cnt2, i, type);
            }
        }
    }
    if(type == 'R') r = cnt2;           //表操作完后的行或者列
    else c = cnt2;
}


int main(int argc, const char * argv[]) {
    int Case = 1;
    while (scanf("%d%d", &r, &c) == 2 && r && c) {
        //将位置信息encode
        cin >> n;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= c; j++){
                a[i][j] = i*100+j; //千百位保存行，个十位保存列
            }
        }
        
        string cmd;
        int x1, y1, x2, y2;
        while (n--) {
            cin >> cmd;
            if(cmd[0] == 'E'){ //交换
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                swap(a[x1][y1], a[x2][y2]);
            }else{       //插入或者删除
                int m;
                scanf("%d", &m);
                int x;
                memset(op, 0, sizeof(op));
                for(int i = 0; i < m; i++)
                {
                    scanf("%d", &x);
                    op[x] = 1;
                }
                if(cmd[0] == 'I'){
                    insert(cmd[1]);
                }else{
                    del(cmd[1]) ;
                }
            }
        }
        
        int q;
        cin >> q;
        if(Case - 1) printf("\n");
        printf("Spreadsheet #%d\n", Case++);
        while (q--) { //q次查询
            int x, y, code;
            scanf("%d%d", &x, &y);
            code = x * 100 + y;
            int flag = 0;
            
            for(int i = 1; i <= r && !flag; i++){
                for(int j = 1; j <= c; j++){
                    if(a[i][j] == code){
                        flag = 1;
                        printf("Cell data in (%d,%d) moved to (%d,%d)\n", x, y, i, j);
                        break;
                    }
                }
            }
            if(!flag) printf("Cell data in (%d,%d) GONE\n", x, y);
        }
    }
    return 0;
}

/*
 7 9
 5
 DR 2 1 5
 DC 4 3 6 7 9
 IC 1 3
 IR 2 2 4
 EX 1 2 6 5
 4
 4 8
 5 5
 7 8
 6 5
 0 0
 */
