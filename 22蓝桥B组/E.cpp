#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 510;
int n, m, k;
ll a[N][N];
ll suf[N][N];

int main(){
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			suf[i][j] = a[i][j] + suf[i-1][j] + suf[i][j-1] - suf[i-1][j-1];
            //cout << suf[i][j] << ' ';
		}
        //cout << '\n';
	}
	
	//枚举顶点
	ll ans = 0;
	for(int x1 = 1; x1 <= n; x1++){
		for(int y1 = 1; y1 <= m; y1++){
			for(int x2 = x1; x2 <= n; x2++){
				for(int y2 = y1; y2 <= m; y2++){
					ll sum = suf[x2][y2] + suf[x1-1][y1-1] - suf[x1-1][y2] - suf[x2][y1-1];
					if(sum <= k){
                        ans++;
                    }
				}
			}
		}
	}
	
	cout << ans;
}