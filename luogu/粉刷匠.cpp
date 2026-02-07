#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t;
int a[55][55];

int main(){
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            char in; cin >> in;
            a[i][j] = in - '0';
        }
    }

    
}