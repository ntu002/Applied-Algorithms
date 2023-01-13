// Warehouse
/*
A truck is planned to arrive at some stations among N stations 1, 2, . . ., N located on a line. 
Station i (i = 1,…, N) has coordinate i and has following information​

ai : amount of goods​

ti : pickup time duration for taking goods​

The route of the truck is a sequence of stations x1 < x2 < . . . < xk (1 ≤ xj ≤ N, j = 1,…, k). 
Due to technical constraints, the distance between two consecutive stations that the truck arrives 
xi and xi+1 is less than or equal to D and the total pickup time duration cannot exceed T. 
Find a route for the truck such that total amount of goods picked up is maximal.​

Input​

Line 1: N, T, D (1 <= N <= 1000, 1 <= T <= 100, 1 <= D <= 10)​

Line 2: a1,. . ., aN (1 <= ai <= 10)​

Line 3: t1, . . ., tN (1 <= ti <= 10)​

Output​

Write the total amount of goods that the truck picks up in the route.​
*/

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e3+4;
int n, T, D;
int a[MAX];
int t[MAX];
int f[MAX][MAX];
int res;

void Solve() {

    for (int i = 1; i <= n; ++i) {
        for(int j = t[i]; j <= T; ++j) {
            for(int k = max(i-D, 0); k <= i-1; ++k) {
                f[i][j] = max(f[i][j], f[k][j-t[i]] + a[i]);
            }
            res = max(res, f[i][j]);
        }
    }

}


int main() {
    cin >> n >> T >> D;

    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> t[i];
    res = 0;

    Solve();

    cout << res;

    return 0;
}
