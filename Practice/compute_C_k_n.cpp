// Compute C_k_n

/*
Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input
Line 1: two positive integers k and n (1 <= k,n <= 999)
Output
Write te value C(k,n) modulo 10^9+7.

Example
Input
3  5
Output
1
*/

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e9+7;
const int N = 1e3+3;
int n, k;
int C[N][N];

int main() {
    cin >> k >> n;
    
    for(int i = 0; i <= k; ++i) {
        for (int j = i; j <= n; ++j) 
            if(i == j || i == 0) C[i][j] = 1; 
            else {
                C[i][j] = (C[i][j-1] + C[i-1][j-1]) % MAX; 
                //cout << "C[" << i << "][" << j << "] . "  << C[i][j] << endl; 
            }
    }

    cout << C[k][n];
    return 0 ;
}
