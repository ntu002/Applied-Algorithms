// MAX_FLOW

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int MAXn = 1e6+6;
int n, m;
int s, t;
vector <int> a[MAXn];
int c[MAXn][MAXn];
int parent[MAXn];
int f[MAXn][MAXn];
int ans;

void input() {
    cin >> n >> m;
    cin >> s >> t;

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) c[i][j] = 0;
    }

    for(int i = 1; i <= m; ++i) {
        int u, v, t;
        cin >> u >> v >> t;

        a[u].push_back(v);
        c[u][v] = t;
    }
}

bool BFS() {
    queue <int> q;
    q.push(s);

    for(int i = 0; i < MAXn; ++i) parent[i] = 0;

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for(int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];

            if (parent[v] == 0) {
                bool ok = false;
                if (c[u][v] > 0) {
                    if (f[u][v] < c[u][v]) ok = true;
                } else {
                    if (f[u][v] > 0) ok = true;
                }

                if (ok) {
                    parent[v] = u; q.push(v);
                    if (v == t) return true;
                }
            }
        }
    }

    return false;
}

void Flow() {
    int u = t; int detal = 1e9;

    while(parent[u] != 0) {
        int pu = parent[u];
        if (c[pu][u] > 0) {
            detal = min(detal, c[pu][u] - f[pu][u]);
            detal = min(detal, f[u][pu]);
        }
        u = pu;
    }

    ans += detal;

    u = t;

    while(parent[u] != 0) {
        int pu = parent[u];
        if (c[pu][u] > 0) {
            f[pu][u] = f[pu][u] + detal;
        } else {
            f[u][pu] = f[u][pu] - detal;
        }

        u = pu;
    }

}

void Solve() {
    for (int u = 1; u <= n; ++u) {
        for(int i = 0; i < a[u].size(); ++i) {
            int v = a[u][i];
            if (c[u][v] > 0) f[u][v] = 0;
        }
    }

    ans = 0;
    while(true) {
        bool ok = BFS();

        if (!ok) break;
        Flow();
    }

    cout << ans;
}

int main() {

    input();
    Solve();
    return 0;
}