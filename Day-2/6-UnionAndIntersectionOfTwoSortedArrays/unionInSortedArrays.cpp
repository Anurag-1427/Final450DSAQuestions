// This implementation uses vectors but can be easily modified to adapt arrays with T.C: O(m+n) and S.C: O(1)
#include <bits/stdc++.h>
using namespace std;

/* Helper function for printUnion().
This same function can also be implemented as a lambda function inside printUnion().
*/
void next_distinct(const vector<int> &arr, int &x) // Moving to next distinct element
{
// vector CAN be passed by reference to avoid unnecessary copies.
// x(index) MUST be passed by reference so to reflect the change in the original index parameter

/* Checks whether the previous element is equal to the current element,
	if true move to the element at the next index else return with the current index
*/
	do
	{
		++x;
	} while (x < arr.size() && arr[x - 1] == arr[x]);
}

void printUnion(vector<int> arr1, vector<int> arr2)
{
	int i = 0, j = 0;
	while (i < arr1.size() && j < arr2.size())
	{
		if (arr1[i] < arr2[j])
		{
			cout << arr1[i] << " ";
			next_distinct(arr1, i); // Incrementing i to next distinct element
		}
		else if (arr1[i] > arr2[j])
		{
			cout << arr2[j] << " ";
			next_distinct(arr2, j); // Incrementing j to next distinct element
		}
		else
		{
			cout << arr1[i] << " ";
			// OR cout << arr2[j] << " ";
			next_distinct(arr1, i); // Incrementing i to next distinct element
			next_distinct(arr2, j); // Incrementing j to next distinct element
		}
	}
	// Remaining elements of the larger array
	while (i < arr1.size())
	{
		cout << arr1[i] << " ";
		next_distinct(arr1, i); // Incrementing i to next distinct element
	}
	while (j < arr2.size())
	{
		cout << arr2[j] << " ";
		next_distinct(arr2, j); // Incrementing j to next distinct element
	}
}

int main()
{
	vector<int> arr1 = {1, 2, 2, 2, 3}; // Duplicates Present
	vector<int> arr2 = {2, 3, 3, 4, 5, 5}; // Duplicates Present

	printUnion(arr1, arr2);

	return 0;
}
// This code is contributed by ciphersaini.
