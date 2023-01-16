// Gold Mining
/*
The Kingdom ALPHA has n warehouses of golds located on a straight line and are numbered 1, 2,..., n. 
The warehouse i has amount of ai (aiai is non-negative integer) and is located at coordinate i (i=1,...,n). 
The King of ALPHA opens a competition for hunters who are responsible to find a subset of gold warehouses 
having largest total amount of golds with respect to the condition that the distance between two selected 
warehouses must be greater than or equal to L1 and less than or equal to L2.


Input
Line 1 contains n, L1, and L2 (1≤n≤100000,1≤L1≤L2≤n)
Line 2 contains n integers a1,a2,…,an
Output
Contains only one single integer denoting the total amount of golds of selected warehouses.

Example
Input
6 2 3
3 5 9 6 7 4

Output
19
*/
#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
const int MAX = 1e6 +5;
int n, L1, L2;
int a[MAX];
int f[MAX]; // f[i]: tong luong vang lon nhat tu nha kho 1-> i-1 va nha kho i duoc chon
int res;

void Solve() {
    deque <int> dd;
    // 
    for(int i = 1; i <= n; ++i) {
        while (!dd.empty() && dd.front() < i - L2) dd.pop_front(); 
        // xoa phan tu (tu dau tien) cho den khi thoa man

        int tg = i - L1;
        if (tg >= 1) {
            // loai bo het dd.back() vi chi can lay nhung gia tri de lay max tron dqueue
            while (!dd.empty() && f[dd.back()] < f[tg]) 
            {
                dd.pop_back();
            }
            dd.push_back(tg);
            // them i - L1 vao hang doi 
        }

        if (!dd.empty()) f[i] = a[i] + f[dd.front()]; else f[i] = a[i];

        res = max(res, f[i]);
        
    }

}

int main() {
    cin >> n;
    cin >> L1 >> L2;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    res = 0;

    Solve();

    // for(int i = 1; i <= n; ++i) f[i] = a[i];

    // for(int i = 2; i <= n; ++i)
    // {
    //     for(int j = i - L2; j <= i - L1; ++j) {
    //         f[i] = max(f[i], a[i] + f[j]);
    //     }
    //     res = max(res, f[i]);
    // }
    cout << res;
    
    return 0;
}