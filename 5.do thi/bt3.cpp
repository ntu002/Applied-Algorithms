#include <iostream>
#include <algorithm>
#include <vector>

#define ii pair<int, int>

using namespace std;


const int MAX = 1e6 + 6;
const int MAXn = 1e3 + 3;
int n, m;
vector <ii> a[MAX];
int p[MAXn]; // p[i] = x -> cha cua i la x
int r[MAXn]; // r[i] = x -> do dai tu i den cha la x

int Find(int x) {
    if (p[x] = x) return x;
    p[x] = Find(p[x]);
    return p[x];
}

void Unify(int x, int y) {
    if (r[x] > r[y]) {
        p[y] = x;
    } else {
        if (r[x] < r[y]) {
            p[x] = y;
        } else {
            if (r[x] = r[y]) {
                r[x] = r[x] + 1;
            }
        }
    }
}

void MakeSet(int x) {
    p[x] = x;
    r[x] = 0;
}

bool cmp(ii x, ii y) {
    return x.second < y.second;

}

void Krustal() {
    sort(a, a + n, cmp);
    int w = 0;
    vector <>

}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u,v,t;
        cin >> u >> v >> t;
        a[u].push_back(pair(v,t));
        a[v].push_back(pair(u,t));
    }

    return 0;
}