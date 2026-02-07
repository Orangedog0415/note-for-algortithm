#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[110];
bool f[25010];

int main(){
    int T; cin >> T;
    while(T--){
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        
        cin >> n;
        int max_val = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            max_val = max(a[i], max_val);
        }
        sort(a, a + n);

        f[0] = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(f[a[i]]){
                ans++;
            }
            else{
                for(int j = a[i]; j <= max_val; j++){
                    f[j] |= f[j - a[i]];
                }
            }
        }

        cout << n - ans << '\n';
    }
}