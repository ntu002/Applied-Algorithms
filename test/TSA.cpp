//  Bài 1: Top signal analysis
#include <iostream>

using namespace std;
const int MAX = 1e6 + 6;
int n;
int a[MAX];
int sum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sum = 0;
    for (int i = 2; i <= n-1; ++i)
        if (a[i] > a[i-1] && a[i] > a[i+1]) sum++;
    cout << sum;
    return 0;
}