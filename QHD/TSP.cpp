/*

tsp(i,s) -> 
F[i,s] -> lưu kết quả của bài tập con 
TSP(i,s) {
    if S empty then {
        F[i,s] = c[i,0];
        return F[i,s];
    } 
    if (F[i,s] < 0){
        F[i,s] = oo
        for (int j = 0 -> n-1) 
            if (j thuộc s) 
                F[i,s] = min (F[i,S], TSP(j, s\j)+a[i][j]);
        return F[i,s];
    } // bt con chưa được giải
}

*/

#include <iostream>
#include <algorithm>
#include <vector>

#define pair<int, int> ii

using namespace std;
int n, m;
int a[1005][1005];
int F[1005][1005];

int TSP(int i, unsigned int s) {
    if (s == 0) {
        F[i][s] = a[i][0];
        return F[i][s];
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    }
}