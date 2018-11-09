//
//  main.cpp
//  树相关算法练习
//
//  Created by APTX on 9/11/2018.
//  Copyright © 2018 APTX. All rights reserved.
//

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

typedef  long long ll;

typedef char ElemType;

typedef  struct  BiNode{
    ElemType data;
    BiNode* lchild;
    BiNode* rchild;
    
    BiNode(ElemType d, BiNode* l, BiNode* r){
        data = d;
        lchild = l;
        rchild = r;
    }
}* BiTree;

void visit(BiTree T)
{
    if(T){
        cout << T->data;
    }
}

void postOrder(BiTree T)
{
    if(T){
        postOrder(T->lchild);
        postOrder(T->rchild);
        visit(T);
    }
}

void deleteBiTree(BiTree T){
    //递归删除后序遍历二叉树T
    if(T){
        deleteBiTree(T->lchild);
        deleteBiTree(T->rchild);
        free(T);
    }
}

//给定二叉树T.设计算法复制二叉树T
BiTree copy(BiTree T)
{
    if(T){
        BiNode* lc = copy(T->lchild);
        BiNode* rc = copy(T->rchild);
        BiNode* root = new BiNode(T->data, lc, rc);
        return root;
    }
    return NULL;
}

//判断二叉树是否为镜像
bool JudgeSame(BiTree T1, BiTree T2)
{
    if(T1 == NULL && T2 == NULL) return true;
    if(T1 == NULL || T2 == NULL) return false;
    
    bool lc = JudgeSame(T1->lchild, T2->lchild);
    bool rc = JudgeSame(T1->rchild, T2->rchild);
    return T1->data == T2->data && lc && rc;
}

//求二叉树宽度
void getLevelCnt(BiTree T, int d, int* H)
{//得到二叉树T中每一层节点数量，d为当前节点层次， 统计结果保留在H中
    if(T){
        getLevelCnt(T->lchild, d+1, H);
        getLevelCnt(T->rchild, d+1, H);
        H[d]++;
    }
}
int getWidth(BiTree T)
{
//    int h[100];
//    memset(h, 0, sizeof(h));
    
    int h[100] = {0};
//    for (auto num : h)
//        cout << num << endl;
//    for (auto num : h)
//    {
//        bool a = true;
//        if(num != 0)
//        {
//            a = false;
//            return 0;
//        }
//        cout << " all nums is 0";
//    }
//
    getLevelCnt(T, 1, h);
    int maxn = 0;
    for (auto value : h)
    {
        maxn = max(maxn, value);
    }
    return maxn;
}
//后序遍历非递归算法
void postOrderNoRecursion(BiTree T)
{
    stack<BiNode*> S;
    BiNode* p = T;       //遍历指针
    BiNode* r = NULL;   //遍历序列中前驱
    
    while (p || !S.empty()) {// 当前结点非空或者栈非空的时候
        if(p){              // p非空情况应该访问p的左孩子
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            if(p->rchild && p->rchild != r){
                p = p->rchild;
            }
            else{
                S.pop();
                visit(p);
                r = p;     //更新r
                p = NULL; //让p下次去拿栈顶元素
            }
        }
    }
}

//查找结点x的所有祖先结点
void getFather(BiTree T, ElemType x)
{
    stack<BiNode*> S;
    BiNode* p = T;
    BiNode* r = NULL;
    
    while (p || !S.empty()) {
        if(p){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            if (p->rchild && p->rchild != r) {
                p = p->rchild;
            }
            else{
                S.pop();
                if(p->data == x){
                    while (!S.empty()) {
                        visit(S.top());
                        S.pop();
                    }
                }
                r = p;
                p = NULL;
            }
        }
    }
}

//查找结点p,q的最近公共祖先
BiTree getFather2(BiTree T, ElemType P, ElemType Q)
{
    stack<BiNode*> S;
    BiNode* p = T;
    BiNode* r = NULL;
    
    stack<BiNode*> SP;
    stack<BiNode*> SQ;
    
    while (p || !S.empty()) {
        if(p){
            S.push(p);
            p = p->lchild;
        }
        else{
            p = S.top();
            if(p->rchild && p->rchild != r){
                p = p->rchild;
                
            }
            else{
                S.pop();
                if(p->data == P){
                    SP = S;
                }
                if(p->data == Q){
                    SQ = S;
                }
                r = p;
                p = NULL;
            }
        }
    }
    
    if(SP.size() == 0 || SQ.size() == 0) return NULL;
    while (SP.size() != SQ.size()) {
        if(SP.size() > SQ.size()) SP.pop();
        else SQ.pop();
    }
    while (SP.top() != SQ.top()) {
        SP.pop();
        SQ.pop();
    }
    return SP.top();
}

int main(){
    BiNode* f = new BiNode('f', NULL, NULL);
    BiNode* d = new BiNode('d', NULL, NULL);
    BiNode* e = new BiNode('e', NULL, NULL);
    BiNode* b = new BiNode('b', d, e);
    BiNode* c = new BiNode('c', f, NULL);
    BiNode* a = new BiNode('a', b, c);
    
//    int width = 0;
//    width = getWidth(a);
//    cout << width << endl;
    
//    postOrder(a);
//    BiTree TCopy = copy(a);
//    if(JudgeSame(TCopy, a))
//        cout << "same" << endl;
//    else cout << "Not same" << endl;
//    postOrder(TCopy);
    
//    postOrder(a);
//    postOrderNoRecursion(a);
    
//    getFather(a, 'e');
    
    visit(getFather2(a, 'd', 'e'));
    
    return 0;
}
