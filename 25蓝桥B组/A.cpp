#include <bits/stdc++.h>
using namespace std;

int main(){
    double r = sqrt(233*233 + 666*666);
    double theta = asin(666/r);
    
    double ans = r + theta*r;
    double R = ans - (int)ans;
    if(R > 0.5) cout << (int)ans + 1;
    else cout << (int)ans;
}