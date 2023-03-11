#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;
    
    string ans;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        while (!ans.empty() && ans.back() < s[i] && ans.size() + n - i > k) {
            ans.pop_back();
            //cout << 0 << ans << endl;
        }
        //cout << 0 << ans << endl;
        if (ans.size() < k) {
            ans.push_back(s[i]);
        }
        //cout << 1 << ans << "\n\n";
    }
    cout << ans << endl;
    
    return 0;
}
