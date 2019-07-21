//
//  main.cpp
//  二叉搜索树
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
    int c;
}Tree[110];

int loc;

Node* creat(){
    Tree[loc].lchild = Tree[loc].rchild = NULL;
    return &Tree[loc++];
}

char str1[25], str2[25];//保存二叉排序树的遍历结果,将每一棵树的前序遍历得到 的字符串与中序遍历得到的字符串连接,得到遍历结果字符串
int size1, size2;//保存在字符数组中的遍历得到字符个数
char* str;//当前正在保存字符串
int* size;//当前正在保存字符串中字符个数

void postOrder(Node* T){
    if(T->lchild != NULL){
        postOrder(T->lchild);
    }
    if(T->rchild != NULL){
        postOrder(T->rchild);
    }
    str[(*size)++] = T->c + '0';
}

void inOrder(Node *T) { //中序遍历
    if(T -> lchild != NULL) {
        inOrder(T -> lchild);
    }
    str[ (*size) ++ ] = T -> c + '0';
    if(T -> rchild != NULL) {
        inOrder(T -> rchild);
    }
}

Node* Insert(Node* T, int x){
    if(T == NULL){
        T = creat();
        T-> c = x;
        return T;
    }
    else if(x < T->c) { T->lchild = Insert(T->lchild, x); }
    else if(x > T->c) { T->rchild = Insert(T->rchild, x); }
    return T;
}

int main(int argc, const char * argv[]) {
    int n;
    char tmp[12];
    while (cin >> n && n) {
        loc = 0;
        Node* T= NULL;
        cin >> tmp;
        for(int i = 0; tmp[i] != 0; i++)
        {
            T = Insert(T, tmp[i]-'0');
        }
        
        size1 = 0;
        str = str1;
        size = &size1;
        postOrder(T);
        inOrder(T);
        str1[size1] = 0;
        
        while (n-- != 0) {
            cin >> tmp;
            Node* T2 = NULL;
            for(int i = 0; tmp[i] != 0; i++){
                T2 = Insert(T2, tmp[i]-'0');
            }
            size2 = 0;
            str = str2;
            size = &size2;
            postOrder(T2);
            inOrder(T2);
            str2[size2] = 0;
            puts(strcmp(str1, str2) == 0 ? "YES" : "NO");
        }
        
    }
    return 0;
}
