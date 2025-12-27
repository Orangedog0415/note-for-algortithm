#include <iostream>
#include <queue>

struct node{
    int data;
    node* next;
};

//正数尾插，负数头插
//保留负数的头尾，把负数尾插在正数头
node* sort_abs(node &L){
    node *h_posi = nullptr, *t_posi = h_posi,
         *h_nega = nullptr, *t_nega = h_nega;
    node *p = L.next;

    while(p != nullptr){
        if(p->data > 0){
            if(h_posi == nullptr){
                h_posi = p;
                h_posi->next = t_posi;
            } 
            else{
                t_posi->next = p;
                t_posi = p;
            }
        }
        else{
            if(t_nega == nullptr){
                t_nega = p;
            }
            p->next = h_nega;
            h_nega = p;
        }
        p = p->next;
    }

    t_nega->next = h_posi;
    L.next = h_nega;
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