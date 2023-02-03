// Parentheses
//AC - 100/100

#include <iostream>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;
string s;

int Solve() {
    stack<char> tmp;

    for(int i = 0; i < s.length(); ++i) {
        if (tmp.empty()) {
            tmp.push(s[i]);
        } else {
            if ((tmp.top() == '(' && s[i] == ')') || (tmp.top() == '[' && s[i] == ']') || (tmp.top() == '{' && s[i] == '}')) {
                tmp.pop();
            } else tmp.push(s[i]);
        }
    }

    if (tmp.empty()) return 1;

    return 0;
    
}

int main() {
    cin >> s;
    cout << Solve();
    return 0;
}