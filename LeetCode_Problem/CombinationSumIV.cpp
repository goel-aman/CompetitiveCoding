#include<bits/stdc++.h>
using namespace std;

// Given an array of distinct integers nums and a target integer target, return 
// the number of possible combinations that add up to target.
// The answer is guaranteed to fit in a 32-bit integer.

// Example 1:
// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.

// Example 2:
// Input: nums = [9], target = 3
// Output: 0

// Constraints:
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 1000
// All the elements of nums are unique.
// 1 <= target <= 1000
 
// Follow up: What if negative numbers are allowed in the given array? How does it 
// change the problem? What limitation we need to add to the question to allow negative numbers?

class Solution {
    int numsLength;
    unordered_map<int,int> um;
public:
    int getAnswer(vector<int>& nums,int target){
        if(target < 0){
            return 0;
        }
        if(target == 0){
            return 1;
        }
        if(um.count(target) > 0){
            return um[target];
        }
        int ans = 0;
        for(int i=0;i<numsLength;i++){
            if(target >= nums[i]){
                ans += getAnswer(nums,target - nums[i]);
            }
        }

        return  um[target]= ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        numsLength = nums.size();
        um.clear();
        int value = getAnswer(nums,target);
        return value;
    }
};