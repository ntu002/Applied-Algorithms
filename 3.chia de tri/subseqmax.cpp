#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e6 + 6;
int n;
int a[MAX];
int maxL, maxR;

int MAXLEFT(int x, int y)
{
    int s = 0;
    for (int i = y; i >= x; --i)
    {
        s += a[i];
        maxL = max(maxL, s);
    }
    return maxL;
}

int MAXRIGHT(int x, int y)
{
    int s = 0;
    for (int i = x; i <= y; ++i)
    {
        s += a[i];
        maxR = max(maxR, s);
    }
    return maxR;
}

int SubSeqMax(int x, int y)
{
    if (x == y)
        return a[x];
    if (x < y)
    {
        int tmp = (x + y) / 2;

        int wL = SubSeqMax(x, tmp);
        int wR = SubSeqMax(tmp + 1, y);

        int mR = MAXRIGHT(tmp + 1, y);
        int mL = MAXLEFT(x, tmp);
        int wM = mR + mL;
        return max(max(wR, wL), wM);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << SubSeqMax(1, n);
    return 0;
}