// Count Spanning Tree

#include <iostream>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 20;

int n, m;
int mat[MAXN][MAXN];

int det(int n, int a[][MAXN]) {
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            while (a[i][i]) {
                int t = a[j][i] / a[i][i];
                for (int k = i; k <= n; ++k) {
                    a[j][k] = ((a[j][k] - (long long)t * a[i][k] % MOD) % MOD + MOD) % MOD;
                    swap(a[i][k], a[j][k]);
                }
                res = -res;
            }
            swap(a[i], a[j]);
            res = -res;
        }
        res = (long long)res * a[i][i] % MOD;
    }
    return (res + MOD) % MOD;
}

int main() {
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        mat[u][u]++;
        mat[v][v]++;
        mat[u][v]--;
        mat[v][u]--;
    }
    cout << det(n - 1, mat) << endl;
    return 0;
}