#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s;
int res;


int main() {

    cin >> s;
    int n = s.size();

    res = -1;

    for(int i = 0; i < n-1; ++i) {
        for (int j = n-1; j >= i+1; --j) {
            if (s[i] == s[j-1] && s[i+1] == s[j]) {
                res = j-i-1;
                break;
            }
        }
    } 

    cout << res;
    return 0;
}