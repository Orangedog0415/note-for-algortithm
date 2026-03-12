#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010, M = 200010;
vector<pair<int, int>> g[N];
int dist[N];
int n, m, s;
bool vis[N];

struct info{
    int dis, pos;

    bool operator < (const info& Info)const
    {
        return dis > Info.dis;
    }
};

void dij(int s){
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;

    priority_queue<info> heap;
    heap.push({0, s});
    while(heap.size()){
        info t = heap.top(); heap.pop();
        int x = t.pos;
        if(vis[x]) continue;
        vis[x] = true;

        for(auto e : g[x]){
            int y = e.first;
            if(dist[y] > dist[x] + e.second){
                dist[y] = dist[x] + e.second;
                if(!vis[y]){
                    heap.push({dist[y], y});
                }
            }
        }
    }
}

int main(){
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }

    dij(s);

    for(int i = 1; i <= n; i++){
        cout << dist[i] << ' ';
    }
}