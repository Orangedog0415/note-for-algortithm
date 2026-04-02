#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int a[N], b[N], c[N];
int n, m;
int ans;
int ar = 0, br = 0, cr = 0;

int pend(){
	int ai = a[ar], bi = b[br], ci = c[cr];
	if(ai == bi && bi == ci) return 200;
	if(ai == bi || bi == ci) return 100;
	if(ai+1 == bi && bi+1 == ci) return 200;
	
	int s[3] = {ai, bi, ci};
	sort(s, s+3);
	if(s[0]+1 == s[1] && s[1]+1 == s[2]) return 100;
	
	return 0;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	
	cin >> m;
	while(m--){
		int x1, x2, x3;
		cin >> x1 >> x2 >> x3;
		ar = (ar + x1) % n;
		br = (br + x2) % n;
		cr = (cr + x3) % n;
		ans += pend();
	}
	
	cout << ans;
}