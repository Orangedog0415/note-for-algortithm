#include<iostream>
#include<vector>
using namespace std;

#define ll long long

const int N = 100010;

int main(){
    int n;
    long long S;
    cin >> n >> S;

    vector<pair<int, int>> a(n);
    int maxc = 0;
    for(int i = 0; i < n; i++){
        int p, c;
        cin >> p >> c;
        a[i] = {p, c};
        maxc = max(c, maxc);
    }

    vector<ll> sumP(maxc + 10, 0),
              sumPC(maxc + 10, 0);
    for(auto &it : a){
        ll p = it.first, c = it.second;
        sumP[c] += p;
        sumPC[c] += p*c;
    }

    vector<ll> sufP(maxc + 10, 0),
              sufPC(maxc + 10, 0);
    for(int c = maxc; c >= 1; c--){
        sufP[c] = sufP[c+1] + sumP[c];
        sufPC[c] = sufPC[c+1] + sumPC[c];
    }

    ll ans = (1ll << 62);
    for(ll x = 0; x <= maxc; x++){
        ll cost = x*S + sufPC[x+1] - x*sufP[x+1];
        ans = min(ans, cost);
    }
    cout << ans;
}