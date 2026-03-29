#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1000000007;
const int MAX = 500010;

ll a[MAX];
int cnt[MAX];
bool st[MAX];
ll fac[MAX];

int main(){
    int in; cin >> in;
    int sz = in - 2;
    for(int i = 0; i < in; i++){
        ll ai; cin >> ai;
        a[i] = ai;
        cnt[ai]++;
    }

    fac[1] = 1;
    for(int i = 2; i <= sz; i++){
        fac[i] = fac[i-1]*i%MOD;
    }

    ll base = fac[sz];
    vector<ll> div_pre;
    for(int v = 1; v < MAX; v++){
        if(cnt[v] > 1){
            div_pre.push_back(fac[cnt[v]]);
        }
    }

    ll ans = 0;
    for(int x = 1; 1ll*x*x <= sz; x++){
        if(sz % x != 0 || !cnt[x] || !cnt[sz/x]){
            continue;
        }

        ll all = base;
        for(auto t : div_pre){
            all /= t;
        }

        if(x == sz/x){
            all *= cnt[x]*(cnt[x]-1);
        } else {
            all *= 2*cnt[x]*cnt[sz/x];
        }

        ans = (ans + all) % MOD;
    }

    cout << ans;
}