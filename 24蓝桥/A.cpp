#include <iostream>
using namespace std;

static int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

bool is_runnian(int year){
    return ((year % 4 == 0) && !(year % 100 == 0)) || (year % 400 == 0);
}

int trans(int i){
    if(i == 0) return 13;
    if(i == 1) return 1;
    if(i == 2) return 2;
    if(i == 3) return 3;
    if(i == 4) return 5;
    if(i == 5) return 4;
    if(i == 6) return 4;
    if(i == 7) return 2;
    if(i == 8) return 2;
    if(i == 9) return 2;
    return 0;
}

int cal(int num){
    int cnt = 0;
    while(num){
        int i = num % 10;
        num /= 10;
        cnt += trans(i);
    }
    return cnt;
}

long long ans = 0;

void search(int y, int m, int d){
    int res = cal(10000*y + 100*m + d);
    if(res > 50) ans++;
}

int main(){
    for(int y = 2000; y <= 2024; y++){

        month[2] = is_runnian(y) ? 29 : 28;
        for(int m = 1; m <= 12; m++){

            int d_end = month[m];
            if(y == 2024 && m == 4) d_end = 13;
            for(int d = 1; d <= d_end; d++){
                search(y, m, d);
                if(y == 2024 && m == 4 && d == 13){
                    cout << ans;
                    return 0;
                }
            }
        }
    }
}