#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2010;
const int MOD = 1e8;

int n, F;
int cow[N], f[N][N];
//f[i][j]：考虑前i头牛的余数为j的情况数

int main(){
    cin >> n >> F;
    for(int i = 1; i <= n; i++){
        cin >> cow[i];
        cow[i] %= F;
    }

    for(int i = 1; i <= n; i++) f[i][cow[i]] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < F; j++){
            f[i][j] = (f[i][j] + f[i-1][j] + f[i-1][(j-cow[i]+F)%F]) % MOD;
        }
    }

    cout << f[n][0];
}