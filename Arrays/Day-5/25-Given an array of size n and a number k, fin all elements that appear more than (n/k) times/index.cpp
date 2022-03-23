// T.C: O(n) - as we are traversing through the array only once.
// S.C: O(n) - if all the elements are unique in the array so every element will take space.

// Using Maps
#include <bits/stdc++.h>
using namespace std;

void solution(int arr[], int n, int k) {
  int comp = n / k;
  unordered_map < int, int > mp;
  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }
  for (auto x: mp) {
    if (x.second > comp)
      cout << x.first << " ";
  }

}
int main() {
  // your code goes here
  int n=8, k=4;
  int arr[]={3,1,2,2,1,2,3,3};
  
  solution(arr, n, k);
 
}