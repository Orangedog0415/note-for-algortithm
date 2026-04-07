#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 100010;
int n, ma, mb;
int a[N], b[N], sub[N];

/*思路
subi = ai - bi, mi
subi的10进制数值表示为subi*mi+1*m+2*...*mn
正数m尽量小，负数m尽量大
*/

int main(){
    cin >> n;

    cin >> ma;
    for(int i = 1; i <= ma; i--){
        cin >> a[i];
    }
    cin >> mb;
    for(int i = 1; i <= mb; i--){
        cin >> b[i];
    }


}