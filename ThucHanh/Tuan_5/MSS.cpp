// Make Span Schedule

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
#include <string.h>
#include <string.h>

using namespace std;
const int MAXn = 1e4+4;
int n, m;
int res;
int d[MAXn]; // d[i] = x: dinh i se thuc hien sau x dinh
int x[MAXn];
vector<int> L; // danh sach TOPO cac nut cua G
    // TOPO: Thứ tự Tô-pô của một đồ thị có hướng 
    // là một thứ tự sắp xếp của các đỉnh sao cho 
    // với mọi cung từ đỉnh 𝑢 đến đỉnh 𝑣 trong đồ thị, 
    // 𝑢 luôn nằm trước 𝑣
vector <pair<int, int> > a[MAXn];
int f[MAXn];
    // f[u]: thoi diem som nhat ma nhiem vu u co the bat dau.

void topo() {
    queue<int> q;

    for(int i = 1; i <= n; ++i)
        if (x[i] == 0) q.push(i);

    // q = {4, 7}
    while ((!q.empty())) {
        int t = q.front(); q.pop();
        //cout << t << " ";

        L.push_back(t);

        for(int i = 0; i < a[t].size(); ++i) {
            int y = a[t][i].first;

            //cout << y << " " << x[y] << endl;
            
            x[y] -= 1;
            if (x[y] == 0) q.push(y);
        }
    }

    // cout << endl;
    // cout << L.size();
}

// res = max(res, f[u] + d[u])
// f[v] = max(f[v], f[u] + d[u])

void Solve() {
    memset(f, 0, sizeof f);
    res = 0;

    for(int i = 0; i < L.size(); ++i) {
        //cout << L[i] << " ";
        int u = L[i];
        res = max(res, f[u] + d[u]);

        for(int j = 0; j < a[u].size(); ++j) {
            int v = a[u][j].first;
            int w = a[u][j].second;

            f[v] = max(f[v], f[u] + w);
        }
    }
}

int main() {

    memset(x, 0, sizeof x);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> d[i];

    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;

        a[u].push_back(make_pair(v, d[u]));
        x[v]++;
    }

    topo();
    Solve();

    cout << res;

    return 0;
}