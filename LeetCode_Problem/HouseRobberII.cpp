#include<bits/stdc++.h>
using namespace std;

// 213. House Robber II
// You are a professional robber planning to rob houses along a
//  street. Each house has a certain amount of money stashed. 
// All houses at this place are arranged in a circle. That means
//  the first house is the neighbor of the last one. Meanwhile, 
// adjacent houses have a security system connected, and it will
//  automatically contact the police if two adjacent houses were
//  broken into on the same night.

// Given an integer array nums representing the amount of money of
//  each house, return the maximum amount of money you can rob tonight
//  without alerting the police.

// Example 1:
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

// Example 2:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 3:
// Input: nums = [0]
// Output: 0
 
// Constraints:
// 1 <= nums.length <= 100
// 0 <= nums[i] <= 1000

class Solution {
    int dp[101][101];
    int length;
public:
    int rob(vector<int>& nums,int start,int end){
        if(start > end){
            return 0;
        }

        if(start == end){
            return nums[start];
        }

        if(dp[start][end] != -1)
        {
            return dp[start][end];
        }
        int ans = 0;
        // lets rob at start;
        ans = max(nums[start] + rob(nums,start + 2,end) ,rob(nums,start + 1,end));
        return dp[start][end] = ans;
    }

    int rob(vector<int>& nums) {
        length = nums.size();
        // if robbery happens at 0th index;
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        ans = max(nums[0] + rob(nums,2,length - 1 - 1),nums[length - 1] + rob(nums,1,length - 3));
        ans = max(ans,rob(nums,1,length-2));
        return ans;   
    }
};