#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
int a[1000010];
int f[1000010][3];
//f[i][j]表示把1~i变为非递减的、结尾是j-1的最小操作次数

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    memset(f, 0x3f, sizeof f);
    f[1][a[1] + 1] = 0;

    for(int i = 2; i <= n; i++){
        if(a[i] == -1){
            f[i][0] = f[i-1][0];
            f[i][2] = f[i-1][2] + 2;
        }
        else if(a[i] == 0){
            f[i][0] = f[i-1][0] + 1;
            f[i][1] = min(f[i-1][0], f[i-1][1]);
            f[i][2] = f[i-1][2] + 1;
        }
        else{//(a[i] == 1)
            f[i][0] = f[i-1][0] + 2;
            f[i][1] = f[i-1][0] + 1;
            f[i][2] = min(f[i-1][0], min(f[i-1][1], f[i-1][2]));
        }
    }

    int ans = min(f[n][0], min(f[n][1], f[n][2]));
    if(ans >= INF) cout << "BRAK";
    else cout << ans;
}