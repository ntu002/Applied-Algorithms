// .Largest Black SubRectangle
// AC 100/100
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
const int maxx = 1e3 + 3;
int n, m;
int a[maxx][maxx];
int h[maxx]; // h[i] -> chieu cao cua cot i
int L[maxx], R[maxx]; 
    // L[i] -> vi tri dau tien o ben trai nho hon h[i]
    // R[i] -> vi tri dau tien o ben phai nho hon h[i]
int res;
int ans;

void Solve() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 0) h[j] = 0; else h[j] = h[j] + 1;
        }

        h[0] = -1; h[m+1] = -1;

        vector<int> V;
        for(int j = 1; j <= m+1; ++j) {
            while(!V.empty() && h[j] < h[V[V.size() - 1]]) {
                R[V[V.size() - 1]] = j;
                V.pop_back();
            }
            V.push_back(j);
        } 

        for(int j = m; j >= 0; --j) {
            while(!V.empty() && h[j] < h[V[V.size() - 1]]) {
                L[V[V.size() - 1]] = j;
                V.pop_back();
            }
            V.push_back(j);
        }

        res = 0;
        for(int j = 1; j <= m; ++j) {
            int c = (R[j] - L[j] - 1)*h[j];
            res = max(res, c);
        }

        ans = max(ans, res);
        //cout << ans << endl;
    }



}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) 
        for(int j = 1; j <= m; ++j) cin >> a[i][j];

    ans = 0;
    Solve();
    cout << ans;

    return 0;
}