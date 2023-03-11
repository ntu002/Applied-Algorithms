/*
Bài toán

Cho một xâu t và một từ s. Tìm các vị trí xuất hiện từ s trên xâu t.

Độ phức tạp

O(m+n)

với m, n là độ dài hai xâu s và t
*/

#include <algorithm>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <iostream>

using namespace std;

const int MN = 1000111;

char s[MN], t[MN];

int nxt[MN];

int main() {

    gets(t);

    gets(s);

    int j;

    j = nxt[0] = -1;

    int ls = strlen(s), lt = strlen(t);

    for (int i = 1; i < ls; ++i) {

        while (j >= 0 && s[j + 1] != s[i]) j = nxt[j];

        if (s[j + 1] == s[i]) ++j;

        nxt[i] = j;

    }

    j = -1;

    for (int i = 0; i < lt; ++i) {

        while (j >= 0 && s[j + 1] != t[i]) j = nxt[j];

        if (s[j + 1] == t[i]) ++j;

        if (j == ls - 1) {  // Het xau s

            printf("%d ", i - j + 1);

            j = nxt[j];

        }

    }

    puts("");

    return 0;

}