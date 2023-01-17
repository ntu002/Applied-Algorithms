// CBUS
// AC 100/100

/*Input: 
3 2
0 8 5 1 10 5 9
9 0 5 6 6 2 8
2 2 0 3 8 7 2
5 3 4 0 3 2 7
9 6 8 7 0 9 10
3 8 10 6 5 0 2
3 4 4 5 2 2 0
Output: 25             
*/

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 50;
int n, k;
int a[MAX][MAX];
int appear[MAX]; // danh dau vi tri da di qua
int load; // so hanh khach hien dang o tren xe

int x[MAX];
int f;
int f_best;
int x_best[MAX];
int cmin;

int Check(int v, int i) {
    if (appear[v] == 1) return 0;

    if (v > n) {
        if (!appear[v-n]) return 0;
    } else {
        if (load + 1 > k) return 0;
    }

    return 1;
}

void Solution() {
    if (f + a[x[2*n]][0] < f_best) {
        f_best = f + a[x[2*n]][0];
        for(int i = 0; i <= 2*n; ++i) x_best[i] = x[i];
    }
}

void Try(int i){
    for(int v = 1; v <= 2*n; ++v) {
        if (Check(v,i)) {
            x[i] = v;
            f += a[x[i-1]][x[i]];
            if(v <= n) load += 1; else load -= 1;
            appear[v] = 1;
            if (i == 2*n) Solution();
            else {
                if (f + (2*n+1-i)*cmin < f_best) Try(i+1);
            }
            if (v <= n) load -= 1; else load += 1;
            appear[v] = 0;
            f -= a[x[i-1]][x[i]];
        }
    }
}

void Solve() {
    load = 0;
    f = 0;
    f_best = 1e9;
    for(int i = 1; i <= 2*n; ++i) appear[i] = 0;
    x[0] = 0;
    Try(1);
    cout << f_best;
}

int main() {
    cin >> n >> k;
    cmin = 1e9;
    for(int i = 0; i <= 2*n; ++i) {
        for(int j = 0; j <= 2*n; ++j) {
            cin >> a[i][j];
            if (i != j && cmin > a[i][j]) cmin = a[i][j];
        }
    }

    Solve();
    return 0;
}