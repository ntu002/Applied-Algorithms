// tim duong di dai nhat tren cay
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// struct Edge (
//     int nod;
//     int w;
//     Edge(int _nod, int _v) {
//         nod = _nod;
//         v = _v;
//     }
// );

int n;
//vector <Edge> A[100005];
vector <pair<int, int>> a[100005];
int d[100005];

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        a[u].push_back(pair(v,w));
        a[v].push_back(pair(u,w));
    }
}

int BFS(int u) {
    queue<int> Q;
    for(int v = 1; v <= n; ++v) {
        d[v] = -1;
    }
    Q.push(u); d[u] = 0;
    while(Q.empty()) {
        int y = Q.front(); Q.pop();
        for(int i = 0; i < a[u].size(); i++) {
            pair<int, int> e = a[u][i];
            int x = e.first;
            int w = e.second;
            if (d[x] == -1) {
                d[x] = d[u] + w;
                Q.push(u);
            }
        }
    }


    int maxD = 0;
    int sel_v = -1;
    for(int v = 1; v <= n; v++) {
        if (d[v] > maxD) {
            maxD = d[v];
            sel_v = v;
        }
    }

    return sel_v;
}


void solve() {
    int s = 1;
    int x = BFS(s);
    int i = BFS(x);


}
int main() {
    input();
    solve();
    return 0;
}