#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
vector<int> c(200010, 0), d(200010, 0);
vector<vector<int>> g1(200010), g2(200010);
vector<vector<int>> ch1(200010), ch2(200010);
bool st[200010];
int ans = 0;

void build_tree(vector<vector<int>>& g, vector<vector<int>>& ch, int u, int fa){
    for(auto& v : g[u]){
        if(v == fa) continue;

        ch[u].push_back(v);
        build_tree(g, ch, v, u);
    }
}

void dfs(int u, int v, int cost){
    ans = max(ans, cost);

    int sz1 = (int)ch1[u].size();
    int sz2 = (int)ch2[v].size();
    int i = 0, j = 0;
    while((i < sz1) && (j < sz2)){
        int &wu = c[ch1[u][i]], &wv = d[ch2[v][j]];
        if(wu == wv){
            dfs(ch1[u][i], ch2[v][j], cost+1);
            i++, j++;
        }
        else if(wu < wv){
            i++;
        }
        else{
            j++;
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++) cin >> c[i];
    for(int i = 1; i <= m; i++) cin >> d[i];
    
    // 根都不相等，公共前缀长度是 0
    if (c[1] != d[1]) {
        cout << 0 << '\n';
        return 0;
    }

    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
        g1[v].push_back(u);
    }
    for (int i = 0; i < m - 1; i++){
        int u, v;
        cin >> u >> v;
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    memset(st, 0, sizeof st);
    build_tree(g1, ch1, 1, -1);
    memset(st, 0, sizeof st);
    build_tree(g2, ch2, 1, -1);

    for(int u = 1; u <= n; u++){
        sort(ch1[u].begin(), ch1[u].end(), [&](int a, int b){
            return c[a] < c[b];
        });
    }
    for(int u = 1; u <= m; u++){
        sort(ch2[u].begin(), ch2[u].end(), [&](int a, int b){
            return d[a] < d[b];
        });
    }

    // 根已匹配，长度从 1 开始
    dfs(1, 1, 1);
    cout << ans;
}