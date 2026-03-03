#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[110][110];
int m, n;
int mincost[110][110];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int x, int y, bool ismagic, int cost, int color){
    if(x < 1 || x > m || y < 1 || y > m) return;

    if(cost >= mincost[x][y]) return;

    mincost[x][y] = cost;

    for(int k = 0; k < 4; k++){
        int xx = x + dx[k], yy = y + dy[k];
        if(xx < 1 || yy < 1 || xx > m || yy > m) continue;

        if(a[xx][yy] != 2){
            int ex = a[xx][yy] ^ color;
            dfs(xx, yy, 0, cost + ex, a[xx][yy]);
        }
        else{
            if(ismagic) continue;
            else{
                dfs(xx, yy, 1, cost + 2, a[x][y]);
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = 2;
        }
    }
    memset(mincost, 0x3f, sizeof mincost);

    while(n--){
        int x, y, c;
        cin >> x >> y >> c;
        a[x][y] = c;
    }

    dfs(1, 1, 0, 0, a[1][1]);

    if(mincost[m][m] == INF) cout << -1;
    else cout << mincost[m][m];
}