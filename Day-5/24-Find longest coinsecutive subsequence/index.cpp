//We are using an optimal approach which furthur using a HashSet
// T.C:O(n) - The T.C of this approach is O(N) because we traverse each consecutive subsequence only once.
// S.C:O(n) - The S.C of the above approach is O(N) because we are maintaining a HashSet.

// With the help of Priority Queue we can solve this in O(n logn) time but prefer that accordingly.

#include<bits/stdc++.h>
using namespace std;
int longestConsecutive(vector < int > & nums) {
  set < int > hashSet;
  for (int num: nums) {
    hashSet.insert(num);
  }

  int longestStreak = 0;

  for (int num: nums) {
    if (!hashSet.count(num - 1)) {
      int currentNum = num;
      int currentStreak = 1;

      while (hashSet.count(currentNum + 1)) {
        currentNum += 1;
        currentStreak += 1;
      }

      longestStreak = max(longestStreak, currentStreak);
    }
  }

  return longestStreak;
}
int main() {
  vector<int> arr{100,200,1,2,3,4};
  int lon = longestConsecutive(arr);
  cout << "The longest consecutive sequence is " << lon << endl;

}