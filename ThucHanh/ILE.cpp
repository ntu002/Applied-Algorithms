// Integer Linear Equation

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int a[105];
int f;
int t[105];
int sum;

void Try(int k) {
    for (int v = 1; v <= (m - f - (t[n] - t[k]))/a[k]; ++v) {
        f += a[k]*v;
        if (k == n) {
            if (f == m) sum++;
        } else Try(k+1);
        f -= a[k]*v;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    sum = 0;
    f = 0;
    t[1] = a[1];
    for (int i = 2; i <= n; ++i) t[i] = a[i] + t[i-1];
    Try(1);

    cout << sum;
    return 0;
}