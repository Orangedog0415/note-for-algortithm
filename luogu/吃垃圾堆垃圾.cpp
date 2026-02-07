#include <iostream>
#include <algorithm>
using namespace std;

struct trash{
    int t, f, h;

    bool operator < (const trash Trash){
        return t < Trash.t;
    }
}Trash[110];


int dp[110];
//dp[height] = life
//对于Trash[i] = {ti, fi, hi}
/*
dp[j] += fi;
dp[j + hi] = max(dp[j + hi], dp[j])
*/

int D, G;

int main(){
    cin >> D >> G;
    for(int i = 1; i <= G; i++){
        int t, f, h; cin >> t >> f >> h;
        Trash[i] = {t, f, h};
    }
    sort(Trash + 1, Trash + 1 + G);

    dp[0] = 10;
    //①初始化
    for(int i = 1; i <= G; i++){
        for(int j = D; j >= 0; j--){
            int t = Trash[i].t, f = Trash[i].f, h = Trash[i].h;
            if(dp[j] - t >= 0){
                if(j + h >= D){
                    cout << t;
                    //②掉落时刻即为逃脱时刻
                    return 0;
                }
                dp[j + h] = max(dp[j + h], dp[j]);
                //③必须先用未更新的dp[j]来更新dp[j + h]
                dp[j] += f;
            }
        }
    }

    cout << dp[0];
}