/*
我讲一下我对这道题目的见解

收集所有连续区间(l1, r1)...(lk, rk)(闭区间)
其中li可以与ri相等

对于每个连续区间内部的好串，只要以等差数列求和公式就能O（1）求得

对于跨两个相邻连续区间的好串，其数量也是易于统计的
设(li, ri), (lj, rj)相邻，区间长度分别是leni = ri - li + 1, lenj = rj - lj + 1
设lenmin = lmin, lenmax = lmax
其中好串的数量=
2*((lmin+1)*lmin/2) +
(lmax + lmin - 1 - 2*lmin)*lmin
于是做完了
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    string s;
    cin >> s;
    n = (int)s.size();

    vector<pair<int, int>> segs;
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && (s[j] == s[j-1] || s[j] == s[j-1] + 1)) {
            j++;
        }
        segs.emplace_back(i, j - 1);
        i = j;
    }

    ll ans = 0;
    for (auto [l, r] : segs) {
        ll len = r - l + 1;
        ans += len * (len + 1) / 2;
    }

    for (int i = 0; i + 1 < (int)segs.size(); i++) {
        auto [l1, r1] = segs[i];
        auto [l2, r2] = segs[i + 1];
        ll len1 = r1 - l1 + 1, len2 = r2 - l2 + 1;
        ll lenmin = min(len1, len2), lenmax = max(len1, len2);
        ans += lenmin * (lenmin + 1) + (lenmax - lenmin - 1) * lenmin;
    }
    cout << ans << endl;
}