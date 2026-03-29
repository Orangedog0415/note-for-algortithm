#include <bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[35];
long long suffix2[35];
int ans = INT_MAX;

void dfs(int idx, long long sum2, int cuts) {
    long long target2 = 2 * m;

    if (sum2 > target2) return;
    if (cuts >= ans) return;
    if (sum2 + suffix2[idx] < target2) return;

    if (idx == n) {
        if (sum2 == target2) ans = min(ans, cuts);
        return;
    }

    // 先尝试整瓜，通常更快靠近目标和。
    dfs(idx + 1, sum2 + 2 * a[idx], cuts);
    // 选半个瓜会增加一次劈瓜操作。
    dfs(idx + 1, sum2 + a[idx], cuts + 1);
    // 不选当前瓜。
    dfs(idx + 1, sum2, cuts);
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a, a + n, greater<long long>());

    suffix2[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suffix2[i] = suffix2[i + 1] + 2 * a[i];
    }

    dfs(0, 0, 0);

    if (ans == INT_MAX) cout << -1;
    else cout << ans;

    return 0;
}