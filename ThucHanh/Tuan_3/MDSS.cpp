// MAX-DISTANCE SUB-SEQUENCE​
// ..._80/100 (1 test time limited)
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e5+5;
int n, c;
int a[MAX];
        
int t;

bool check(int distance) {
    int sl = 1;
    int i = 1, j = 2;
    while (i < n) {
        while (j <= n && a[j] - a[i] < distance) ++j;
        if (j <= n) sl++;
        if (sl >= c) return true;
        i = j;
        j++;
    } 
    return false;
}




int Solve() {
    int l = 0;
    int r = a[n] - a[1];
    while (l <= r) {
        int mid = (l+r)/2;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while(t--) {
        cin >> n >> c;
        for (int j = 1; j <= n; ++j) cin >> a[j];
        sort(a+1, a+1+n);
        cout << Solve() << endl;
    }
    return 0;

}