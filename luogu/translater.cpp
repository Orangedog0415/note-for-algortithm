#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int sum;
int q[1010], head = 0, rear = -1;


int main(){
    cin >> m >> n;
    int hash[1010] = {0};

    while(n--){
        int in; cin >> in;
        if(hash[in]) continue;
        if(!hash[in] && rear - head + 1 < m){
            hash[in] = 1;
            q[++rear] = in;
            sum++;
        }
        if(!hash[in] && rear - head + 1 >= m){
            hash[q[head++]] = 0;
            hash[in] = 1;
            q[++rear] = in;
            sum++;
        }
    }
    cout << sum;
}