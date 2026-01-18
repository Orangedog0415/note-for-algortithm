#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int p[1010];

int n, m;

struct edge{
    int a, b;
    ll w;

    bool operator <(edge E){
        return w < E.w;
    } 
}e[100010];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;

    for(int i = 0; i < m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {a, b ,w};
    }
    sort(e, e + m);

    ll cnt = 0, res = 0;
    for(int i = 0; i < m; i++){
        ll a = e[i].a, b = e[i].b, w = e[i].w;
        a = find(a), b = find(b);
        //此处要把p[a]p[b]设置成根节点，这样链接才是正确的
        //否则只是随意的叶子节点相连会find不回去
        if(a != b){
            res = max(res, w);
            cnt++;
            p[a] = b;
        }
    }

    if(cnt < n - 1) cout << -1;
    else cout << res;
}