// Initialize four variables for taking care of the first buy, first sell, second buy, second sell. Set first buy and second buy as INT_MIN and first and second sell as 0. This is to ensure to get profit from transactions. Iterate through the array and return the second sell as it will store maximum profit.

//T.C: O(N) and S.C: O(1)

#include <iostream>
#include<climits>
using namespace std;

int maxtwobuysell(int arr[],int size) {
	int first_buy = INT_MIN;
	int first_sell = 0;
	int second_buy = INT_MIN;
	int second_sell = 0;
	
	for(int i=0;i<size;i++) {
		
		first_buy = max(first_buy,-arr[i]);//we set prices to negative, so the calculation of profit will be convenient
		first_sell = max(first_sell,first_buy+arr[i]);
		second_buy = max(second_buy,first_sell-arr[i]);//we can buy the second only after first is sold
		second_sell = max(second_sell,second_buy+arr[i]);
	
	}
	return second_sell;
}

int main() {

	int arr[] = {2, 30, 15, 10, 8, 25, 80};
	int size = sizeof(arr)/sizeof(arr[0]);
	cout<<maxtwobuysell(arr,size);
	return 0;
}
