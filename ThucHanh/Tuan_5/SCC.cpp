// Compute Strongly Connected Components of directed graphs
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>

using namespace std;

const int Max = 1e5+6;
int n, m;
vector <int> a[Max];
stack <int> st;
int timeDFS;
int scc = 0;
int low[Max], num[Max];
bool D[Max];

void DFS(int u) {
    num[u] = low[u] = ++timeDFS;

    st.push(u);
    for(int v = 0; v < a[u].size(); ++v) {
    //for(auto&v:a[u]) {
        if (D[v]) continue;
        if (!num[v]) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        scc++;
        int v;
        do {
            v = st.top(); st.top();
            D[v] = true;
        } while(v != u);
    }
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }

    for(int i = 1; i <= n; ++i) 
        if (!num[i]) DFS(i);

    cout << scc;
    return 0;
}