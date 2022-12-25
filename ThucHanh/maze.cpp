//maze
#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int> ii;
 
int m,n,r,c;
int a[1000][1000], dd[1005][1005];
queue<ii> vitri;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int solve(int r, int c) {
    vitri.push(ii(r,c));
    dd[r][c] = 0; a[r][c] = 1;
    while (!vitri.empty()) {
        ii u = vitri.front(); vitri.pop();
        for(int i = 0; i < 4; ++i) {
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;
            if (x < 1 || x > n || y < 1 || y > m) return dd[u.first][u.second] + 1;
            if (a[x][y] != 1) {
                dd[x][y] = dd[u.first][u.second] + 1;
                vitri.push(ii(x,y));
                a[x][y] = 1;
            }
        }
    }
    return -1;

}


// int Slove(int r, int c) {
//     vitri.push(ii(r,c));
//     while (vitri.size() != 0) {
//         ii u = vitri.front(); vitri.pop();
        
//         for(int i = 0; i < 4; ++i) {
//             int x = dx[i] + u.first;
//             int y = dy[i] + u.second;

//             if (a[x][y] != 1) {
//                 a[x][y] = 1;
//                 dd[x][y] = dd[u.first][u.second] + 1;
//                 vitri.push(ii(x,y));
//             }
//         }
//     }
//     return -1;
// }


 int main() {
     cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= m; ++j) cin >> a[i][j];
    
    cout <<solve(r,c);
    // cout << endl;
    // for (int i = 1; i <= n; ++i) {

    //     for (int j = 1; j <= m; ++j) cout << dd[i][j] << " ";
    //     cout << endl;
    // }
    
    return 0;

 }