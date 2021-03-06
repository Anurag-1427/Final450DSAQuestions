#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[], int arr_size)
{
    int low = 0;
    int high = arr_size-1;
    int mid = 0;

    while(mid <= high)
    {
        switch(arr[mid])
        {
            case 0:
                    swap(arr[low++], arr[mid++]);
                    break; 
            case 1: 
                    mid++;
                    break;
            case 2: 
                    swap(arr[mid], arr[high--]);
                    break;
        }
    }
}
void printArray(int arr[], int arr_size)
{
    for(int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}
int main(int argc, char const *argv[])
{
    int arr[] = {0,1,1,0,1,2,1,2,0,0,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, n);
    cout << "Array after Segregation: " << endl;
    printArray(arr, n);

    return 0;
}
