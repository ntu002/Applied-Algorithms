//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstring>

#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAXn = 25;
const int MAX = 1e6 + 9;  

int n, a[MAXn][MAXn];
int dp[MAX][MAXn];
int res;

// S -> Start of tour 
// u -> diem bat dau
int tsp(int S, int u) {
    // xet het tat ca cac truong hop
    // (1<<n) = 2^n; -> dich sang trai n lan
    if (S == (1<<n) - 1) return a[u][0];
    // dp[S][u] != INF -> da co gia tri
    if (dp[S][u] != INF) return dp[S][u];
    for (int v = 0; v < n; v++) {
        // & -> AND
        if (!(S & (1<<v))) {
            dp[S][u] = min(dp[S][u], a[u][v] + tsp(S|(1<<v), v)); // | -> OR
        }
    }
    return dp[S][u];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    res = 0;

    memset(dp, 0x3f, sizeof dp);
    res = tsp(1,0);

    // for (int i = 1; i <= (1<<n) - 1; ++i) {
    //     for(int j = 0; j < n; ++j) cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    cout << res << endl;
    return 0;
}