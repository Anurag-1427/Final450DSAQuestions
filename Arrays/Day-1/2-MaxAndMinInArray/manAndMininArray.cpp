// https://www.techiedelight.com/find-minimum-maximum-element-array-using-minimum-comparisons/

// Performance:
// If the array has an even number of elements n, then the above solution does n/2 + 3n/2 + 2 comparisons in both best and worst-case. (Note that we have also considered n/2 comparisons done by for-loop).
// If the array has an odd number of elements n, then the above solution does (n-1)/2 + 3(n-1)/2 + 4 comparisons in both best and worst-case. (We have also considered (n-1)/2 comparisons done by for-loop).

#include<bits/stdc++.h>
using namespace std;

void findMinAndMax(vector<int> const &nums, int& min, int& max)
{
    max = INT_MIN, min = INT_MAX;
    int n = nums.size();
    
    bool odd = n&1;
    if(odd)
    {
        n--;
    }
    //compare elements in pairs i.e. nums[i] and nums[i+1]
    for(int i = 0; i < n; i=i+2)
    {
        int maximum, minimum;
        if(nums[i] > nums[i+1])     // 1st Comparison
        {
            minimum = nums[i+1];
            maximum = nums[i];
        }
        else{
            minimum = nums[i];
            maximum = nums[i+1];
        }

        //update max
        if(maximum > max)
        {    max = maximum;   }
        // update min
        if(minimum < min)
        {   min = minimum;    }

        //handle the last element if array has odd number of elements
        if(odd)
        {
            if(nums[n] > max)
            {   max = nums[n]; }
            if(nums[n] < min)
            {   min = nums[n]; }
        }
    }
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {4,7,5,1,3};
    int max, min;
    findMinAndMax(nums, min, max);
    cout << "Minimum element in array: " << min << endl;   
    cout << "Maximum element in array: " << max << endl;   
    return 0;
}