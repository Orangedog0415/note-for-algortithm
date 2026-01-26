#include <iostream>
#include <algorithm>
using namespace std;

int a[310];
int n;

long long pow(int h1, int h2){
    return 1LL * (h1 - h2) * (h1 - h2);
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    int l = 0, r = n;
    long long ans = 0;
    for(int cnt = 0; cnt <= n; cnt++){
        if(cnt % 2 == 0){
            ans += pow(a[l], a[r]);
            l++;
        }
        else if(cnt % 2 == 1){
            ans += pow(a[l], a[r]);;
            r--;
        }
    }

    cout << ans;
}