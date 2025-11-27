#include <iostream>
#include <list>
using namespace std;

list<int> L;
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        int in; cin >> in;
        L.push_back(in);
    }

    auto it = L.begin();
    while(L.size() > 1){
        for(int i = 1; i < m; i++){
            it++;
            if(it == L.end()) it = L.begin();
        }
        cout << *it << ' ';
        it = L.erase(it);
        if(it == L.end()) it = L.begin();
    }
    cout << *L.begin();
}