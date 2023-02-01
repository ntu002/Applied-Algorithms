// Count number of sudoku solutions

// Failed

/*
input: 
0 0 3 4 0 0 0 8 9
0 0 6 7 8 9 0 2 3
0 8 0 0 2 3 4 5 6
0 0 4 0 6 5 0 9 7
0 6 0 0 9 0 0 1 4
0 0 7 2 0 4 3 6 5
0 3 0 6 0 2 0 7 8
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

output: 
64
*/

#include <iostream>
#include <algorithm>

using namespace std;
int a[10][10];
int markR[10][10], markC[10][10], markSquare[10][10][10];
int dem;
bool found;

void Result() {
    for(int i = 0; i <= 8; ++i) {
        for(int j = 0; j <= 8; ++j) cout << a[i][j] << " ";
        cout << endl;
    }
}

bool Check(int v, int r, int c) {
    return (markC[c][v] == false && markR[r][v] == false && markSquare[r/3][c/3][v] == false);
}

void Try(int r, int c) {

    // for(int v = 1; v <= 9; ++v) {
    //     if (Check(v,r,c) && a[r][c] == 0) {
    //         cout << r << " " << c << " : " << v << " | ";
    //         a[r][c] = v;
    //         markC[c][v] = true;
    //         markR[r][v] = true;
    //         markSquare[r/3][c/3][v] = true;

    //         if (r == 8 && c == 8) {
    //             dem++;
    //             // cout << "--------------------------" << endl;
    //             // Result();
    //             // cout << "--------------------------" << endl;
    //             // break;
    //         } else {
    //             if (c < 8) Try(r, c+1); 
    //             else 
    //                 if (r < 8) Try(r+1, 0);
    //                 cout << endl;
    //         }

    //         a[r][c] = 0;
    //         markC[c][v] = false;
    //         markR[r][v] = false;
    //         markSquare[r/3][c/3][v] = false;
    //     } 
    //     else {
    //         if (r == 8 && c == 8) {
    //             dem++;
    //         } else {
    //             if (c < 8) Try(r, c+1); 
    //             else 
    //                 if (r < 8) Try(r+1, 0);
    //         }
    //     }
    // }

    if (a[r][c] == 0) {
        for(int v = 1; v <= 9; ++v) {
            cout << r << c << v << ": " << Check(v,r,c) << " | ";
        if (Check(v,r,c)) {
            //cout << r << " " << c << " : " << v << " | ";
            a[r][c] = v;
            markC[c][v] = true;
            markR[r][v] = true;
            markSquare[r/3][c/3][v] = true;

            if (r == 8 && c == 8) {
                dem++;
                // cout << "--------------------------" << endl;
                // Result();
                // cout << "--------------------------" << endl;
                // break;
            } else {
                if (c < 8) Try(r, c+1); 
                else 
                    if (r < 8) Try(r+1, 0);
                    cout << endl;
            }

            a[r][c] = 0;
            markC[c][v] = false;
            markR[r][v] = false;
            markSquare[r/3][c/3][v] = false;
        } 
        else {
            if (r == 8 && c == 8) {
                dem++;
            } else {
                if (c < 8) Try(r, c+1); 
                else 
                    if (r < 8) Try(r+1, 0);
            }
        }
    }
    } else {
            if (r == 8 && c == 8) {
                dem++;
            } else {
                if (c < 8) Try(r, c+1); 
                else 
                    if (r < 8) Try(r+1, 0);
            }
        }
}

int main() {
    for (int r = 0; r <= 8; ++r) {
        for(int c = 0; c <= 8; ++c) cin >> a[r][c];
    }

    for (int v = 1; v <= 9; ++v) {
        for (int r = 0; r <= 8; ++r) markR[r][v] = false;
        for (int c = 0; c <= 8; ++c) markC[c][v] = false;

        for (int i = 0; i <= 2; ++i) 
            for (int j = 0; j <= 2; ++j) markSquare[i][j][v] = false;
    }

    for(int v = 1; v <= 9; ++v) {
        for(int r = 0; r <= 8; ++r)
            for(int c = 0; c <= 8; ++c)
                if (a[r][c] == v) {
                    markR[r][v] = true;
                    markC[c][v] = true;
                    markSquare[r/3][c/3][v] = true;
                }
    }

    // for(int v = 1; v <= 9; ++v) {
    //     for(int r = 0; r <= 8; ++r)
    //         for(int c = 0; c <= 8; ++c)
    //             // if (a[r][c] == v) {
    //             //     markR[r][v] = true;
    //             //     markC[c][v] = true;
    //             //     markSquare[r/3][c/3][v] = true;
    //             // }
    //             {
    //                 cout << r << c << v << markSquare[r/3][c/3][v] << " | ";
    //             }
    //             cout << endl;
    // }

    dem = 0;
    Try(0,0);

    //cout << dem;
    return 0;
}