#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e2+3;

const int MOD = 1000000123;
int dp[N][N][N][2];

int fn(int n) {
	
  dp[1][1][0][1] = 1;
  dp[1][0][1][0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k <= i - j; k++) {
        if (j) {
          dp[i][j][k][1] = (dp[i][j][k][1] + dp[i - 1][j - 1][k][0]) % MOD;
          dp[i][j][k][1] = (dp[i][j][k][1] + dp[i - 1][j - 1][k][1]) % MOD;
        }
        if (k) {
          dp[i][j][k][0] = (dp[i][j][k][0] + dp[i - 1][j][k - 1][0]) % MOD;
          dp[i][j][k][0] = (dp[i][j][k][0] + dp[i - 1][j][k - 1][1]) % MOD;
        }
      }
    }
  }
  int ans = 0;
  for (int j = 0; j <= n; j++) {
    for (int k = 0; k <= n - j; k++) {
      ans = (ans + dp[n][j][k][0]) % MOD;
      ans = (ans + dp[n][j][k][1]) % MOD;
    }
  }
  return ans;
}

int main() {
	int n;
	cin >> n;
	cout << fn(n);
	return 0;
}