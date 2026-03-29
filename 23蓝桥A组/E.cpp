#include <bits/stdc++.h>
using namespace std;

const int N = 200010;

struct Node{
    map<int, int> mp;
    int c;
    vector<int> sons;
} node[N];

int n;
int ans = 0;

bool merge(int v){
    map<int, int> &mv = node[v].mp;

    mv[node[v].c]++;
    for(auto i : node[v].sons){
        map<int, int> &ms = node[i].mp;

        for(auto t : ms){
            int c = t.first, cnt = t.second;
            mv[c] += cnt;
        }
    }

    int e = 0;
    for(auto t : mv){
        int c = t.first, cnt = t.second;
        if(e == 0){
            e = cnt;
            continue;
        }

        if(e != cnt) return false;
    }

    return true;
}

void dfs(int v){
    for(auto son : node[v].sons){
        dfs(son);
    }
    ans += merge(v);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int c, f;
        cin >> c >> f;

        node[i].c = c;
        node[f].sons.push_back(i);
    }

    dfs(1);

    cout << ans;
}