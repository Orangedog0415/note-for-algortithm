/*
题目：
题目描述
小蓝正在平面直角坐标系中的第一象限里玩一个逃生小游戏，在第一象限 中埋有 n 颗地雷，第 i 颗地雷的坐标为 (xi , yi) ，触发范围为以 (xi , yi) 为圆心， 半径为 ri 的圆。一旦小蓝走进了圆内就会触发地雷导致游戏失败。小蓝初始在 原点 (0, 0) 上，他需要在第一象限内选择一个方向一直往前走，如果能不触发 任何地雷即可成功通关游戏。他想知道在 屏幕截图 2025-04-14 222816.png中均匀随机选择一个方向，即在 0 ◦ （朝向 x 轴正方向）至 90◦ （朝向 y 轴正方向）之间随机选择一个方向，通 关游戏的概率是多少？

输入格式
输入的第一行包含一个正整数 n 。 

接下来 n 行，每行包含三个正整数 xi , yi ,ri ，相邻整数之间使用一个空格分隔。

输出格式
输出一行包含一个实数，四舍五入保留三位小数，表示答案。

样例输入
1
2 2 1
样例输出
0.540
提示
【样例输入 2】 

2

1 3 1 

3 1 1

【样例输出 2】 

0.181

【评测用例规模与约定】 

对于 20% 的评测用例，1 ≤ n ≤ 100 ； 

对于所有评测用例，1 ≤ n ≤ 105 ，1 ≤ xi , yi ≤ 104 ，ri < min(xi , yi) 。
*/
/*
我的想法：
其实就是一个角度的区间覆盖
对于每一个圆算圆心到原点角度为轴，半径所能覆盖的角度(asin)
如果一边合并一边计算的话，复杂度是n2，会爆
所以我们选择全部计算完覆盖的区间后
按区间左端点排序
用on的线性贪心办法合并区间
设当前区间(l1, r1), 下一个区间(l2, r2)
若r1 > l2, 合并区间
else 存当前区间（直接相减得覆盖角度范围的值，加到res里面），以下一个区间为起点继续合并
这样的复杂度是on的
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<double, double>> intervals; // 存储每个地雷的覆盖角度区间
    for (int i = 0; i < n; i++) {
        double x, y, r;
        cin >> x >> y >> r;
        double angle = atan2(y, x); // 圆心到原点的角度
        double delta = asin(r / sqrt(x * x + y * y)); // 半径覆盖的角度范围
        intervals.emplace_back(angle - delta, angle + delta); // 存储区间
    }
    
    // 按区间左端点排序
    sort(intervals.begin(), intervals.end());
    
    double res = 0.0; // 记录覆盖的总角度范围
    double current_end = 0.0; // 当前合并区间的右端点
    
    for (const auto& interval : intervals) {
        if (interval.first > current_end) { // 如果当前区间与上一个合并区间不重叠
            res += interval.second - interval.first; // 加上当前区间的长度
            current_end = interval.second; // 更新当前合并区间的右端点
        } else if (interval.second > current_end) { // 如果当前区间与上一个合并区间部分重叠
            res += interval.second - current_end; // 加上未覆盖的部分
            current_end = interval.second; // 更新当前合并区间的右端点
        }
    }
    
    double probability = (M_PI / 2 - res) / (M_PI / 2); // 计算概率，除以90度对应的弧度值
    cout << fixed << setprecision(3) << probability << endl; // 输出结果，保留三位小数
    
    return 0;
}