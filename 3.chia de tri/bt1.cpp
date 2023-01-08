#include<iostream>
#include <algorithm>

using namespace std;
int n;
int a[10005];
int s[10005];
int Max;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    Max = -99999999;
    s[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        if (s[i-1] > 0) s[i] = s[i-1] + a[i]; else s[i] = a[i];
        Max = max(s[i], Max);
    }
    cout << Max;
    //return 0;

}