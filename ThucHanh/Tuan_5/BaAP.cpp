// Bridges and Articulation Points

/*
- Một đỉnh gọi là khớp nếu như xoá đỉnh đó sẽ làm tăng số thành phần liên thông của đồ thị. 
- Một cạnh được gọi là cầu nếu xoá cạnh đó sẽ làm tăng số thành phần liên thông của đồ thị.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAXn = 1e6 + 7;
int n, m;
vector <int> a[MAXn];
int low[MAXn]; 
    // thoi gian den tham dinh u theo thu tu duyet DFS
    // gia tri thu tu nho nhat trong cay con goc v
int num[MAXn]; 
    // thoi gian nho nhat ma dinh u va cac dinh con cua u do the den tham duoc trong cay DFS
    // num[i]: thu tu tham cua dinh i
int khop[MAXn];
    // khop[i] = 1 -> dinh i la khop
    // khop[i] = 0 -> dinh i khong phai la khop
int cau[MAXn];
int parent[MAXn]; // parent[i] = cha cua i
int child[MAXn]; // child[i] = so con cua dinh i
int t;

void DFS(int u) {
    t++;
    num[u] = t;
    low[u] = num[u];

    for(int i = 0; i < a[u].size(); ++i) {
        int v = a[u][i];
        if (v == parent[u]) continue;

        // neu v da duoc tham -> low[u] = min(low[u], num[v]);
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            parent[v] = u;
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
    }
}

int KHOP() {

    int res = 0;

    // (u,v) neu u khong phai la goc va low[v] >= num[u] -> u la khuop
    for(int i = 1; i <= n; ++i) {
        int u = parent[i];
        if (u > 0 && parent[u] > 0 && low[i] >= num[u]) khop[u] = 1;
    }
    
    // neu u la 1 goc cua cay con thi u la khop neu child[u] >= 2
    for(int i = 1; i <= n; ++i) 
        if (parent[i] == 0 && child[i] >= 2) khop[i] = 1;
    
    for (int i = 1; i <= n; ++i) res += khop[i];
    
        return res;

}

int CAU() {

    int res = 0;
    for(int i = 1; i <= n; ++i) 
        if (parent[i] != 0 && low[i] >= num[i]) res++;

    return res;

}


int main() {

    cin >> n >> m;

    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    int t = 0;

    for(int i = 1; i <= n; ++i)
        if (!num[i]) DFS(i);

    for (int i = 1; i <= n; ++i) {
        int v = parent[i];
        if (v > 0) child[v]++;
    }

    cout << KHOP() << " " << CAU();

    return 0;
}