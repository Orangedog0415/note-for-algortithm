#include <iostream>
using namespace std;

#define ll long long

const int N = 50001;
const int MOD = 7;

int a[N];
int n;
int cnt[7][2];

int main(){
    for(int i = 0; i < MOD; i++){
        cnt[i][0] = N + 1;
        cnt[i][1] = 0;
    }
    cnt[0][0] = 0;

    cin >> n;

    for(int i = 1; i <= n; i++){
        int in; cin >> in;
        a[i] = (in % MOD + a[i - 1]) % MOD;
        cnt[a[i]][0] = min(cnt[a[i]][0], i);
        cnt[a[i]][1] = max(cnt[a[i]][1], i);
    }

    int ans = 0;
    for(int i = 0; i < MOD; i++){
        int t = cnt[i][1] - cnt[i][0];
        ans = max(ans, t);
    }

    cout << ans;
}