// Using Binary Search over the Range

// Complexity Analysis:

// T.C: O( y * n*logn)
// where y =  log( abs(Mat[0][0] - Mat[n-1][n-1]) )
// We call the getElementsGreaterThanOrEqual function  log ( abs(Mat[0][0] – Mat[n-1][n-1])  ) times
// Time complexity of getElementsGreaterThanOrEqual is O(n logn) since there we do binary search n times.
// S.C: O(1)


#include <bits/stdc++.h>
using namespace std;

// This returns count of elements in matrix less than of equal to num
int getElementsGreaterThanOrEqual(int num, int n, int mat[4][4]) {
	int ans = 0;

	for (int i = 0; i < n; i++) {
		// if num is less than the first element then no more element in matrix further are less than or equal to num
		if (mat[i][0] > num) {
			return ans;
		}
		// if num is greater than last element, it is greater than all elements in that row
		if (mat[i][n - 1] <= num) {
			ans += n;
			continue;
		}
		// This contain the col index of last element in matrix less than of equal to num
		int greaterThan = 0;
		for (int jump = n / 2; jump >= 1; jump /= 2) {
			while (greaterThan + jump < n &&
				mat[i][greaterThan + jump] <= num) {
				greaterThan += jump;
			}
		}

		ans += greaterThan + 1;
	}
	return ans;
}

// returns kth smallest index in the matrix
int kthSmallest(int mat[4][4], int n, int k) {
	// We know the answer lies between the first and the last element
	// So do a binary search on answer based on the number of elements
	// our current element is greater than the elements in the matrix
	int l = mat[0][0], r = mat[n - 1][n - 1];

	while (l <= r) {
		int mid = l + (r - l) / 2;
		int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);

		if (greaterThanOrEqualMid >= k)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main() {
	int n = 4;
	int mat[4][4] = {
		{10, 20, 30, 40},
		{15, 25, 35, 45},
		{25, 29, 37, 48},
		{32, 33, 39, 50},
	};
	cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
	return 0;
}
