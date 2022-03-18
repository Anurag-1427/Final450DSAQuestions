// https://www.codegrepper.com/code-examples/cpp/kth+max+element+in+arrays

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    const int size = 10;
    int k = 3;
    int arr[size] = {5,2,8,34,73,82,1,6,19,29};  // 1,2,5,6,8,19,29,34,73,82
    sort(arr, arr+size);
    int smallestKthElement = arr[k-1];
    int largestKthElement = arr[size-k];
    cout << "Kth Smallest Element in array: " << smallestKthElement << endl;
    cout << "Kth Largest Element in array: " << largestKthElement << endl;

    return 0;
}
