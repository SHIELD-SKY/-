//
//  main.cpp
//  逆置数组
//
//  Created by APTX on 6/9/2018.
//  Copyright © 2018 APTX. All rights reserved.
//
//p23 8
#include <iostream>
typedef int DataType;

using namespace std;

void  Reverse(DataType A[], int left, int right, int arraySize)
{
    if(left >= right || right >= arraySize)
        return;
    int mid = (left+right)/2;
    for(int i = 0; i <= mid - left; i++)
    {
        DataType temp = A[left+i];
        A[left+i] = A[right-i];
        A[right-i] = temp;
    }
}

void Exchange(DataType A[], int m, int n, int arraySize)
{
    Reverse(A, 0, m+n-1, arraySize);
    Reverse(A, 0, n-1, arraySize);
    Reverse(A, n, m+n-1, arraySize);
}
int main(int argc, const char * argv[]) {
    
    DataType a[] = {1,2,3,4,5,6,7,8};
    Exchange(a, 3, 5, 8);
    for(int i = 0; i < 8; i++)
        cout << a[i] << endl;
    return 0;
}
