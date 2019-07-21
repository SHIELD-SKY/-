//
//  main.cpp
//  成绩排序
//
//  Created by APTX on 21/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

//struct E {
//    char name[100+5];
//    int age;
//    int score;
//}buf[1000+10];
//
//bool cmp(E a, E b)
//{
//    if(a.score != b.score) return a.score < b.score;
//    int tmp = strcmp(a.name, b.name);
//    if(tmp != 0) return tmp < 0;
//    else return a.age < b.age;
//}
//int main(int argc, const char * argv[]) {
//    int n;
//    while(scanf("%d", &n) != EOF)
//    {
//        for(int i = 0; i < n; i++)
//        {
//            scanf("%s%d%d", buf[i].name, &buf[i].age, &buf[i].score);
//        }
//        sort(buf, buf + n, cmp);
//        for(int i = 0; i < n; i++){
//            printf("%s %d %d\n", buf[i].name, buf[i].age, buf[i].score);
//        }
//    }
//    return 0;
//}

struct E {
    char name[100+10];
    int age;
    int score;
    bool operator < (const E &b) const{
        if(score != b.score) return score < b.score;
        int tmp = strcmp(name, b.name);
        if(tmp != 0) return tmp < 0;
        else return age < b.age;
    }
}buf[1000+10];

int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s%d%d", buf[i].name, &buf[i].age, &buf[i].score);
        }
        sort(buf, buf + n);
        for(int i = 0; i < n; i++)
        {
            printf("%s %d %d\n", buf[i].name, buf[i].age, buf[i].score);
        }
    }
    return 0;
}



