#include<bits/stdc++.h>
using namespace std;

// 1696. Jump Game VI
// You are given a 0-indexed integer array nums
//  and an integer k.
// You are initially standing at index 0. In one move,
//  you can jump at most k steps forward without going
//  outside the boundaries of the array. That is, you can
//  jump from index i to any index in the 
// range [i + 1, min(n - 1, i + k)] inclusive.
// You want to reach the last index of the array (index n - 1).
//  Your score is the sum of all nums[j] for each index j you
//  visited in the array.
// Return the maximum score you can get.

// Example 1:
// Input: nums = [1,-1,-2,4,-7,3], k = 2
// Output: 7
// Explanation: You can choose your jumps forming the subsequence
//  [1,-1,4,3] (underlined above). The sum is 7.

// Example 2:
// Input: nums = [10,-5,-2,4,0,3], k = 3
// Output: 17
// Explanation: You can choose your jumps forming the 
// subsequence [10,4,3] (underlined above). The sum is 17.

// Example 3:
// Input: nums = [1,-5,-20,4,-1,3,-6,-3], k = 2
// Output: 0
 
// Constraints:
// 1 <= nums.length, k <= 105
// -104 <= nums[i] <= 104

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int numsLength = nums.size();
        deque<int> dq;
        vector<int> dp(numsLength,INT_MIN);
        dp[numsLength - 1] = nums[numsLength - 1];
        dq.push_back(numsLength - 1);
        
        for(int i=numsLength - 2;i>=0;i--){
            while(!dq.empty() && dq.front() > i + k){
                dq.pop_front();
            }

            dp[i] = max(dp[i],dp[dq.front()] + nums[i]);
            while(!dq.empty() && dp[dq.back()] < dp[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return dp[0];
    }
};