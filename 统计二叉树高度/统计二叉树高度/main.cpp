//
//  main.cpp
//  统计二叉树高度
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


//求二叉树高度
//思路：二叉树的高度等于左右子树高度加一
int Hight(BiTree T)
{
    if(T == NULL) return 0;
    
    int lh = Hight(T->lchild);
    int rh = Hight(T->rchild);
    return max(lh, rh) + 1;
    
    return 0;
}

int main(){
    BiNode * d = new BiNode('d', NULL, NULL);
    BiNode * e = new BiNode('e', NULL, NULL);
    BiNode * b = new BiNode('b', d, e);
    BiNode * c = new BiNode('c', NULL, NULL);
    BiNode * a = new BiNode('a', b, c);
    
    cout << Hight(a) << endl;
    return 0;
}

