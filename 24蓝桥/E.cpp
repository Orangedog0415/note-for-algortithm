#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

int n, k, T;

const int N = 100010;
int a[N];

double sigma(ll sum1, ll sum2, ll k){
    double s1 = sum1, s2 = sum2, num = k;
    return (num*s2 - s1*s1)/(num*num);
}

bool check(int x){
    vector<int> b;
    b.push_back(0);
    for(int i = 1; i <= x; i++) b.push_back(a[i]);

    sort(b.begin(), b.end());

    vector<ll> pre1(N), pre2(N);
    for(int i = 1; i <= x; i++){
        ll v = b[i];
        pre1[i] = pre1[i-1] + v;
        pre2[i] = pre2[i-1] + v*v;
    }

    for(int r = k; r <= x; r++){
        int l = r - k + 1;
        ll sum1 = pre1[r] - pre1[l-1];
        ll sum2 = pre2[r] - pre2[l-1];

        double sgm = sigma(sum1, sum2, (ll)k);
        if(sgm < T){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> k >> T;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int l = k, r = n, ans = -1;
    while(l <= r){
        int mid = (l + r)/2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans;
}