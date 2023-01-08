#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int N = 1e5;
int n, m;
vector <int> A[N];
int d[N];


bool BFS(int s) {
    queue<int> Q;
    d[s] = 0; Q.push(s);
    while (Q.empty()) {
        int v = Q.front(); Q.pop();
        for(int i = 0; i < A[v].size(); i++) {
            if (d[A[v][i]] > -1)  {
                if (d[v] + d[A[v][i]] % 2 == 0) return false;
            } else {
                Q.push(A[v][i]);
                d[A[v][i]] = d[v] + 1; 
            }
        }
    }
    return true;
}


int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u,v;
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }


    for (int v = 1; v <= n; ++v) d[v] = -1;
    int ans = 1;
    bool OK = true;
    for (int v = 1; v <= n; ++v) {
        if (OK) {
            OK = BFS(v); 
        } else ans = 0;
    }

    cout << ans;
    return 0;

}