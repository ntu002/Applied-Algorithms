// Inter City Bus System

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 5005;
int n, m;
int c[MAX], d[MAX];
int dist[MAX];
vector <int> a[MAX];
bool f[MAX];
int w[MAX][MAX];

void BFS(int u) {
    queue <int> q;

    for(int i = 1; i <= n; ++i) dist[i] = -1;

    dist[u] = 0; q.push(u);

    while(!q.empty()) {
        int v = q.front(); q.pop();
        w[u][v] = c[u];
        for(int i = 0 ; i < a[v].size(); ++i) {
            int t = a[v][i];
            if (dist[t] >= 0) continue;
            dist[t] = dist[v] + 1;
            if (dist[t] <= d[u]) q.push(t);
        }
    }
}

void dijkstra(int s, int t) {
    for(int v = 1; v <= n; ++v) {
        dist[v] = w[s][v]; 
        f[v] = false;
    }

    dist[s] = 0;
    f[s] = false;

    for(int i = 1; i <= n; ++i) {
        int u = -1;
        int minD = 1e9;

        for(int v = 1; v <= n; ++v) 
            if(!f[v]) {
                if (dist[v] < minD) {
                    u = v;
                    minD = dist[v];
                }
            }
        
        f[u] = true;

        if (u == t) break;
        for(int v = 1; v <= n; ++v)
            if (!f[v]) {
                if (dist[v] > dist[u] + w[u][v]) {
                    dist[v] = dist[u] + w[u][v];
                }
            }
    }

    cout << dist[t];
}

void Solve() {
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= n; ++j) w[i][j] = 1e9;
    
    for(int i = 1; i <= n; ++i) BFS(i);

    dijkstra(1,n);

}

int main() {
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; ++i) {
        cin >> c[i] >> d[i];
    }

    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    Solve();

    return 0;
}