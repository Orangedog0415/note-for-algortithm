#include <bits/stdc++.h>
using namespace std;

string a[2];
int ans;

int main(){
	cin >> a[0] >> a[1];
	int n = a[0].size();
	
	//bianli1
	vector<int> idx;
	for(int i = 0; i < n; i++){
		if(a[0][i] == '#' || a[1][i] == '#'){
			idx.push_back(i);
		}
	}
	
	//bianli2
	int m = idx.size();
	for(int i = 0; i < m - 1; i++){
		int l = idx[i], r = idx[i+1];
		if((a[0][l] == '#' && a[0][r] == '#') || 
			a[1][l] == '#' && a[1][r] == '#'){
				ans += r - l - 1;
		} else {
			ans += r - l;
			a[0][r] = a[1][r] = '#';
		}	
	}
	
	cout << ans;
}