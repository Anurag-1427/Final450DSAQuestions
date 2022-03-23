// Therefore this problem can be solved iteratively using two pointers (first pointer pointing to start of the array and second pointer pointing to the last element of the array) method and keeping count of total merging operations done till now.
// Below is an implementation of the above idea.

// T.C: O(n)

// C++ program to find number of operations to make an array palindrome
#include <bits/stdc++.h>
using namespace std;

// Returns minimum number of count operations required to make arr[] palindrome
int findMinOps(int arr[], int n)
{
	int ans = 0; // Initialize result

	// Start from two corners
	for (int i=0,j=n-1; i<=j;)
	{
		// If corner elements are same, problem reduces arr[i+1..j-1]
		if (arr[i] == arr[j])
		{
			i++;
			j--;
		}

		// If left element is greater, then we merge right two elements
		else if (arr[i] > arr[j])
		{
			// need to merge from tail.
			j--;
			arr[j] += arr[j+1] ;
			ans++;
		}

		// Else we merge left two elements
		else
		{
			i++;
			arr[i] += arr[i-1];
			ans++;
		}
	}

	return ans;
}

// Driver program to test above
int main()
{
	int arr[] = {1, 4, 5, 9, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Count of minimum operations is "
		<< findMinOps(arr, n) << endl;
	return 0;
}
