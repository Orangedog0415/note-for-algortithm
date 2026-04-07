#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, n;

int main(){
    cin >> a >> b >> n;

    ll pack = 5*a + 2*b;
    ll week = n / pack;
    ll res = n % pack;

    for(int i = 1; i <= 5; i++){
        res -= a;
        if(n <= 0){
            cout << i + 7*week;
            return 0;
        }
    }
    for(int i = 6; i <= 7; i++){
        res -= b;
        if(n <= 0){
            cout << i + 7*week;
            return 0;
        }
    }
}