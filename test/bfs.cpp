#include <stdio.h>

#include <vector>

#include <queue>

using namespace std;

vector<int> a[2309];

int d[2309]; //one-based

int n, m;

void bfs() {

    int u, i, v;

    queue<int> qu;

    qu.push(1);

    d[1] = 1;

    while (qu.size()) {

        u = qu.front();

        qu.pop();

        for (int i = 0; i < a[u].size(); i++) {

            int v = a[u][i];

            if (d[v] == 0) {

                d[v] = d[u] + 1;

                qu.push(v);

            }

        }

    }

}

int main() {

    scanf("%d%d", &n, &m);

    while (m--) {

        int p, q;

        scanf("%d%d", &p, &q);

        a[p].push_back(q);

        a[q].push_back(p); // remove it in one-directional graph

    }

    bfs();

    printf("   i : ");

    for (int i = 1; i <= n; i++)

        printf("%3d,", i);

    printf("\n");

    printf("d[i] : ");

    for (int i = 1; i <= n; i++)

        printf("%3d,", d[i]);

    printf("\n");

}