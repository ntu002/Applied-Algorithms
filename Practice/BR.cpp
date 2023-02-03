// Bounding rectangle
// AC - 100/100

#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;
const int MAX = 1e6+9;
int n;

int main() {

    int res = MAX;

    int a, b, c, d;
    a = MAX;
    b = MAX;
    c = -MAX;
    d = -MAX;

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        a = min(a, min(x1, x2));
        b = min(b, min(y1, y2));

        c = max(c, max(x1, x2));
        d = max(d, max(y1, y2));
    }

    res = min(res, abs((c-a)*(d-b))); 

    //cout << a << " " << b << " " << c << " " << d << '\n';

    cout << res;

    return 0;
}