#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 100010;

int n, m;
ll a[N];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    sort(a+1, a+n+1);
    ll b[N] = {0};
    for(int i = 1; i <= n; i++){
        b[i] = a[i] * a[i];
    }

    ll ans = 0x3f3f3f3f3f3f3f3f;
    for(int l = 1; l + m - 1 <= n; l++){
        int r = l + m - 1;
        ans = min(ans, b[r] - b[l]);
    }
    cout << ans;
}