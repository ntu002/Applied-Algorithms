// Disjoint Segment​

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
int n;

struct Data{
    int first, second;
};

Data a[100005];

bool cmp( Data x, Data y)
{
    return x.second < y.second;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
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

}
