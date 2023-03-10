#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int n, m;

int main() {
    cin >> n >> m;

    float x;
    x = min(sqrt(2*n), sqrt(2*m));
    if (x < floor(x) + 0.5) {
        cout << floor(x);
    } else {
        int tg = ceil(x);
        if (tg % 2 == 0) cout << floor(x); else cout << ceil(x);
    }
    return 0;
}