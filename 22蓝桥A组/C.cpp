#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 200010;
ll a[N], suf[N];
int n;

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		ll in;
		cin >> in;
		a[i] = suf[i] = in;
		suf[i] += suf[i-1];
	}
	
	ll ans = 0;
	for(int i = 1; i < n; i++){
		ans += a[i] * (suf[n] - suf[i]);
	}
	cout << ans;
}