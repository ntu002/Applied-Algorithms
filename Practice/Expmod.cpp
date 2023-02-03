// EXPMOD
// error

#include <assert.h>
#include <stdio.h>

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define long long long

const int Max = 1e9+7;

typedef vector<int> vi;
const int BASE = 10000;
vi a, b;

void fix(vi &a) {
    a.push_back(0);
    for (int i = 0; i < a.size() - 1; ++i) {
        a[i + 1] += a[i] / BASE;
        a[i] %= BASE;
        if (a[i] < 0) {
            a[i] += BASE;
            a[i + 1]--;
        }
    }
    while (a.size() >= 2 && a.back() == 0) a.pop_back();
}

vi operator*(const vi &a, const vi &b) {
    vi c(a.size() + b.size() + 1);
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < b.size(); ++j) {
            c[i + j] += a[i] * b[j];
            c[i + j + 1] += c[i + j] / BASE;
            c[i + j] %= BASE;
        }
    return fix(c), c;
}

vi to_vi(int x) {  // x < Base
    assert(x < BASE);
    return vi(1, x);
}


int sqr(int x) {
    return (x*x) % Max;
}

long Solve(int a, int b) {
    if (b == 0) return 1;
    else
        if (b % 2 == 0) return sqr(Solve(a, b/2)) % Max;
        else
            return a * (sqr(Solve(a, b/2))) % Max;
}

int main() {
    cin >> a >> b;

    cout << Solve(a,b);

    return 0;
}