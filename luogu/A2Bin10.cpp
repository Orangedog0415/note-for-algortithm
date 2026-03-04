#include <iostream>
#include <vector>
using namespace std;

vector<string> vecA, vecB;

void dfs(string a, string b, int step){
    if(step > 10) return;

    

}

int main(){
    string A, B;
    cin >> A >> B;

    string Ai, Bi;
    while(cin >> Ai >> Bi){
        vecA.push_back(Ai);
        vecB.push_back(Bi);
    }

    dfs(A, B, 0);
}