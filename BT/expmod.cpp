// Expmod 

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e9+7;
long long n, m;

long long Expmod(int n, int m) {
    long long res = 1;
    while (m > 0) {
        if (m & 1) {
            res = (res * n) % MAX;
        }
        n = n * n % MAX;
        m >>= 1;
    }
    return res;
}
int main() {
    cin >> n >> m;

    cout << Expmod(n, m);
    return 0;
}
