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


// mem[i] -> tong max k co 2 phan tu canh nhau co ptu ket thu tai i
// 
// mem[1] = a[1]; -> mem[i+1] = max(mem[i-1] + a[i+1], mem[i])  1001 10 5 5 5 100   
// mem[n]

// x[i] : tong max ma ptu ket thuc la i
// y[i] : tong max ma ptu ket thuc k phai la i
/*
x[1] = a[1];
y[1] = 0;

x[i] = max(x[i-2] + a[i], y[i-1] + a[i]);
y[i] = max(x[i-1], a[i-1] + x[i-3], a[i-1] + y[i-2],
			 a[i-2] + x[i-4], x[i-2], a[i-2] + y[i-3]
			 );
-> a[i-2] + y[i-3] -> x[i-1]
*/

// -> cout << max(x[n], y[n]); 