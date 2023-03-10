// Store & Search String

// AC: 100/100

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string Type;
    do{
        cin >> Type;
        if (Type == "*") continue;

        // string s;
        // cin >> s;
        a[Type] = 1;

    }while (Type != "*");

    do {
        cin >> Type;
        if (Type == "***") continue;

        if (Type == "find") {
            string s;
            cin >> s;
            if (a[s] == 1) cout << 1 << endl;
            else cout << 0 << endl;
        } else 
            if (Type == "insert") {
                string s;
                cin >> s;
                if (a[s] == 1) cout << 0 << endl;
                else {
                    a[s] = 1;
                    cout << 1 << endl;
                }
            }


    }while (Type != "***");

    return 0;
}