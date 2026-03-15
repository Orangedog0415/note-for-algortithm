#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
using namespace std;

const int N = 20;
//0:A ; 1:E ; 2:I ; 3:O ; 4:U
//rear存尾back，head存头[0]
vector<string> dic_rear[5], dic_head[5];
unordered_map<string, int> mp;
int n;

int dp[N][5];

int CharToInt(char c){
    if(c == 'A') return 0;
    if(c == 'E') return 1;
    if(c == 'I') return 2;
    if(c == 'O') return 3;
    if(c == 'U') return 4;
    return -1;
}

char IntToChar(int i){
    if(i == 0) return 'A';
    if(i == 1) return 'E';
    if(i == 2) return 'I';
    if(i == 3) return 'O';
    if(i == 4) return 'U';
    return ' ';
}

//dfs(c, step)表示使用step个单词且第step个单词以c结尾所能得到的最大复杂度
int dfs(int i, int step){
    if(dp[step][i] != -1) return dp[step][i];

    int res = 0, wlength = -1;
    for(auto word : dic_rear[i]){
        if(mp[word] == 0){
            mp[word] = 1;
            int t = dfs(CharToInt(word[0]), step-1);
            res = max(res, t + (int)word.length());
            mp[word] = 0;
        }
    }

    return dp[step][i] = res;
}

int main(){
    cin >> n;
    for(int _ = 0; _ < n; _++){
        string w;
        cin >> w;
        mp.insert({w, 0});
        dic_rear[CharToInt(w.back())].push_back(w);
        dic_head[CharToInt(w[0])].push_back(w);
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = dp[0][4] = 0;
    int ans = 0;
    for(int i = 0; i < 5; i++){
        ans = max(ans, dfs(i, n));
    }
    cout << ans;
}