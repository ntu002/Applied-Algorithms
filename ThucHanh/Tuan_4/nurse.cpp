// Nurse
/*
Đề bài: ​

Một giám đốc của một bệnh viện muốn lập lịch làm việc cho y tá trong N ngày 1…N.​
Y tá chỉ có thể làm việc liên tục trong x ngày (K1 <= x <= K2), sau đó phải nghỉ 1 ngày.​
- Y tá chỉ được nghỉ 1 ngày giữa 2 đợt làm việc liên tiếp. Có nghĩa rằng nếu y tá nghỉ 
ngày hôm nay, ngày mai y tá đó sẽ phải làm việc.​

Yêu cầu:​
Tính số cách có thể lập lịch làm việc cho các y tá.​

​Example:​
Input:​
6 2 3​
Output:​
4​
*/

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1e3+3;
int n, k1, k2;
int a[MAX]; // a[i]: so cach lam den ngay thu i ma ngay i nghi
int b[MAX]; // b[i]: so cach lam den ngay thu i ma ngay i di lam


int main() {
    cin >> n >> k1 >> k2;

    for(int i = 1; i <= n; ++i) {
        a[i] = 0;
        b[i] = 0;
    }

    a[0] = 1; a[1] = 1; b[k1] = 1;

    for(int i = k1+1; i <= n; ++i) {
        a[i] = b[i-1];
        b[i] = 0;

        for(int j = k1; j <= k2; ++j) {
            if (i - j >= 0) b[i] += a[i-j];
        }
    }

    cout << a[n] + b[n];
    return 0;
}