// Most efficient method
// Thorugh Hashing
// Also 'twoSum' function helps in leetcode exactly
// T.C: O(N) and  S.C: O(N)
#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{

    vector<int> res;
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i)
    {

        if (mp.find(target - nums[i]) != mp.end())
        {

            res.emplace_back(i);
            res.emplace_back(mp[target - nums[i]]);
            return res;
        }

        mp[nums[i]] = i;
    }

    return res;
}
int main()
{
    vector<int> nums{2, 3, 1, 4};
    int target = 4;
    vector<int> ans;
    ans = twoSum(nums, target);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}