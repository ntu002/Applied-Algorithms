// Course schedule
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 30;
int n ,x, y;
int a[MAX];
int t[MAX];
int res;
int f;

void Try(int k) {

    for (int v = 0; v <= 1; ++v) {  
        f += a[k]*v;
        if (k == n) {
            if (f >= x && f <= y) res++;
        } else Try(k+1);
       f -= a[k]*v;
    }
} 

int main() {

    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    
    res = 0;
    f = 0;
    t[1] = a[1];
    for(int i = 2; i <= n; ++i) t[i] = a[i] + t[i-1];

    Try(1);
    cout << res;

    return 0;
    
}