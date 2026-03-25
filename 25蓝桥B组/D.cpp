#include <iostream>

using namespace std;
using ll = long long;

int main() {
	ll t; cin >> t;
    while(t--){
        ll a, b, c, k;
        cin >> a >> b >> c >> k;
        while(k--){
            ll A, B, C;
            A = (b+c)/2;
            B = (a+c)/2;
            C = (a+b)/2;
            a = A, b = B, c = C;

            if(a == b && b == c) break;
        }
        cout << a << ' ' << b << ' ' << c << '\n'; 
    }
}
