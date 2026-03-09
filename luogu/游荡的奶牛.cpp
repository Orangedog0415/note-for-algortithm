#include <iostream>
using namespace std;

char a[110][110];
int n, m;
int r1, c1, r2, c2;
int t;
int cnt[110][110][16];

int dfs(int t, int x, int y){
    if(x <= 0 || y <= 0 || x > n || y > m) return 0;
    if(a[x][y] == '*') return 0;
    if(t == 0){
        return (x == r1 && y == c1) ? 1 : 0;
    }
    if(cnt[x][y][t]) return cnt[x][y][t];

    int up = dfs(t-1, x, y+1), 
        down = dfs(t-1, x, y-1), 
        left = dfs(t-1, x-1, y), 
        right = dfs(t-1, x+1, y);

    return cnt[x][y][t] = up + down + left + right;
}

int main(){
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;

    cnt[r1][c1][0] = 1;

    dfs(t, r2, c2);

    cout << cnt[r2][c2][t];
}