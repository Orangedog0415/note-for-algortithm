#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1010;
ll a[N];

int bitCount(int x){
    return __builtin_popcount(x);
}

int main(){
    int n; cin >> n;
    for(int i = 1;i <= n; i++) cin >> a[i];
    int m; cin >> m;

    while(m--){
        for(int i = 1; i <= n; i++){
            a[i] *= bitCount(a[i]);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << a[i] << ' ';
    }
}