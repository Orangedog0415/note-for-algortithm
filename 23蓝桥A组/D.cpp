#include <bits/stdc++.h>
using namespace std;

int ans = 0;
bool dp[5010][5010];

int main(){
    string s;
    cin >> s;
    int n = (int)s.size();

    for(int len = 2; len <= n; len++){
        for(int l = 0; l < n; l++){
            int r = l + len - 1;
            if(r >= n)  break;

            if(s[l] > s[r]) {
                dp[l][r] = 1;
                ans++;
            } else if(s[l] == s[r]) {
                dp[l][r] = dp[l+1][r-1];
                if(dp[l][r]) ans++;
            } else {
                dp[l][r] = 0;
            }
        }
    }

    cout << ans;
}

/*
反转后更小
2.5*10e7，可以n2
对于当前查找的每一个子串[l, r](l<r)
i = l, j = r;
while(i < j){
    if(s[i] > s[j]) ok
    if(s[i] == s[j]) i++, j--;
    if(s[i] < s[j]) no
}
*/