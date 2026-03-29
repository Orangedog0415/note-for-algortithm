#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, m;
int a[N], b[N], c[N];

int check(int ar, int br, int cr){
    int A = a[ar], B = b[br], C = c[cr];

    if(A == B && B == C) return 200;
    if(A == B || A == C || B == C) return 100;

    if(A+1 == B && B+1 == C) return 200;
    int arr[3] = {A, B, C};
    sort(arr, arr+3);

    if(arr[0]+1 == arr[1] && arr[1]+1 == arr[2]) return 100;
    return 0;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    int ans = 0;
    int ar = 0, br = 0, cr = 0;
    cin >> m;
    while(m--){
        int x, y, z;
        cin >> x >> y >> z;

        ar = (ar + x) % n;
        br = (br + y) % n;
        cr = (cr + z) % n;
        ans += check(ar, br, cr);
    }

    cout << ans;
}