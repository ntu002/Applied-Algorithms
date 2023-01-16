//Range Minimum Query
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int maxx = 1e6 + 6;

int n, m;
int a[maxx];
int b[35][maxx];

int rmq(int i, int j) {
    int k = log2(j-i+1);
    int p2k = (1 << k);
    if (a[b[k][i]] <= a[b[k][j-p2k+1]]) {
        return b[k][i];
    } else return b[k][j-p2k+1];

}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];

    for (int j = 0; (1 << j) <= n; ++j)
        for(int i = 0; i < n; ++i) b[j][i] = -1;

    for(int i = 0; i < n; ++i) b[0][i] = i;

    for(int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            if (a[b[j-1][i]] < a[b[j-1][i+ (1 << (j-1))]]) b[j][i] = b[j-1][i]; 
                else b[j][i] = b[j-1][i+ (1 << (j-1))];
        }
    }

    long long Res = 0;

    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        Res += a[rmq(x,y)];
    }

    cout << Res;

    return 0;
}