#include <iostream>
#include <stack>
using namespace std;

string ex;

int main(){
    cin >> ex;

    stack<int> st;
    int num = 0;
    bool read = 0;

    for(auto c : ex){
        if(isdigit(c)){
            read = 1;
            num = num*10 + (c - '0');
        }
        else if(c == '.'){
            st.push(num); num = 0;
            read = 0;
        }
        else if(c == '@'){
            cout << st.top();
            return 0;
        }
        else{
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int res;

            if(c == '+') res = a + b;
            if(c == '*') res = a * b;
            if(c == '-') res = a - b;
            if(c == '/') res = a / b;

            st.push(res);
        }
    }
}