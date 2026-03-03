#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct info{
    int x, y;
    int cost;
    int diridx;
};

enum Direction{
    S = 0, E = 1, N = 2, W = 3
};

int s[55][55];//square
int p[55][55];//point
int n, m;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};
//0123:x+,y+,x-,y-

//void dfs(int x, int y, int desx, int desy, int cost, int diridx){
    //1边界返回
    //2到达返回
    //循环，
//}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int in; cin >> in;
            if(in){
                p[i][j] = p[i+1][j] =
                p[i][j+1] = p[i+1][j+1] = 1;
            }
        }
    }

    int stax, stay, desx, desy, dir;
    char d;
    cin >> stax >> stay >> desx >> desy >> d;
    dir = (Direction)d;

    queue<info> q;
    int ans = 0;
    info start = {stax + 1, stay + 1, 0, dir};
    q.push(start);
    while(q.size()){
        info t = q.front(); q.pop();
        
        if(t.x < 0 || t.y < 0 || t.x > n || t.y > m) continue;

        if(t.x == desx + 1 && t.y == desy + 1){
            ans = t.cost;
            break;
        }

        for(int i = 1; i <= 5; i++){
            info s;
            if(1 <= i && i <= 3){
                s = {t.x + i*dirx[t.diridx], t.y + i*diry[t.diridx], t.cost, t.diridx};
            }
            else if(i == 4){
                s = t;
                s.diridx = (s.diridx + 1) % 4;
            }
            else{
                s = t;
                s.diridx = (s.diridx + 3) % 4;
            }
            s.cost++;
            if(s.x >= 0 && s.y >= 0 && s.x <= n && s.y <= m){
                q.push(s);
            }
        }
    }

    cout << ans;
    
}