#include<bits/stdc++.h>
using namespace std;

// 229. Majority Element II
// Given an integer array of size n, find all
//  elements that appear more than ⌊ n/3 ⌋ times.
// Follow-up: Could you solve the problem in
//  linear time and in O(1) space?

// Example 1:
// Input: nums = [3,2,3]
// Output: [3]

// Example 2:
// Input: nums = [1]
// Output: [1]

// Example 3:
// Input: nums = [1,2]
// Output: [1,2]

// Constraints:
// 1 <= nums.length <= 5 * 104
// -109 <= nums[i] <= 109

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int numsLength = nums.size();
        int val = numsLength / 3;
        unordered_map<int,int> um;
        for(int i=0;i<numsLength;i++){
            um[nums[i]]++;
        }
        vector<int> ans;
        for(auto var : um){
            if(var.second > val){
                ans.push_back(var.first);
            }
        }
        return ans;
    }
};