//
//  main.cpp
//  编写算法求二叉树中以权值为x的节点为根的子树的高度
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


//编写算法求二叉树中以权值为x的节点为根的子树的高度
//思路：二叉树的高度等于左右子树高度加一
int Hight(BiTree T)
{
    if(T == NULL) return 0;
    
    int lh = Hight(T->lchild);
    int rh = Hight(T->rchild);
    return max(lh, rh) + 1;
    
    return 0;
}

void x_hight(BiTree T, ElemeType x)
{
    if(T)
    {
        x_hight(T->lchild, x);
        x_hight(T->rchild, x);
        if(T->data == x) cout << "以" << x << "为根节点的高度：" << Hight(T);
    }
}

int main(){
    BiNode * d = new BiNode('d', NULL, NULL);
    BiNode * e = new BiNode('e', NULL, NULL);
    BiNode * b = new BiNode('b', d, e);
    BiNode * c = new BiNode('c', NULL, NULL);
    BiNode * a = new BiNode('a', b, c);
    
    x_hight(a, 'b');
    return 0;
}

