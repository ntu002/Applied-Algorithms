#include <algorithm> // for sorting
#include <iostream>
using namespace std;
int m;

// Required function
int maxProductSubarrayOfSizeK(int A[], int n, int k)
{
	// sorting given input array
	sort(A, A + n);

	// variable to store final product of all element
	// of sub-sequence of size k
	int product = 1;

	// CASE I
	// If max element is 0 and
	// k is odd then max product will be 0
	if (A[n - 1] == 0 && (k & 1))
		return 0;

	// CASE II
	// If all elements are negative and
	// k is odd then max product will be
	// product of rightmost-subarray of size k
	if (A[n - 1] <= 0 && (k & 1)) {
		for (int i = n - 1; i >= n - k; i--)
			product *= A[i];
		return product;
	}

	// else
	// i is current left pointer index
	int i = 0;

	// j is current right pointer index
	int j = n - 1;

	// CASE III
	// if k is odd and rightmost element in
	// sorted array is positive then it
	// must come in subsequence
	// Multiplying A[j] with product and
	// correspondingly changing j
	if (k & 1) {
		product *= A[j];
		j--;
		k--;
	}

	// CASE IV
	// Now k is even
	// Now we deal with pairs
	// Each time a pair is multiplied to product
	// ie.. two elements are added to subsequence each time
	// Effectively k becomes half
	// Hence, k >>= 1 means k /= 2
	k >>= 1;

	// Now finding k corresponding pairs
	// to get maximum possible value of product
	for (int itr = 0; itr < k; itr++) {

		// product from left pointers
		int left_product = A[i] * A[i + 1];

		// product from right pointers
		int right_product = A[j] * A[j - 1];

		// Taking the max product from two choices
		// Correspondingly changing the pointer's position
		if (left_product > right_product) {
			product *= left_product;
			i += 2;
		}
		else {
			product *= right_product;
			j -= 2;
		}
	}

	// Finally return product
	return product;
}

// Driver Code to test above function
int main()
{
	int A[100];
	int n;
	int k = 4;

    cin >> n >> k >> m;
    for(int i = 1; i <= n; ++i) cin >> A[i];

	cout << maxProductSubarrayOfSizeK(A, n, k);

	return 0;
}
