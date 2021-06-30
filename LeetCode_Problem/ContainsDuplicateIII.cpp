#include<bits/stdc++.h>
using namespace std;

// 220. Contains Duplicate III
// Given an integer array nums and two integers k and t, return 
// true if there are two distinct indices i and j in the array 
// such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.

// Example 1:
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true

// Example 2:
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true

// Example 3:
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false

// Constraints:
// 0 <= nums.length <= 2 * 104
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 104
// 0 <= t <= 231 - 1

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int numsLength = nums.size();
        set<int> se(nums.begin(),nums.end());
        if(se.size() == nums.size() && t== 0){
            return false;
        }

        for(int i=0;i<numsLength;i++){
            for(int j= i + 1; j <= i + k && j < numsLength;j++){
                if(abs(nums[j] -nums[i]) <= k){
                    return true;
                }
            }
        }
        return false;
    }
};