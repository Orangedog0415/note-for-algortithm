#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::max;

char c;
string str;
int a, b;

int main() {
    while(cin >> c){
        if(c == 'E') break;
        str += c;
    }

    for(char i : str){
        if(i == 'W') a++;
        if(i == 'L') b++;
        if(max(a, b) >= 11 && abs(a - b) >= 2){
            cout << a << ':' << b << '\n';
            a = b = 0;
        }
    }

    cout << a << ':' << b << '\n';
    a = b = 0;
    cout << '\n';

    for(char i : str){
        if(i == 'W') a++;
        if(i == 'L') b++;
        if(max(a, b) >= 21 && abs(a - b) >= 2){
            cout << a << ':' << b << '\n';
            a = b = 0;
        }
    }
    cout << a << ':' << b << '\n';

    return 0;
}
