# 后缀表达式
#### 题目描述

所谓后缀表达式是指这样的一个表达式：式中不再引用括号，运算符号放在两个运算对象之后，所有计算按运算符号出现的顺序，严格地由左而右新进行（不用考虑运算符的优先级）。

本题中运算符仅包含 +-*/。保证对于 / 运算除数不为 0。特别地，其中 / 运算的结果需要**向 0 取整**（即与 C++ `/` 运算的规则一致）。

如：3*(5-2)+7 对应的后缀表达式为：3.5.2.-*7.+@。在该式中，`@` 为表达式的结束符号。`.` 为操作数的结束符号。

#### 输入格式

输入一行一个字符串 s，表示后缀表达式。

#### 输出格式

输出一个整数，表示表达式的值。
#### code
```cpp
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
```
# 表达式括号匹配
#### 题目描述

假设一个表达式有英文字母（小写）、运算符（`+`、`-`、`*`、`/`）和左右小（圆）括号构成，以 `@` 作为表达式的结束符。请编写一个程序检查表达式中的左右圆括号是否匹配，若匹配，则输出 `YES`；否则输出 `NO`。表达式长度小于 255，左圆括号少于 20 个。

#### 输入格式

一行：表达式。

#### 输出格式

一行：`YES` 或 `NO`。
#### code
```cpp
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
```
# 表达式求值
#### 题目描述

给定一个只包含加法和乘法的算术表达式，请你编程计算表达式的值。

#### 输入格式

一行，为需要你计算的表达式，表达式中只包含数字、加法运算符 `+` 和乘法运算符 `*`，且没有括号，所有参与运算的数字均为 0 到 231−1 之间的整数。

输入数据保证这一行只有 `0123456789+*` 这 12 种字符。

#### 输出格式

一个整数，表示这个表达式的值。

注意：当答案长度多于 4 位时，请只输出最后 4 位，前导 0 不输出。

#### code
```cpp
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
```