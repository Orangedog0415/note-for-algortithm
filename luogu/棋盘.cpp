#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;

int m, n;
int a[110][110];        // 地图颜色：0红，1黄，2无色
int min_cost[110][110]; // 记录到达某点的最小花费，用于剪枝
int dx[4] = {0, 0, 1, -1}; // 方向数组
int dy[4] = {1, -1, 0, 0};

// x, y: 当前坐标
// cost: 到达当前坐标的花费
// is_magic: 当前这一步是否使用了魔法（如果用了，下一步不能再用）
// curr_color: 当前格子的颜色（如果是魔法格子，这里存的是变色后的颜色）
void dfs(int x, int y, int cost, bool is_magic, int curr_color) {
    // 1. 越界检查
    if(x < 1 || y < 1 || x > m || y > m) return;

    // 2. 剪枝：如果当前花费已经比之前找到的路径更贵或相等，就没必要继续走了
    if(cost >= min_cost[x][y]) return;
    
    // 更新到达该点的最小花费
    min_cost[x][y] = cost;

    // 3. 尝试向四个方向移动
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 越界预检查
        if(nx < 1 || ny < 1 || nx > m || ny > m) continue;

        if(a[nx][ny] != 2) { 
            // 情况A：下个格子有颜色
            // 如果颜色相同花费0，不同花费1
            int extra = (a[nx][ny] == curr_color) ? 0 : 1;
            // 走到有色格子，魔法状态重置为false，颜色为下个格子原本的颜色
            dfs(nx, ny, cost + extra, false, a[nx][ny]);
        } 
        else { 
            // 情况B：下个格子无色
            if(!is_magic) { 
                // 只有当前没用魔法，下个格子才能用魔法
                // 策略：为了省钱，我们把下个无色格子变成和当前格子一样的颜色
                // 这样移动花费为0，但魔法花费为2。总共增加2。
                // 此时下个格子的临时颜色就是 curr_color
                dfs(nx, ny, cost + 2, true, curr_color);
            }
            // 如果 is_magic 为 true，则不能走到无色格子，直接跳过
        }
    }
}

int main(){
    cin >> m >> n;
    
    // 初始化地图为无色
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] = 2; 
        }
    }
    
    // 读入有颜色的格子
    for(int i = 0; i < n; i++){
        int x, y, c; 
        cin >> x >> y >> c;
        a[x][y] = c;
    }

    // 初始化最小花费数组为无穷大
    memset(min_cost, 0x3f, sizeof(min_cost));

    // 从(1,1)开始搜，当前花费0，没用魔法，颜色是起点原本的颜色
    dfs(1, 1, 0, false, a[1][1]);

    // 输出结果
    if(min_cost[m][m] == INF) 
        cout << -1 << endl;
    else 
        cout << min_cost[m][m] << endl;

    return 0;
}