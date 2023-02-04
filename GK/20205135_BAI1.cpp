#include <iostream>
#include <algorithm>

using namespace std;
const int MAXn = 1e5+6;
int n, k, m;
int a[MAXn];
int ans;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k >> m;

    for(int i = 1; i <= n; ++i) cin >> a[i];

    for(int i = 1; i <= n-k; ++i) {
        int sum = 0;
        for (int j = i; j <= i+k-1; ++j) sum += a[j];
        if (sum == m) ans++;
    } 

    cout << ans;

    return 0;

}