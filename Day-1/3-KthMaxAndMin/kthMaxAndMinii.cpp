// https://prepinsta.com/cpp-program/find-kth-max-and-min-element-in-array/

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;

    set<int> s(arr.begin(), arr.end());
    set<int>::iterator itr = s.begin(); //s.begin() returns a pointer to first element in set
    advance(itr, k-1); // itr points to kth element (minimum) in set
    cout << "Minimum: " << *itr << endl;

    itr = s.begin();
    advance(itr, n-k); // itr points to kth element (maximum) in set
    cout << "Maximum: " << *itr << endl;
    return 0;
}
