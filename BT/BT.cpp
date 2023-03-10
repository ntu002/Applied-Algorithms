// Sum pair of sequence equal to a number

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6+6;
int n, m;
int a[MAX];
int dem;

int BinarySearch(int x, int l, int r) {
    if (r >= l) {
        int mid = (r - l)/2 + l;

        if (a[mid] == x) return mid;

        if (a[mid] > x) return BinarySearch(x, l, mid-1);

        return BinarySearch(x, mid+1, r);
    }

    return -1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    sort(a+1, a+1+n);
    dem = 0;

    for(int i = 1; i <= n; ++i) {
        if (a[i] <= m - a[i]) {
            if (BinarySearch(m-a[i], i+1, n) != -1) {
                //cout << BinarySearch(m-a[i], i+1, n) << endl;
                dem++;
            }
        } else break;
    }

    cout << dem;

    return 0;
}