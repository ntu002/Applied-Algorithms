#include <iostream>
#include <string>
#define ull unsigned long long
const int d = 256;
const ull Q = 1e9 + 7;

using namespace std;

string P, T;
// int last[256];

// void computeLast(string p) {
//     for (int c = 0; c < 256; ++c) {
//         last[c] = 0;
//     }
//     int k = p.length();
//     for (int i = k - 1; i >= 0; --i) {
//         if (last[p[i]] == 0) last[p[i]] = i;
//     }
// }

// int boyerMoore(string P, string T) {
//     computeLast(P);
//     int s = 0;
//     int cnt = 0;
//     int N = T.length();
//     int M = P.length();
//     while (s <= N - M) {
//         int j = M - 1;
//         while (j >= 0 && T[j + s] == P[j]) j = j - 1;
//         if (j == -1) {
//             cnt++; 
//             s = s + 1;
//         } else {
//             int k = last[T[j + s]];
//             s = s + (j - k > 1 ? j - k : 1);
//         }
//     }
//     return cnt;
// }

/*
    Using hash
*/

ull submod(ull a, ull b) {
    a = a % Q;
    b = b % Q;
    if (a >= b) return a - b;
    return Q + a - b;
}

ull exp(int d, int n) {
    if (n == 0) return 1 % Q;
    if (n == 1) return d % Q;
    int n1 = n/2;
    ull r = exp(d, n1);
    r = (r * r) % Q;
    if (n % 2 == 0) return r;
    return (r * d) % Q;
}

ull hashCode(string p) {
    ull c = 0;
    for (int i = 0; i < p.length(); ++i) {
        c = c * 256 + p[i];
        c = c % Q;
    }
    return c;
}

ull hashCode(string s, int start, int end) {
    ull c = 0;
    for (int i = start; i <= end; ++i) {
        c = c * 256 + s[i];
        c = c % Q;
    }
    return c;
}

int rabinKarp(string P, string T) {
    int cnt = 0;
    int N = T.length();
    int M = P.length();
    ull e = exp(d, M - 1);
    ull codeP = hashCode(P); ull codeT = hashCode(T, 0, M - 1);
    for (int s = 0; s <= N - M; ++s) {
        if (codeP == codeT) {
            bool ok = true;
            for (int j = 0; j < M; ++j) {
                if (P[j] != T[j + s]) {
                    ok = false;
                    break;
                }
            }
            if (ok) cnt++;
        }
        
        ull t = T[s] * e;
        t = t % Q;
        t = submod(codeT, t);
        codeT = t * d + T[s + M];
        codeT = codeT % Q;
    }
    return cnt;
}

int main() {
    getline(cin, P);
    getline(cin, T);
    int ans = rabinKarp(P, T);
    cout << ans << endl;
}