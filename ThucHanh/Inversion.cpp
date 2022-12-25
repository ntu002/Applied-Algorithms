// Inversion
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
const int MAX = 1e6 + 5;
const int MAXn = 1e9 + 7;
int n;
int a[MAX];
int temp[MAX];

// int solve(int arr[],int n)
// {
//     multiset<int> set1;
//     set1.insert(arr[0]);
  
//     int count = 0;

//     multiset<int>::iterator itset1; 
    
//     for (int i=1; i<n; i++)
//     {
//         set1.insert(arr[i]);
  
//         itset1 = set1.upper_bound(arr[i]); // phan tu dau tien co gia tri >= a[i];
  
//         count += distance(itset1, set1.end());
//     }
  
//     return count;
// }


// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(NULL);
//     cout.tie(NULL);

//         int n;
//         int a[MAX];
//         cin >> n;
//         for (int j = 0; j < n; ++j) cin >> a[j];
//         cout << solve(a,n) % MAXn << endl;;

//     //}
//     return 0;
// }

int _merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left, Count = 0;
    while ((i <= mid) && (j <= right)) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else {
            temp[k++] = a[j++];
            Count = (Count + (mid - i + 1)) % MAXn;
        }
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
    for (i = left; i <= right; i++) a[i] = temp[i];

    return Count;
}

int mergeSort(int left, int right) {
    int mid, dem = 0;
    if (right > left) {
        mid = (left + right) / 2;

        dem = (dem + mergeSort(left, mid)) % MAXn;
        dem = (dem + mergeSort(mid + 1, right)) % MAXn;
        dem = (dem + _merge(left, mid, right)) % MAXn;
    }

    return dem;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << mergeSort(1,n);
    return 0;
}