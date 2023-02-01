// Capacitated Vehicle Routing - Not Empty Route Allowed
// AC - 100/100

/*
Input: 
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0
Output: 
70
*/

#include <iostream>
#include <algorithm>

using namespace std;
int n, K;
int d[50]; // khach hang thu i yeu cau so luong la d[i]
int q; //xe thu i co tai trong la q[i];
int c[50][50]; // khoang cach di tu i -> j

int x[50]; // diem tiep theo cua diem khach hang thu i tren lo trinh
int y[50]; // diem dau tien cua xe thu i

int Load[50]; // tong khoi luong hang tren xe thu i
bool visited[50]; // danh dau khach hang i da duoc giao 
int f; // chieu dai quang duong di duoc cua k xe
int nbsegment; // so chang duong di duoc cua k xe = n+k;
int Fmin;
int C_min; // do dai cua chang nho nhat

void solution() {
    if (f < Fmin) Fmin = f;

}

bool checkX(int v, int i, int k) {
    if (v == 0) return true;
    if (Load[k] + d[v] > q) return false;
    if (visited[v] == true) return false;
    return true;

}

bool checkY(int v, int k) {
    if (Load[k] + d[v] > q) return false;
    return true;
}

void TryX(int i, int k) {
    for(int v = 0; v <= n; ++v) {
        if (checkX(v, i, k)) {
            x[i] = v; visited[v] = true;
            Load[k] += d[v];
            f += c[i][v];
            nbsegment++;

            if(v == 0) {
                if (k == K) {
                    if (nbsegment == n+K) solution(); 
                } else
                {
                    if (f + C_min*(n+K-nbsegment) < Fmin)  TryX(y[k+1], k+1);
                } 
            } else if (f + C_min*(n+K-nbsegment) < Fmin) TryX(v, k);

            visited[v] = false;
            Load[k] -= d[v];
            f -= c[i][v];
            nbsegment--;
        }
    }

}

void TryY(int k) {
    for (int v = y[k-1] + 1; v <= n + k - K; ++v) {
        if (checkY(v,k)) {
            y[k] = v; visited[v] = true;
            Load[k] += d[v];
            f += c[0][v];
            nbsegment++;
            if(k == K) {
                TryX(y[1], 1);
            } else TryY(k+1);

            visited[v] = false;
            Load[k] -= d[v];
            f -= c[0][v];
            nbsegment--;
        }

    }

}


int main() {
    cin >> n >> K >> q;

    C_min = 1e9;
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j){
            cin >> c[i][j];
            if (C_min > c[i][j] && i!=j) C_min = c[i][j];

        } 

    for(int i = 1; i <= n; ++i) visited[i] = false;
    for(int i = 1; i <= K; ++i) Load[i] = 0;
    f = 0;
    Fmin = 1e9;
    nbsegment = 0;
    TryY(1);
    cout << Fmin;
    //cout <<f;
    return 0;
}