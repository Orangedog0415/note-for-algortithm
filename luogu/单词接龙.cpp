#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
using namespace std;

const int N = 20;
//0:A ; 1:E ; 2:I ; 3:O ; 4:U
string w[N];
int n;

int dp[1 << N][5];

int CharToInt(char c){
    if(c == 'A') return 0;
    if(c == 'E') return 1;
    if(c == 'I') return 2;
    if(c == 'O') return 3;
    if(c == 'U') return 4;
    return -1;
}

//dfs(c, step)表示使用step个单词且第step个单词以c结尾所能得到的最大复杂度
int dfs(int i, int mask){
    if(dp[mask][i] != -1) return dp[mask][i];

    int res = 0;
    for(int j = 0; j < n; j++){
        if(!(mask & (1 << j)) && CharToInt(w[j].back()) == i){
            int next = CharToInt(w[j][0]);
            int t = dfs(next, mask | 1 << j);
            res = max(res, t + (int)w[j].length());
        }
    }

    return dp[mask][i] = res;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 0; i < 5; i++){
        ans = max(ans, dfs(i, 0));
    }
    cout << ans;
}