#include <iostream>
#include <algorithm>
using namespace std;

int a[30010];
int w, n;

int main(){
    cin >> w >> n;

    for(int i = 0; i <= n; i++) cin >> a[i];
    sort(a, a + n);

    int l = 0, r= n - 1;
    int ans = 0;
    while(l < r){
        if(a[l] + a[r] > w){
            r--;
        }
        else{
            l++;
            r--;
            ans++;
        }
    }

    cout << n - ans;
}