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