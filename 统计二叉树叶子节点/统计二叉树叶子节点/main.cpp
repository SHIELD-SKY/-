//
//  main.cpp
//  统计二叉树叶子节点
//
//  Created by APTX on 7/11/2018.
//  Copyright © 2018 APTX. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef char ElemeType;



typedef struct BiNode{
    ElemeType data;
    BiNode* lchild;
    BiNode* rchild;
    
    BiNode(ElemeType d, BiNode* l, BiNode* r)
    {
        data = d;
        lchild = l;
        rchild = r;
    }
}* BiTree;

int cnt = 0;
int countLeaf(BiTree T)
{
    if(T){
        countLeaf(T->lchild);
        countLeaf(T->rchild);
        if(T->lchild == NULL && T->rchild == NULL) cnt++;
            return cnt;
    }
    return 0;
}
int main(){
    BiNode * d = new BiNode('d', NULL, NULL);
    BiNode * e = new BiNode('e', NULL, NULL);
    BiNode * b = new BiNode('b', d, e);
    BiNode * c = new BiNode('c', NULL, NULL);
    BiNode * a = new BiNode('a', b, c);
    
    cout << countLeaf(a) << endl;
    return 0;
}
