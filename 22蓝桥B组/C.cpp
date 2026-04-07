#include <bits/stdc++.h>
using namespace std;

const int N = 10010;
int n;

int main(){
    cin >> n;
    int e = 2*(n-1);

    for(int i = 1; i < n/2; i++){
        cout << e << '\n';
        e -= 2;
    }
    cout << e << '\n';
    if(n%2 == 0) cout << e << '\n';
    for(int i = 1; i < n/2; i++){
        e += 2;
        cout << e << '\n';
    }
}