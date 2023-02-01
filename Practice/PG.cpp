// Permutation generation
// AC: 120/120

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[30];

void Print() {
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
}

void Try() {
    do {
        Print();
    } while (next_permutation(a,a+n));
    /*
    bool next_permutation (BidirectionalIterator first,
                       BidirectionalIterator last);
                       -> hoan vi cho den khi ve day ban dau
    */
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) a[i] = i+1;
    Try();
    return 0;
}
