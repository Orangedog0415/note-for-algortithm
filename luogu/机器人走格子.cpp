#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct info{
    int x, y;
    int cost;
    int diridx;
};

int s[55][55];//square
int p[55][55];//point
int n, m;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

void dfs(int x, int y, int desx, int desy, int cost, int diridx){
    //1边界返回
    //2到达返回
    //循环，
}

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

    queue<info> q;
    
}