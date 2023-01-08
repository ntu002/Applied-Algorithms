#include <iostream>
#include <algorithm>

using namespace std;
int a[10][10];
bool markR[10][10], markC[10][10], markSquare[10][10][10];
long long dem;
bool found;
void Result() {
    for (int i = 0; i <= 8; ++i) {
        for (int j = 0; j <= 8; ++j) cout << a[i][j] << " ";
        cout << endl;
    }
}

bool Check(int v, int r, int c) {
    return (markR[r][v] == false && markC[c][v] == false && markSquare[r/3][c/3][v] == false);
}

void Try(int r, int c)
{
    for (int v = 1; v <= 9; ++v)
    {
        if (Check(v,r,c) && a[r][c] == 0) {
            a[r][c] = v;
            markR[r][v] = true;
            markC[c][v] = true; 
            markSquare[r/3][c/3][v] = true;
            if (r == 8 and c == 8) {
                dem++;
                //Result();
                //cout << "--------------------------" << endl;
                //break;
            }
            else {
                    if (c < 8) Try(r, c+1); else Try(r+1, 0); 
            }
            
            markR[r][v] = false;
            markC[c][v] = false;
            markSquare[r/3][c/3][v] = false;
        }
        else {
            if (r == 8 and c == 8) {
                dem++;
                //Result();
                //cout << "--------------------------" << endl;
                //break;
            }
            else {
                if (c < 8) Try(r, c+1); else Try(r+1, 0); 
            }
        }
    }

}

int main()
{
    for (int r = 0; r <= 8; ++r) 
        for (int c = 0; c <= 8; ++c) cin >> a[r][c];
    for (int v = 1; v <= 9; ++v) {
        for(int r = 0; r <= 8; ++r) markR[r][v] = false;
        for(int c = 0 ; c <= 8; ++c) markR[c][v] = false;

        for (int i = 0; i <= 2; ++i)
            for (int j = 0; j <= 2; ++j) markSquare[i][j][v] = false;
    }

    for (int v = 1; v <= 9; ++v) {
        for(int r = 0; r <= 8; ++r) 
            for (int c = 0; c <= 8; ++c) 
                if (a[r][c] == v) {
                    markR[r][v] = true;
                    markC[c][v] = true;
                    markSquare[r/3][c/3][v] = true;
                }
        
        // for (int i = 0; i <= 2; ++i)
        //     for (int j = 0; j <= 2; ++j) markSquare[i][j][v] = false;
    }
    dem = 0;
    Try(0,0);
    cout << dem;

    return 0;
}