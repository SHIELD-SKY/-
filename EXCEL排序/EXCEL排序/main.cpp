//
//  main.cpp
//  EXCEL排序
//
//  Created by APTX on 21/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//https://vjudge.net/problem/HDU-1862

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int maxn = 100000+ 10;

//421ms, 3340kB

//struct student  {
// char stuNum[7];
//    char name[9];
//    int score;
//}buf[100000+ 10];
//
//bool cmp1(student a, student b)
//{
//    return strcmp(a.stuNum, b.stuNum) < 0;
//}
//
//bool cmp2(student a, student b)
//{
//    int tmp = strcmp(a.name, b.name);
//    if(tmp != 0) return tmp < 0;
//    else if(tmp == 0) return strcmp(a.stuNum, b.stuNum) < 0;
//    return false;
//}
//
//bool  cmp3(student a, student b)
//{
//    if (a.score != b.score) {
//        return a.score < b.score;
//    }
//    else if(a.score == b.score) return strcmp(a.stuNum, b.stuNum) < 0;
//    return false;
//}
//
//
//int main(int argc, const char * argv[]) {
//    int count = 0;
//    int N,C;
//    while (scanf("%d%d", &N, &C) != EOF) {
//        if(N == 0) return 0;
//        else{
//            count++;
//            for(int i = 0; i < N; i++)
//            {
//                scanf("%s%s%d", buf[i].stuNum, buf[i].name, &buf[i].score);
//            }
//            switch (C) {
//                case 1:
//                    sort(buf, buf+N, cmp1);
//                    break;
//                case 2:
//                    sort(buf, buf+N, cmp2);
//                    break;
//                case 3:
//                    sort(buf, buf+N, cmp3);
//                    break;
//                default:
//                    break;
//            }
//
//            printf("Case %d:\n", count);
//
//            for (int i = 0; i < N; i++) {
//                printf("%s %s %d\n", buf[i].stuNum, buf[i].name, buf[i].score);
//            }
//        }
//    }
//    return 0;
//}
//

//2168ms, 13208kB

int n, c;

struct student {
    string num;
    string name;
    int score;
    
    bool operator < (const  student &b) const {
        if(c == 1) return num < b.num;
        else if( c == 2) return name != b.name ? name < b.name : num < b.num;
        else if(c == 3) return score != b.score ? score < b.score : num < b.num;
        return false;
    }
}buf[100000+ 10];
    
int main()
{
    int count = 0;
    while (cin >> n >> c && n != 0) {
        
        cout << "Case " << ++count <<":" << endl;
        
        for(int i = 0; i < n; i++)
        {
            cin >> buf[i].num >> buf[i].name >> buf[i].score;
        }
        sort(buf, buf+n);
        for (int i = 0; i < n; i++) {
            cout << buf[i].num << " " << buf[i].name << " "<< buf[i].score << endl;
        }
        
    }
    return 0;
}

