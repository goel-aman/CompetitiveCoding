#include<bits/stdc++.h>
using namespace std;

// 368. Largest Divisible Subset
// Given a set of distinct positive integers nums, return
//  the largest subset answer such that every pair 
// (answer[i], answer[j]) of elements in this subset
//  satisfies:
// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple solutions, return any of them.

// Example 1:
// Input: nums = [1,2,3]
// Output: [1,2]
// Explanation: [1,3] is also accepted.

// Example 2:
// Input: nums = [1,2,4,8]
// Output: [1,2,4,8]
 
// Constraints:
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 2 * 109
// All the integers in nums are unique.

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int numsLength = nums.size();
        if(nums.size() == 1){
            return nums;
        }
        sort(nums.begin(),nums.end());
        vector<int> ans;
        vector<int> dp(numsLength,1);
        int maxValue = 1;
        int maxIndex = 0;
        for(int i=0;i<numsLength;i++){
            for(int j = 0;j<= i - 1;j++){
                if(nums[i]%nums[j] == 0){
                    dp[i] = max(dp[i],dp[j] + 1);
                    if(dp[i] > maxValue){
                        maxValue = dp[i];
                        maxIndex = i;
                    }
                }
            }
        }

        int maxVal = maxValue;
        int previous = nums[maxIndex];
        for(int i=maxIndex;i>=0;i--){
            if(dp[i] == maxVal && previous%nums[i] == 0){
                ans.push_back(nums[i]);
                maxVal--;
                previous = nums[i];
            }
        }
        return ans;
    }
};