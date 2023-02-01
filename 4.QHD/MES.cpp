// Max Even Subsequence
// 80/100 - Wrong Answer
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6 + 6;
const int MAXn = 1e9 + 9;

int n;
int a[MAX];
int SC[MAX], SL[MAX], s[MAX];
bool ddC[MAX], ddL[MAX];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >>n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        ddC[i] = true;
        ddL[i] = true;
    }

    if (a[1] % 2 == 1) {
        ddC[1] = false;
        SL[1] = a[1];
    } else {
        SC[1] = a[1];
        ddL[1] = false;
    }

    ans = - MAXn;

    for (int i = 2; i <= n; ++i) {
        if (a[i] % 2 == 0) {
            if (SC[i-1] > 0 && ddC[i-1]) SC[i] = SC[i-1] + a[i]; else SC[i] = a[i];
            if (ddL[i-1]) SL[i] = SL[i-1] + a[i]; else ddL[i] = false;

        } else {
            if (SC[i-1] > 0 && ddC[i-1]) SL[i] = SC[i-1] + a[i]; else SL[i] = a[i];
            if (ddL[i-1]) SC[i] = SL[i-1] + a[i]; else ddC[i] = false;
        }
        ans = max(ans, SC[i]);
        //cout << SC[i] << " " << SL[i] << " " << ddC[i-1] << " " << ddL[i-1] << endl;
    }
    //for (int i = 1; i <= n; ++i) cout << SC[i] << " " << SL[i] << endl;
    if (n == 1 && a[1] % 2 == 1) cout << "NOT_FOUND"; else cout << ans;
    return 0;
}
