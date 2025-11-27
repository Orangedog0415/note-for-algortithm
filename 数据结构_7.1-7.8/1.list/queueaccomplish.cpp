#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
using iter = list<int>::iterator;

int n, m;
iter pos[100010];
list<int> L;
bool erased[100010];

int main(){
    cin >> n;
    L.push_back(1);
    pos[1] = L.begin();
    for(int i = 2; i <= n; i++){
        int k, op; cin >> k >> op;
        if(op == 0){
            pos[i] = L.insert(pos[k], i);
        }
        else{
            auto it = pos[k];
            it++;
            pos[i] = L.insert(it, i);
        }
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        if(!erased[x]){
            L.erase(pos[x]);
            erased[x] = true;
        }
    }
    for(auto& v : L){
        cout << v << ' ';
    }
}