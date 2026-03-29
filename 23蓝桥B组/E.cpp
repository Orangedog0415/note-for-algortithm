#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N], h[N], r[N];
int dp[N][10];
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        r[i] = a[i] % 10;

        int num = a[i];
        h[i] = a[i];
        while(num >= 10){
            h[i] = (num /= 10);
        }
    }

    memset(dp, 0x3f, sizeof dp);
    dp[1][r[1]] = 0;

    for(int i = 2; i <= n; i++){
        for(int rear = 0; rear < 10; rear++){
            dp[i][rear] = dp[i-1][rear] + 1;
        }

        dp[i][r[i]] = min(i-1, dp[i][r[i]]);
        dp[i][r[i]] = min(dp[i][r[i]], dp[i-1][h[i]]);
    }

    int ans = 0x3f3f3f3f;
    for(int i = 0; i < 10; i++){
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
}