#include<iostream>

using namespace std;

int x[11];
int n, k;
int Bool[10] = {0};
int tg[10];

 
void xuat(int A[], int tg[]) {
    for (int i = 1; i <= n; i++)
        cout << A[i] << " ";
    cout << endl;
}
 
void Try(int tg[],int A[], int k) {
    for (int i = 1; i <= n; i++) {
        //Kiểm tra nếu phần tử chưa được chọn thì sẽ đánh dấu
        if (!Bool[i]) {
            A[k] = i; // Lưu một phần tử vào hoán vị
            Bool[i] = 1;//Đánh dấu đã dùng
            if (k == n)//Kiểm tra nếu đã chứa một hoán vị thì xuất
                xuat(A, tg);
            else
                Try(A, tg, k + 1);
            Bool[i] = 0;
        }
    }
}
 

void printArray(int a[],int tg[], int k){

	for(int i = 1; i <= k; ++i) Bool[i] = 0;
    for(int i = 1; i <= k; ++i) cout << a[i];

    //Try(a,tg, k);

	cout << " ";
}

void dequy(int h, int k, int n){
	for (int i = x[h-1] + 1; i <= n - (k-h); i++){
		x[h] = i;
		if (h == k) printArray(x,tg, k);
		else {
			dequy(h+1, k, n);
		}
	}
}
int main(){

	cin >> n >> k;
	x[0] = 0;
	dequy(1, k, n);
}