

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

struct Arc {
    int node; int w;
    Arc(int _node, int _w) {
        this->node = _node;
        this->w = _w;
    }
};

const int MAX = 1e4+4;
const int INF = 1e9+9;
int n, m;
int s,t;
vector <Arc> A[MAX];
int p[MAX], d[MAX];


int selectMin(set<int> nonFixed) {
    // return the node of nonFixed having minimum d[v]

    int minD = INF; int sel_v = -1;

    for (set<int>::iterator it = nonFixed.begin(); it != nonFixed.end(); ++it) {
        int v = *it;
        if (d[v] < minD) {
            minD = d[v];
            sel_v = v;
        }
    }

    return sel_v;
}


void dij2() {
    //set <int> nonFixed;
    priority_queue <pair<int, int> > nonFixed;
    for (int v = 1; v <= n; ++v) {
        d[v] = INF; p[v] = s;
    }

    for (int i = 0; i <= A[s].size(); ++i) {
        Arc a = A[s][i];
        int v = a.node; int w = a.w;
        d[v] = w;
    }

    d[s] = 0;
    for (int v = 1; v <= n; ++v) if(v != s) nonFixed.push(make_pair(v, d[v]));

    while (!nonFixed.empty()) {

        int u = nonFixed.top().first; nonFixed.pop();
        //int u = selecMin(nonFixed);
        if (u == t) break;
        //nonFixed.erase(u);

        for (int i = 0; i < A[u].size(); ++i) {
            Arc a = A[u][i];
            int v = a.node;
            int w = a.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
                nonFixed.push(make_pair(v, d[v]));
            }
        }
    }

    cout << d[t];

}

void dijkstra() {
    set<int> nonFixed;

    for (int v = 1; v <= n; ++v) {
        d[v] = INF; p[v] = s;
    }

    for (int i = 0; i < A[s].size(); ++i) {
        Arc a = A[s][i];
        int v = a.node; int w = a.w;
        d[v] = w;
    }

    d[s] = 0;
    for (int v = 1; v <= n; ++v) if (v != s) nonFixed.insert(v);

    while(!nonFixed.empty()) {
        int u = selectMin(nonFixed);
        if (u == t) break;
        nonFixed.erase(u); // shortest path from s to u has been found
        for (int i = 0; i < A[u].size(); ++i) {
            Arc a= A[u][i];
            int v = a.node;
            int w = a.w;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                p[v] = u;
            }
        }
    }

    cout << d[t];
}



int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back(Arc(v,w));
    }

    cin >> s >> t;

    dij2();

    return 0;
}