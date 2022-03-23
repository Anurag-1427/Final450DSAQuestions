// Given heights of n towers and a value k. We need to either increase or decrease the height of every tower by k (only once) where k > 0. The task is to minimize the difference between the heights of the longest and the shortest tower after modifications and output this difference.

// Input  : arr[] = {1, 15, 10}, k = 6
// Output :  Maximum difference is 5.
// Explanation : We change 1 to 7, 15 to 
// 9 and 10 to 4. Maximum difference is 5
// (between 4 and 9). We can't get a lower
// difference.

// Input : arr[] = {1, 5, 15, 10} 
//         k = 3   
// Output : Maximum difference is 8
// arr[] = {4, 8, 12, 7}

// Input : arr[] = {4, 6} 
//         k = 10
// Output : Maximum difference is 2
// arr[] = {14, 16} OR {-6, -4}

// Input : arr[] = {6, 10} 
//         k = 3
// Output : Maximum difference is 2
// arr[] = {9, 7} 

// Input : arr[] = {1, 10, 14, 14, 14, 15}
//         k = 6 
// Output: Maximum difference is 5
// arr[] = {7, 4, 8, 8, 8, 9} 

// Input : arr[] = {1, 2, 3}
//         k = 2 
// Output: Maximum difference is 2
// arr[] = {3, 4, 5} 

// First, we try to sort the array and make each height of the tower maximum. We do this by decreasing the height of all the towers towards the right by k and increasing all the height of the towers towards the left (by k). It is also possible that the tower you are trying to increase the height doesn’t have the maximum height. Therefore we only need to check whether it has the maximum height or not by comparing it with the last element towards the right side which is a[n]-k. Since the array is sorted if the tower’s height is greater than the a[n]-k then it’s the tallest tower available. Similar reasoning can also be applied for finding the shortest tower.  

// Note:- We need not consider where a[i]<k because the height of the tower can’t be negative so we have to neglect that case.


// T.C: O(n logn) and S.C: O(n)

#include <bits/stdc++.h>
using namespace std;

// User function Template
int getMinDiff(int arr[], int n, int k)
{
	sort(arr, arr + n);
	int ans = arr[n - 1] - arr[0]; // Maximum possible height difference

	int tempmin, tempmax;
	tempmin = arr[0];
	tempmax = arr[n - 1];

	for (int i = 1; i < n; i++) {
		tempmin= min(arr[0] + k,arr[i] - k); // Minimum element when we add k to whole array

		tempmax = max(arr[i - 1] + k, arr[n - 1] - k); // Maximum element when we subtract k from whole array
														
		ans = min(ans, tempmax - tempmin);
	}
	return ans;
}

// Driver Code Starts
int main()
{
	int k = 6, n = 6;
	int arr[n] = { 7, 4, 8, 8, 8, 9 };
	int ans = getMinDiff(arr, n, k);
	cout << ans;
}
