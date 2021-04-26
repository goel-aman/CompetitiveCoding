#include<bits/stdc++.h>
using namespace std;

// 15. 3Sum
// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
//  such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Example 2:
// Input: nums = []
// Output: []

// Example 3:
// Input: nums = [0]
// Output: []
 
// Constraints:
// 0 <= nums.length <= 3000
// -105 <= nums[i] <= 105


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int numsLength = nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<=numsLength - 3;i++){
            if(i != 0){
                if(nums[i] == nums[i - 1]){
                    continue;
                }
            }
            int j = i + 1; int k = numsLength - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j < k && nums[j + 1] == nums[j]){
                        j++;
                    }
                    while(j < k && nums[k - 1] == nums[k]){
                        k--;
                    }

                    j++;k--;
                }

                if(sum > 0){
                    k--;continue;
                }

                if(sum < 0){
                    j++;
                    continue;
                }
            }
        }
        return ans;
    }
};