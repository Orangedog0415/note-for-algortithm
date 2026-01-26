#include <iostream>
#include <algorithm>
using namespace std;

struct Milk{
    int p, a;
    //p是单价，a是产量

    bool operator < (const Milk m){
        return p < m.p;
    }
}milk[5010];

int n, m;

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> milk[i].p >> milk[i].a;
    }
    sort(milk, milk + m);

    long long res = 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int a = milk[i].a, p = milk[i].p;
        int need = n - cnt;
        if(need >= a){
            cnt += a;
            res += 1LL * p * a;
        }
        else{
            res += 1LL * p * need;
            break;
        }
    }

    cout << res;
}