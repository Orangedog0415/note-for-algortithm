#include <bits/stdc++.h>
using namespace std;

int h, w;
int a[4] = {2, 0, 2, 5};

int main(){
	cin >> h >> w;
	
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			int val = a[(i+j)%4];
			cout << val;
		}
		cout << '\n';
	}
}