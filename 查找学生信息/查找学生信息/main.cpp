//
//  main.cpp
//  查找学生信息
//
//  Created by APTX on 2/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//
//2003 年清华大学计算机研究生机试真题
//二分查找

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string num;
    string name;
    string gender;
    int age;
    
    bool operator< (const Student & b) const{
        return num < b.num;
    }
}buf[1000+5];

int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        for(int i = 0; i < n; i++)
        {
            cin >> buf[i].num >> buf[i].name >> buf[i].gender >> buf[i].age;
        }
        
        sort(buf, buf+n);
        
        int m;
        string SearchNum;
        cin >> m;
    
        for(int i = 0; i < m; i++)
        {
            //cout << "1111" << endl;
            int ans = -1;
            cin >> SearchNum;
            int top = n-1, bottom = 0;
            
            while (top >= bottom) {
                int mid = (top + bottom) / 2;
                if(buf[mid].num == SearchNum) { ans = mid; break;}
                else if(buf[mid].num < SearchNum) {bottom = mid + 1;}
                else if (buf[mid].num > SearchNum) {top = mid - 1;}
            }
           // cout << "ddddd";
            if(ans != -1) {
                cout << buf[ans].num + " " <<  buf[ans].name + " " << buf[ans].gender + " " << buf[ans].age << endl;
            }
            else if(ans == -1) {cout << "No Answer!";}
        }
    }
    
    return 0;
}
