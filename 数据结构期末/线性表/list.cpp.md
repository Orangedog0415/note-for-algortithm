```cpp
#include <iostream>
#include <stdlib.h>

struct node{
    int val;
    node* next;
};

void insert(int v, node* pt){
    node* p = (node*) malloc(sizeof node);
    p->val = v;
    p->next = pt->next;
    pt->next = p;
}
//头节点insert(v, L)
//尾节点insert(v, last)

node* reverse(node* h) {
    // 空链表或只有一个节点
    if (h == nullptr || h->next == nullptr)
        return h;

    node* newHead = reverse(h->next);

    h->next->next = h;  // 关键：让下一个节点指回自己
    h->next = nullptr; // 当前节点断开

    return newHead;
}

node* merge(node* L1, node* L2){
    node* h1 = L1->next,* h2 = L2->next;
    node* L = (node*)malloc(sizeof node);
    node* h = (node*)malloc(sizeof node);
    L->next = h, h->next = nullptr;

    while(h1 && h2){
        int v;
        if(h1->val <= h2->val){
            v = h1->val;
        }
        else{
            v = h2->val;
        }
        node* p = (node*) malloc(sizeof node);
        p->val = v;
        p->next = nullptr;
        h->next = p;
        h = p;
    }
    //剩下的归并懒得写了
}