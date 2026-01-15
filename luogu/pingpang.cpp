#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::string;

int main() {
    string whole, str;

    while (cin >> str) {
        whole += str;

        size_t pos = whole.find('E');
        if (pos != string::npos) {
            whole.resize(pos);
            break;   // 找到 E 就结束读取
        }
    }

    size_t pos = 0, length = whole.size();
    while(pos < length){
        unsigned int a = 0, b = 0, cnt = 0;
        while(pos < length && cnt < 11){
            if(whole[pos] == 'W') a++;
            else b++;
            pos++;
            cnt++;
        }
        cout << a << ':' << b << '\n';
    }

    cout << '\n';

    pos = 0;
    while(pos < length){
        unsigned int a = 0, b = 0, cnt = 0;
        while(pos < length && cnt < 21){
            if(whole[pos] == 'W') a++;
            else b++;
            pos++;
            cnt++;
        }
        cout << a << ':' << b << '\n';
    }

    return 0;
}
