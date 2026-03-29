#include <bits/stdc++.h>
using namespace std;

string dfs(int p){
    if(p == 1) return "RED";

    string fa = dfs(p << 1);
    if(fa == "RED"){
        if(p == (p/2*2)) return fa;
        else return "BLACK";
    }
    else{
        if(p == (p/2*2)) return fa;
        else return "RED";
    }
}

int main(){
    int m;
    cin >> m;
    while(m--){
        int n, k;
        cin >> n >> k;

        int p = (1 << (n-1)) + k - 1;
        string fa = "RED", ans = fa;
        stack<int> s;
        while(p != 1){
            s.push(p);
            p /= 2;
        }

        int pre = 1;
        while(!s.empty()){
            auto t = s.top(); s.pop();
            if(t == pre*2) ans = fa;
            else ans = (fa == "RED") ? "BLACK" : "RED";
            fa = ans;
            pre = t;
        }
        cout << ans << '\n';
    }
}