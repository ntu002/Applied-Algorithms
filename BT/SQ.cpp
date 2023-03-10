// Simulation Queue
// AC

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
queue<int> a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;

    do {
        cin >> s;
        if (s == "#") continue;;
         if (s == "PUSH") {
            int x;
             cin >> x;
             a.push(x);
         }

         if (s == "POP") {
            if (a.empty()) cout << "NULL" << endl;
            else {
                cout << a.front() << endl;
                a.pop();
            }
            
         }
    } while (s != "#");

    return 0;
}