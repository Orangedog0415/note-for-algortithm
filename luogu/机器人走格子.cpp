#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct info{
    int x, y;
    int cost;
    int diridx;
};

int charToDir(char c) {
    if (c == 'S') return 0;
    if (c == 'E') return 1;
    if (c == 'N') return 2;
    if (c == 'W') return 3;
    return 0;
}

int p[55][55];//point
int n, m;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};
//0123:x+,y+,x-,y-

bool vis[55][55][4];

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
    dir = charToDir(d);

    queue<info> q;
    int ans = -1;
    info start = {stax, stay, 0, dir};
    q.push(start);
    vis[stax][stay][dir] = 1;

    while(q.size()){
        info t = q.front(); q.pop();
        
        if(t.x <= 0 || t.y <= 0 || t.x >= n || t.y >= m) continue;

        if(t.x == desx && t.y == desy){
            ans = t.cost;
            break;
        }

        for(int i = 1; i <= 3; i++){
            info s = t;
            int nx = t.x + i*dirx[t.diridx], ny = t.y + i*diry[t.diridx];
            if(p[nx][ny] == 1) break;
            s.x = nx, s.y = ny;
            s.cost++;

            if(s.x > 0 && s.y > 0 && s.x < n && s.y < m){
                if(!vis[s.x][s.y][s.diridx]){
                    q.push(s);
                    vis[s.x][s.y][s.diridx] = 1;
                }
            }
        }

        info sdl = t;
        sdl.diridx = (sdl.diridx + 1) % 4;
        sdl.cost++;
        if(sdl.x > 0 && sdl.y > 0 && sdl.x < n && sdl.y < m){
            if(!vis[sdl.x][sdl.y][sdl.diridx]){
                q.push(sdl);
                vis[sdl.x][sdl.y][sdl.diridx] = 1;
            }
        }

        info sdr = t;
        sdr.diridx = (sdr.diridx + 3) % 4;
        sdr.cost++;
        if(sdr.x > 0 && sdr.y > 0 && sdr.x < n && sdr.y < m){
            if(!vis[sdr.x][sdr.y][sdr.diridx]){
                q.push(sdr);
                vis[sdr.x][sdr.y][sdr.diridx] = 1;
            }
        }
        
    }

    std::cout << ans;
    
}