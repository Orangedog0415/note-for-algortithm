#include <iostream>
#include <stack>
using namespace std;

const int MOD = 10000;

int main(){
    int a; cin >> a; a%=MOD;
    stack<int> st; st.push(a);
    int b; char op;
    while(cin >> op >> b){
        if(op == '*'){
            a = st.top(); st.pop();
            st.push(a*b%MOD);
        }
        else{
            st.push(b);
        }
    }
    int sum = 0;
    while(!st.empty()){
        sum = (sum + st.top())%MOD;
        st.pop();
    }
    cout << sum;
}