// Binary sequence generation
// AC - 100/100
/*
Given an integer n, write a program that generates all the binary sequences of length n in a lexicographic order.

Input
Line 1: contains an integer n (1 <= n <= 20)
Output
Write binary sequences in a lexicographic ordder, eac sequence in a line

Example
Input
3
Output
000
001
010
011
100
101
110
111
*/

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int a[30];

void Print() {
    for(int i = 0; i < n; ++i) {
        cout << a[i];
    }
    cout << endl;

}

void Solve(int i) {

    if (n == i) {
        Print();
        return;
    }

    a[i] = 0;
    Solve(i+1);

    a[i] = 1;
    Solve(i+1);

}

int main() {
    cin >> n;

    Solve(0);

    return 0;
}