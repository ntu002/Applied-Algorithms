#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> a;
int n;

int Solve()
{
	int s = a[0];
	int res = 0;
	int Max_i;

	for (int i = 1; i < n; i++) {
		Max_i = max(s, res);

		s = res + a[i];
		res = Max_i;
	}

	return max(s, res);
}

int main()
{
    cin >> n;

    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }

	cout << Solve();
	return 0;
}
