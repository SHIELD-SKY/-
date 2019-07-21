//
//  main.cpp
//  postOrder
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

void visit(BiTree T)
{
    cout << T->data << ' ';
}
void postOrder(BiTree T)
{
    if(T){
        postOrder(T->lchild);
        postOrder(T->rchild);
        visit(T);
    }
}
int main(){
    BiNode * d = new BiNode('d', NULL, NULL);
    BiNode * e = new BiNode('e', NULL, NULL);
    BiNode * b = new BiNode('b', d, e);
    BiNode * c = new BiNode('c', NULL, NULL);
    BiNode * a = new BiNode('a', b, c);
    
    postOrder(a);
}
