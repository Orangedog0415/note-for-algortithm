//想法是线性dp
//dp[N][3],dp[i][1]代表第i列只填上面一个,dp[i][2]代表第i列只填下面一个
//dp[i][0]代表第i列填满
//三种情况的i-1列全部填满

//ans = dp[N][0]
//填满i列，用L型填i-1的上下缺角，用1个I型竖着填i-1的满格，用两个I型横着填i-2的满格
//dp[i][0] = dp[i-1][1] + dp[i-1][2] + dp[i-1][0] + dp[i-2][0]
//填到i列的第一个角，用L型填i-2的满格，用I型横着插i-1的下缺角
//dp[i][1] = dp[i-2][0] + dp[i-1][2]
//填到i列的第二个角，用L型填i-2的满格，用I型横着插i-1的上缺角
//dp[i][2] = dp[i-2][0] + dp[i-1][1]
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1000000007;
int n;

int main(){
    cin >> n;

    if(n == 1){
        cout << 1;
        return 0;
    }

    ll full_i2 = 1;  // i = 0
    ll full_i1 = 1, up_i1 = 0, down_i1 = 0;  // i = 1

    for(int i = 2; i <= n; i++){
        ll full = (up_i1 + down_i1 + full_i1 + full_i2) % MOD;
        ll up = (full_i2 + down_i1) % MOD;
        ll down = (full_i2 + up_i1) % MOD;

        full_i2 = full_i1;
        full_i1 = full;
        up_i1 = up;
        down_i1 = down;
    }

    cout << full_i1;
    
}