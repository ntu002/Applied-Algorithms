#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e6 + 6;

int n;
int m;
int a[MAX];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int binSearch(int l, int r)
{
    int tmp = (l + r) / 2;
    if (m == a[tmp])
        return tmp;
    if (m > a[tmp])
        binSearch(tmp + 1, r);
    if (m < a[tmp])
        binSearch(l, tmp + 1);
    if (l == r)
        if (a[l] == m)
            return l;

    return -1;
}

int main()
{
    return 0;
}