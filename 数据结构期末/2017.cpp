#include <iostream>
#include <queue>

struct node{
    int data;
    node* next;
};

//正数尾插，负数头插
//保留负数的头尾，把负数尾插在正数头
void sort_list(struct node *L) {
    struct node *p = L->next; // 工作指针，用于遍历原链表
    struct node *q;           // 临时指针，用于保存p的下一个节点
    
    struct node *posHead = NULL; // 正数链表的头指针
    struct node *posTail = NULL; // 正数链表的尾指针
    struct node *negTail = NULL; // 负数链表的尾指针（即第一个插入的负数）

    // 1. 断开头结点，初始化L为空链表（用于存放负数）
    L->next = NULL; 

    while (p != NULL) {
        q = p->next; // 关键：在修改p->next之前，先保存下一个节点，防止断链
        
        if (p->data < 0) {
            // === 负数：头插法 ===
            // 逻辑：插入到L之后
            if (L->next == NULL) {
                // 如果是第一个插入的负数，它将成为负数部分的最后一个节点
                negTail = p;
            }
            p->next = L->next;
            L->next = p;
        } 
        else {
            // === 正数：尾插法 ===
            // 逻辑：追加到正数链表末尾
            if (posHead == NULL) {
                posHead = p;
                posTail = p;
            } else {
                posTail->next = p;
                posTail = p;
            }
            // 尾插后务必将next置空，防止残留原本的链接
            posTail->next = NULL; 
        }
        
        p = q; // 继续处理下一个节点
    }

    // 2. 连接负数部分和正数部分
    if (negTail != NULL) {
        // 如果存在负数，将正数链表接在负数链表的尾部
        negTail->next = posHead;
    } else {
        // 如果没有负数，L直接指向正数链表
        L->next = posHead;
    }
    
    // 注意：正数链表的尾部 posTail->next 在循环中已经被置为 NULL，无需额外操作
}

struct BiTnode{
    int data;
    BiTnode *lc, *rc;
};

int depth(BiTnode *rt){
    if(rt == nullptr) return 0;
    if(rt->lc == nullptr && rt->rc == nullptr) return 0;
    return std::max(depth(rt->lc), depth(rt->rc)) + 1;
}

const int N = 100010;
//邻接表
typedef struct Anode{
    int vi;
    int wi;
    Anode *next;
} Alink;

typedef struct{
    int data;
    Alink *vh;
}Vnode;

typedef struct{
    Vnode v[N];
    int n, m;
    int visited[N];
}Alist;

void visit(int k){
    std::cout << k << '\n';
}

std::queue<int> q;

void BFS(Alist *G, int k) {
    // 1. 定义队列及指针
    // 假设 N 已经在宏定义中，或者使用 G->n 作为界限
    // 这里的 maxSize 只要大于等于节点总数即可
    int Q[N]; 
    int front = 0, rear = 0; 
    
    // 辅助指针，用于遍历边链表
    Anode *p; 
    int u, w; // u为当前处理顶点，w为邻接顶点索引

    // 2. 初始化访问标记数组 (如果调用前未初始化，需在此处初始化)
    for(int i = 0; i < G->n; i++) {
        G->visited[i] = 0; 
    }

    // 3. 处理起始节点 k
    visit(k);               // 访问起始点（题目未具体定义visit，假设为打印）
    G->visited[k] = 1;      // 标记为已访问
    Q[rear++] = k;          // 入队 (赋值后 rear 后移)

    // 4. 队列不为空时循环
    while (front != rear) {
        u = Q[front++];     // 出队 (取出队头元素，front 后移)

        // 指向当前顶点 u 的第一个邻接点
        // 注意：根据题目图示，顶点数组是 v，链表头指针是 Vh
        p = G->v[u].vh;    

        // 遍历 u 的所有邻接点
        while (p != NULL) {
            w = p->vi;      // 获取邻接点在顺序表中的位置下标

            // 关键判断：如果该邻接点未被访问
            if (G->visited[w] == 0) {
                visit(w);           // 访问节点
                G->visited[w] = 1;  // 【关键】入队前立即标记，防止重复入队
                Q[rear++] = w;      // 入队
            }
            p = p->next;    // 指向下一个邻接点
        }
    }
}