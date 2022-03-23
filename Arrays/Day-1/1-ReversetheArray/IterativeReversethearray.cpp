//Iterative solution for the reverse of array
#include<bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
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
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    printArray(arr, n); // for printing the original array
    reverseArray(arr, 0, n-1);  //for reversing the array
    cout << "Reversed Array is: " << endl;
    printArray(arr, n); // for printing the reversed array
    return 0;
}


