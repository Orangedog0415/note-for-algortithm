# 约瑟夫环
#### 题目描述

n 个人围成一圈，从第一个人开始报数,数到 m 的人出列，再由下一个人重新从 1 开始报数，数到 m 的人再出圈，依次类推，直到所有的人都出圈，请输出依次出圈人的编号。

#### 输入格式

输入两个整数 n,m。
#### 输出格式

输出一行 n 个整数，按顺序输出每个出圈人的编号。
#### 说明/提示

1≤m,n≤100
#### code
```cpp
    auto it = L.begin();

    while(L.size() > 1){

        for(int i = 1; i < m; i++){

            it++;

            if(it == L.end()) it = L.begin();

        }

        cout << *it << ' ';

        it = L.erase(it);

        if(it == L.end()) it = L.begin();

    }

    cout << *L.begin();
```

# 插入删除


