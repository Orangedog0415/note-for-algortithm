#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s0, s1;
    cin >> s0 >> s1;
    int n = (int)s0.size();

    vector<int> m(n, 0);
    int L = -1, R = -1;
    for (int i = 0; i < n; ++i) {
        if (s0[i] == '#') m[i] |= 1;
        if (s1[i] == '#') m[i] |= 2;
        if (m[i] != 0) {
            if (L == -1) L = i;
            R = i;
        }
    }

    if (L == -1) {
        cout << 0 << '\n';
        return 0;
    }

    const int INF = 1e9;
    int pc[4] = {0, 1, 1, 2};
    int dp[4] = {INF, INF, INF, INF};
    int ndp[4] = {INF, INF, INF, INF};

    for (int t = 1; t <= 3; ++t) {
        if ((t & m[L]) == m[L]) {
            dp[t] = pc[t] - pc[m[L]];
        }
    }

    for (int i = L + 1; i <= R; ++i) {
        for (int t = 0; t < 4; ++t) ndp[t] = INF;

        for (int p = 1; p <= 3; ++p) {
            if (dp[p] >= INF) continue;
            for (int t = 1; t <= 3; ++t) {
                if ((t & m[i]) != m[i]) continue;
                if ((p & t) == 0) continue;
                int add = pc[t] - pc[m[i]];
                ndp[t] = min(ndp[t], dp[p] + add);
            }
        }

        for (int t = 0; t < 4; ++t) dp[t] = ndp[t];
    }

    int ans = min(dp[1], min(dp[2], dp[3]));
    cout << ans << '\n';
    return 0;
}