//
//  main.cpp
//  排序
//
//  Created by APTX on 18/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int buf[100];

//冒泡练习
int BubbleSort()
{
   
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &buf[i]);
        }
        
        int count = 0;
        
        for (int i = 0; i < n; i++)
        {
            bool changed = false;
            for(int j = 0; j < n-i-1; j++)
            {
                if(buf[j] > buf[j + 1]){
//                    int tmp = buf[j];
//                    buf[j] = buf[j+1];
//                    buf[j+1] = tmp;
                    swap(buf[j], buf[j+1]);
                    count++;
                    changed = true;
                }
                
            }
            if(!changed) {break;}
            
        }
        
        for(int i = 0; i < n; i++)
        {
            printf("%d ", buf[i]);
        }
        printf("\n");
        cout << count << "\n";
        printf("\n");
    }
    return 0;
    
}

//sort练习
bool cmp (int x, int y)
{
//    return x < y;

    return x > y;
}

int sort1()
{
    while (scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &buf[i]);
        }
        
        sort(buf, buf + n, cmp);
//        sort(buf, buf + n);
        
        for(int i = 0; i < n; i++)
        {
            printf("%d ", buf[i]);
        }
        printf("\n");
    }
   return 0;
}

int main(int argc, const char * argv[]) {
//    BubbleSort();
    sort1();
    
    
    return 0;
}
