// longest common Subsequence

//Longest Common Subsequence
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6 + 6;
const int MAXn = 1e4 + 3;
int n, m;
int a[MAX], b[MAX];
int s[MAXn][MAXn];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    for (int i = 1; i <= n; ++i) s[i][0] = 0;
    for (int i = 1; i <= m; ++i) s[0][i] = 0;

    for (int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) {
            if (a[i] == b[j]) {
                s[i][j] = s[i-1][j-1] + 1;
            } else s[i][j] = max(s[i-1][j], s[i][j-1]);
        }
    cout << s[n][m];
    return 0;

}