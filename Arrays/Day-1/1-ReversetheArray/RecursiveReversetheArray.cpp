//Recursice solution for the reverse of array
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    // base case
    if(start >= end) return ;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    //recursive calling 
    reverseArray(arr, start+1, end-1);
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr,n);
    reverseArray(arr, 0, n-1);
    cout << "Reversed array is: " << endl;
    printArray(arr, n);

    return 0;
}