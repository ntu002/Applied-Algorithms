#include <bits/stdc++.h>
using namespace std;
string s;
void solve(){
	int dis = 0;
	for (int i=0;i<s.length() - 2;i++)
		for (int j=i+1;j<s.length() - 1;j++){
			if (s[i] == s[j] && s[i+1] == s[j+1]){
				if (dis < (j-i)) dis = j - i;
			}
		}
	if (dis) cout << dis;
	else cout << "-1";
}

int main(){
	cin >> s;
	solve();
	return 0;
}
