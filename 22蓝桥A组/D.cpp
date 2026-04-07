#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010;
int n, m, x;
int a[N];
int best[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> x;
    const int LIM = 1 << 20;
    vector<int> last(LIM, 0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        int need = a[i] ^ x;
        best[i] = max(best[i - 1], last[need]);
        last[a[i]] = i;
    }

    while(m--){
        int l, r;
        cin >> l >> r;
        cout << (best[r] >= l ? "yes\n" : "no\n");
    }

    return 0;
}