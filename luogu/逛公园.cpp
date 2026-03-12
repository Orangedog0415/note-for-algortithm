#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct info{
    int dis, pos;

    bool operator < (const info& x)const{
        return x.dis < dis;
    } 
};

const int N = 100010;
int t, n, m, k, p;

vector<pair<int, int>> g[N], rg[N];
int dis[N];
bool vis[N];

// dp[u][j] 表示从 1 到 u，比最短路多走 j 的距离的路径数
int dp[N][55]; 
// ins[u][j] 用于标记该状态是否正在当前的递归调用栈中，用于判 0 环
bool ins[N][55]; 

int dfs(int u, int j){
    if(ins[u][j]) return -1;
    if(dp[u][j] != -1) return dp[u][j];

    ins[u][j] = 1;

    int res = 0;
    if(u == 1 && j == 0) res = 1;

    for(auto e : rg[u]){
        int v = e.first, w = e.second;

        int j_v = dis[u] - dis[v] + j - w;
        if(j_v >= 0 && j_v <= k){
            int val = dfs(v, j_v);
            if(val == -1) return -1;
            res = (res + val) % p;
        }
    }

    ins[u][j] = 0;
    return dp[u][j] = res;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m >> k >> p;
        for (int i = 1; i <= n; i++) {
            g[i].clear();
            rg[i].clear();
        }
        
        for(int i = 0; i < m; i++){
            int a, b, w;
            cin >> a >> b >> w;
            g[a].push_back({b, w});
            rg[b].push_back({a, w});
        }

        //dij
        memset(dis, 0x3f, sizeof dis); dis[1] = 0;
        memset(vis, 0, sizeof vis);
        priority_queue<info> q;
        q.push({0, 1});
        while(q.size()){
            auto t = q.top(); q.pop();
            int d = t.dis, x = t.pos;
            if(vis[x]) continue;
            vis[x] = true;

            for(auto e : g[x]){
                int y = e.first, w = e.second;
                if(dis[y] > dis[x] + w){
                    dis[y] = dis[x] + w;
                    if(!vis[y]){
                        q.push({dis[y], y});
                    }
                }
            }
        }
        //dij-over

        memset(dp, -1, sizeof dp);
        memset(ins, 0, sizeof ins);

        int ans = 0;
        bool ring0 = 0;
        for(int j = 0; j <= k; j++){
            int val = dfs(n, j);
            if(val == -1){
                ring0 = 1;
                break;
            }
            ans = (ans + val) % p;
        }

        if(ring0){
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }
}