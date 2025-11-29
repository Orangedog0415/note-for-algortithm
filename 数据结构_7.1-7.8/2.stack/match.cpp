#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s; cin >> s;
    stack<char> st;

    for(auto& c : s){
        if(c == '(') st.push(c);
        if(c == ')'){
            if(!st.empty() && st.top() == '('){
                st.pop();
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    if(st.empty()){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}