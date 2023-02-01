// WATER JUGS
//AC - 100/100

#include <iostream>
#include <algorithm>

using namespace std;
int a, b, c;

int gcd(int a, int b)
{
    if (b == 0)
       return a;
    return gcd(b, a%b);
}

int Solve(int a, int b, int c) {
    int from = a;
    int to = 0;

    int step = 1;
    while (from != c && to != c) {
        int tmp = min(from, b - to);

        to += tmp;
        from -= tmp;

        step++;

        if (from == c || to == c) break;

        if (from == 0) {
            from = a;
            step++;
        }

        if (to == b) {
            to = 0;
            step++; 
        }
    }

    return step;
}

int main() {
    cin >> a >> b >> c;

    if (c > max(a,b)) cout << -1;
    else {
        if (c % gcd(a,b) != 0) cout << -1;
        else cout << min(Solve(a,b,c), Solve(b,a,c));
    } 
    return 0;
}