//
//  main.cpp
//  二叉排序树
//
//  Created by APTX on 13/2/2019.
//  Copyright © 2019 APTX. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

struct Node{
    Node* lchild;
    Node* rchild;
    int c;
}Tree[110];

int loc;

Node* creat(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

void postOrder(Node* T){
    if(T->lchild != NULL){
        postOrder(T->lchild);
    }
    if(T->rchild != NULL){
        postOrder(T->rchild);
    }
    cout << T->c << ' ';
}

void inOrder(Node* T){
    if(T->lchild != NULL){
        inOrder(T->lchild);
    }
    cout << T->c << ' ';
    if(T->rchild != NULL){
        inOrder(T->rchild);
    }
}

void preOrder(Node* T){
    cout << T->c <<' ';
    if(T->lchild != NULL){
        preOrder(T->lchild);
    }
    if(T->rchild != NULL){
        preOrder(T->rchild);
    }
}

Node* Insert(Node* T, int x){
    if(T == NULL){
        T = creat();
        T->c = x;
        return T;
    }
    else if(x < T->c) { T-> lchild = Insert(T->lchild, x); }
    else if(x > T->c) { T-> rchild = Insert(T->rchild, x); }
    return T;
}
int main(int argc, const char * argv[]) {
    int n;
    while (cin >> n) {
        loc = 0;
        Node* T = NULL;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            T = Insert(T, x);
        }
        preOrder(T);
        cout << endl;
        inOrder(T);
        cout << endl;
        postOrder(T);
        cout << endl;
    }
    return 0;
}
