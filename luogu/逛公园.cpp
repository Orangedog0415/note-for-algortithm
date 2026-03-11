//要判断0环
//要一次bfs先找出d，后续bfs计算d+k

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int M = 2e5 + 10;
int t, n, m, k, p;
vector<pair<int, int>> g[N];//{to, w}
vector<pair<int, int>> rg[N];//{to, w}
vector<pair<int, int>> w0[N];//{from, to}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> k >> p;
        for(int i = 1; i <= n; i++){
            g[i].clear();
            rg[i].clear();
            w0[i].clear();
        }
        for(int i = 0; i < m; i++){
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            rg[v].push_back({u, w});
            if(w == 0) w0[u].push_back({u, v});
        }

        
    }
}