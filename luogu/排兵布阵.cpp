#include <iostream>
#include <algorithm>
using namespace std;

int s, n, m;
int a[110][110];
int f[110][20010];
//f[i][j]代表攻占前i座城堡使用j个兵能获得的最大值

int main(){
    cin >> s >> n >> m;
    for(int i = 1; i <= s; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[j][i];
        }
    }
    for(int i = 1; i <= n; i++){
        sort(a[i] + 1, a[i] + 1 + s);
    }

    for(int i = 1; i <= n; i++){
        for(int j = m; j >= 0; j--){
            f[i][j] = f[i-1][j]; 

            for(int k = 1; k <= s; k++){
                if(j - a[i][k]*2 - 1 >= 0)
                    f[i][j] = max(f[i][j], f[i - 1][j - a[i][k]*2 - 1] + k*i);
            }
        }
    }

    cout << f[n][m];
}