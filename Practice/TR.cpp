// Text Replacement

// AC - 100/100

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string s1, s2;
string s;

void Solve() {
    string ans = "";

    for(int i = 0; i < s.length(); ++i) {
        int k = 0;

        // ktra xem tu ki tu i cua xau s co giong sau s1 hay khong
        if (s[i] == s1[k] && (i+s1.length() <= s.length())) {
            int j;
            for(j = i; j < i+s1.length(); ++j) {
                if (s[j] != s1[k]) break;
                else k++;
            }

            // neu giong thi thay s1 thanh s2
            // them s2 vao ans
            if (j == i + s1.length()) {
                ans.append(s2);
                i = j-1;
            } else ans.push_back(s[i]);
            // nguoc lai thi them ki tu s1 vao ans
        } else ans.push_back(s[i]);
    }

    cout << ans;
}

int main() {
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s);

    Solve();
    return 0;

}