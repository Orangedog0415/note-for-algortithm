#include <iostream>
#include <cstring>
using namespace std;

int a[5][5];
int ans = 0;

bool ok(){
    //1、扫描行
    for(int i = 0; i < 5; i++){
        int r = a[i][0];
        if(a[i][1] == r && a[i][2] == r && a[i][3] == r && a[i][4] == r) return false;
    }

    //2、扫描列
    for(int i = 0; i < 5; i++){
        int c = a[0][i];
        if(a[1][i] == c && a[2][i] == c && a[3][i] == c && a[4][i] == c) return false;
    }

    //3、扫描对角线
    int center = a[2][2];
    if(a[0][0] == center && a[1][1] == center && a[3][3] == center && a[4][4] == center){
        return false;
    }
    if(a[0][4] == center && a[1][3] == center && a[3][1] == center && a[4][0] == center){
        return false;
    }

    //检测无误
    return true;
}

void MaskToMatrix(int mask){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            a[i][j] = mask & 1;
            mask = mask >> 1;
        }
    }
}

void dfs(int mask, int step, int pos){
    if(25 - pos < step) return; 
    if(step == 0){
        int final_mask = mask << (25 - pos);
        MaskToMatrix(final_mask);
        if(ok()) ans++;
        return;
    }

    dfs(mask << 1 | 1, step-1, pos+1);
    dfs(mask << 1, step, pos+1);
}

int main(){
    dfs(0, 13, 0);

    cout << ans;
}