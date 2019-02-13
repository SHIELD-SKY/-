//
//  main.cpp
//  二叉树遍历
//
//  Created by APTX on 13/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    Node* lchild;
    Node* rchild;
    char c;
}Tree[50];  //静态内存分配数组
int loc;   //静态数组中已经分配的结点个数

Node *creat(){  //申请一个结点空间,返回指向其的指针
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

char str1[30], str2[30];//保存前序和中序遍历结果字符串
void postOrder(Node* T){
    if(T->lchild != NULL){
        postOrder(T->lchild);
    }
    if(T->rchild != NULL){
        postOrder(T->rchild);
    }
    cout << T-> c;
}

Node* build(size_t s1, size_t e1, size_t s2, size_t e2){      //由字符串的前序遍历和中序遍历还原树,并返回其根节点,其中 前序遍历结果为由str1[s1]到str1[e1]，中序遍历结果为str2[s2]到str2[e2]
    Node* ret = creat();                //为该树根节点申请空间
    ret->c = str1[s1];
    int rootIdx;
    for(int i = s2; i <= e2; i++)
    {
        if(str2[i] == str1[s1]){
            rootIdx = i;
            break;
        }
        
    }
    if(rootIdx != s2){
        ret->lchild = build(s1+1, s1 +(rootIdx -s2), s2, rootIdx - 1);
    }
    if(rootIdx != e2){
        ret->rchild = build(s1 + (rootIdx - s2) + 1, e1, rootIdx + 1, e2);
    }
    return ret;
}
int main(int argc, const char * argv[]) {
    while (cin >> str1) {
        cin >> str2;
        loc = 0;
        size_t L1 = strlen(str1);
        size_t L2 = strlen(str2);
        Node* T = build(0, L1-1, 0, L2-1);
        postOrder(T);
        cout << endl;
    }
    return 0;
}

