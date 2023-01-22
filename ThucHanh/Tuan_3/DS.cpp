// Disjoint Segment​
// AC - 100/100

#include <iostream>
#include <algorithm>

using namespace std;
const int MAXn = 1e6+6;
int n;
struct Data {
    int first;
    int second;

};
Data a[MAXn];

bool cmp(Data x, Data y) {
    return x.second < y.second;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].first >> a[i].second;

    sort(a+1, a+n+1, cmp);

    int d = 1, i = 1;
    for(int j = 2; j <= n; ++j)
    {
        if (a[j].first > a[i].second)
        {
            d++;
            i = j;
        }
    }

    //for(int i = 1; i <= n; ++i) cout << a[i].first << " " << a[i].second << '\n';
    cout << d << '\n';

    return 0;
}