#include <stdio.h>

#include <vector>

#include <iostream>

#include <algorithm>

using namespace std;

#define N 100005

int n, m, cnt;

vector<int> a[N];

int Visited[N], Parent[N];

void visit(int u) {

    cout << "Visiting " << u << endl;

    Visited[u] = ++cnt; // travesal time

    for (int i = 0; i < a[u].size(); i++) {

        int v = a[u][i];

        if (v != Parent[u]) {

            if (!Visited[v]) {

                Parent[v] = u;

                visit(v);

            }

        }

    }

}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {

        int p, q;

        cin >> p >> q;

        /*do {

            p=rand()%n+1;

            q=rand()%n+1;

        } while (p==q);

        cout << p << " " << q << endl;*/

        a[p].push_back(q);

        a[q].push_back(p);

    }

    for (int i = 1; i <= n; i++) if (!Visited[i]) visit(i);

    cout << "Travesal time: " << endl;

    for (int i = 1; i <= n; i++) cout << Visited[i] << " ";

    cout << endl;

    cin.ignore(2);

}