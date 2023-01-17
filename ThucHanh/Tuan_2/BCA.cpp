// balanced course assignment 
// AC 100/100
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int m, n;
vector<int> T[50];
bool conflict[50][50];
int res;
int x[50];
int load[50];

bool check (int t, int k) {
    for(int i = 1; i <= k-1; ++i) {
        if (conflict[i][k] && x[i] == t) return false;
    }
    return true;
}

void solution() {
    int maxLoad = 0;
    for (int i = 1; i <= m; ++i) {
        maxLoad = max(maxLoad, load[i]);
    }
    if (maxLoad < res) res = maxLoad;

}

void Try(int k) {
    for (int i = 0; i < T[k].size(); ++i) {
        int t = T[k][i]; // giao vien
        if (check(t, k)) {
            x[k] = t; // mon hoc k do co t phu trach
            load[t] ++;
            if (k == n) solution();
            else {
                if (load[t] < res) Try(k+1);
            }
            load[t]--;
        }

    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        int k;
        cin >> k;
        for(int j = 1; j <= k; ++j) {
            int c;
            cin >> c;
            T[c].push_back(i);
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) conflict[i][j] = false;

    int K;
    cin >> K;
    for(int i = 1; i <= K; ++i) {
        int x,y;
        cin >> x >> y;
        conflict[x][y] = true;
        conflict[y][x] = true;
    }
    res = 1e9;
    Try(1);

    cout << res;

    return 0;
}