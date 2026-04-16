#include <bits/stdc++.h>
using namespace std;

// 各月天数（2023 非闰年）
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static long long count_subseq(const vector<int>& digits, const string& target) {
    // dp[i] 表示：当前扫描到某位置时，构成 target 前 i 个字符的方案数
    vector<long long> dp(target.size() + 1, 0);
    dp[0] = 1;

    for (int x : digits) {
        char ch = char('0' + x);
        // 倒序转移，避免本轮字符被重复使用
        for (int j = (int)target.size() - 1; j >= 0; --j) {
            if (target[j] == ch) {
                dp[j + 1] += dp[j];
            }
        }
    }

    return dp[target.size()];
}

int main(){
    vector<int> digits;
    string token;
    // 兼容输入中有空格或连写数字的情况，只提取前 100 个数字
    while ((int)digits.size() < 100 && (cin >> token)) {
        for (char c : token) {
            if (isdigit((unsigned char)c)) {
                digits.push_back(c - '0');
                if ((int)digits.size() == 100) break;
            }
        }
    }

    long long ans = 0;
    // 枚举 2023 年所有合法日期，将 YYYYMMDD 作为目标串统计子序列出现次数
    for (int m = 1; m <= 12; ++m) {
        for (int d = 1; d <= month[m]; ++d) {
            string target = "2023";
            target += char('0' + m / 10);
            target += char('0' + m % 10);
            target += char('0' + d / 10);
            target += char('0' + d % 10);
            ans += count_subseq(digits, target);
        }
    }

    cout << ans;

    return 0;
}