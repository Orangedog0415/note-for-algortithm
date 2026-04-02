//巨大的模拟
#include <bits/stdc++.h>
using namespace std;

deque<int> q1, q2;
unordered_set<int> s1, s2;
int n1, n2, m;

void q2_add(int v){
    q2.push_front(v);
    s2.insert(v);
            
    //check:q2是否溢出
    if((int)q2.size() > n2){
        int u = q2.back();
        s2.erase(u);
        q2.pop_back();
    }
}

void q2_del(int v){
    for(auto it = q2.begin(); it != q2.end(); ++it){
        if(*it == v){
            q2.erase(it);
            break;
        }
    }
    s2.erase(v);
}

void q1_add(int v){
    q1.push_front(v);
    s1.insert(v);

    //check:q1是否溢出
    
    if((int)q1.size() > n1){
        int u = q1.back();
        s1.erase(u);
        q1.pop_back();

        q2_add(u);
    }
}

void q1_del(int v){
    for(auto it = q1.begin(); it != q1.end(); ++it){
        if(*it == v){
            q1.erase(it);
            break;
        }
    }
    s1.erase(v);
}

void println(const deque<int> &q){
    for(int v : q){
        cout << v << ' ';
    }
    cout << '\n';
}

int main(){
    cin >> n1 >> n2 >> m;

    while(m--){
        int v; cin >> v;

        //1、找不到p
        if(s1.find(v) == s1.end() && s2.find(v) == s2.end()){
            q2_add(v);
        }
        //2、找到p，放到p1头
        //在q1里
        else if(s1.find(v) != s1.end()){
            q1_del(v);
            q1_add(v);
        }
        //在q2里
        else if(s2.find(v) != s2.end()){
            q2_del(v);
            q1_add(v);
        }
    }

    println(q1);
    println(q2);
}

/*
数据结构：q1(n1), q2(n2)
查找p的四种情况：
    1、没有p。
       那就把p放到q2的头
    2、有p。
       那就把p放到q1的头
    3、如果因为情况1，q2产生了溢出
       那就丢掉q2的尾
    4、如果因为情况2，q1产生了溢出
       那就把q1的尾放到q2的头
    5、如果因为情况4，q2产生了溢出
       那就丢掉q2的尾
*/