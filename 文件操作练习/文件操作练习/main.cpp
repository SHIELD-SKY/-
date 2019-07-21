//
//  main.cpp
//  文件操作练习
//
//  Created by APTX on 31/1/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, const char * argv[]) {
    
    FILE* rf = fopen("main.cpp", "r");
    FILE* wf = fopen("main-2.cpp", "w");
    
    char buf[100];
    
    while (fgets(buf, 100, rf) != NULL) {
        fputs(buf, wf);
    }
    
    fclose(rf);
    fclose(wf);
    
    return 0;
}
