#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

vector<string> vecA, vecB;
int sz;

int dfs(string a, string b, int step){
    if(step > 10) return 11;

    if(a == b) return step;

    int ans = 11;
    for(int i = 0; i < sz; i++){
        size_t pos = a.find(vecA[i]);
        if(pos != string::npos){
            a.replace(pos, vecA[i].length(), vecB[i]);
            ans = min(dfs(a, b, step+1), ans);
            a.replace(pos, vecB[i].length(), vecA[i]);
        }
    }

    return ans;
}

int main(){
    string A, B;
    cin >> A >> B;

    string Ai, Bi;
    while(cin >> Ai >> Bi){
        vecA.push_back(Ai);
        vecB.push_back(Bi);
    }

    sz = (int)vecA.size();
    queue<pair<string, int>> q;
    unordered_set<string> st;

    q.push({A, 0});
    st.insert(A);
    while(q.size()){
        auto t = q.front(); q.pop();
        string a = t.first;
        int cost = t.second;

        if(cost >= 10) continue;

        for(int i = 0; i < sz; i++){
            size_t pos = 0;

            while((pos = a.find(vecA[i], pos)) != string::npos){
                string cur = a;
                cur.replace(pos, vecA[i].length(), vecB[i]);

                if(cur == B){
                    cout << cost + 1;
                    return 0;
                }

                if(st.find(cur) == st.end()){
                    q.push({cur, cost + 1});
                    st.insert(cur);
                }

                pos++;
            }
        }
    }

    cout << "NO ANSWER!";
}