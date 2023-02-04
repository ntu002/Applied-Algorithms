#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 1e6+6;
int n;
priority_queue <int> a;

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        a.push(x);
    }

    string type;

    do
    {
        cin >> type;
        if (type == "*")
            continue;
        else if (type == "insert") {
            int x;
            cin >> x;
            a.push(x);
        } else if (type == "delete-max") {
            cout << a.top() << endl;
            a.pop();
        }
    } while (type != "*");
    return 0;
}