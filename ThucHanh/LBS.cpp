// .Largest Black SubRectangle

#include <iostream>
#include <algorithm>

using namespace std;
const int maxx = 1e3 + 3;
int n;
int a[maxx][maxx];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < n; ++j) cin >> a[i][j];

}