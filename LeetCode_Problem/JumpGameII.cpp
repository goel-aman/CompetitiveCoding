#include<bits/stdc++.h>
using namespace std;

// 45. Jump Game II

// Given an array of non-negative integers nums, you are initially positioned
//  at the first index of the array.
// Each element in the array represents your maximum jump length at 
// that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. 
// Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2
 
// Constraints:
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 1000

class Solution {
    int numsLength;
    int dp[10001];
public:
    int minJump(vector<int>& nums,int index){
        if(index >= numsLength - 1){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        if(nums[index] == 0){
            return dp[index] = INT_MAX;
        }
        int ans = INT_MAX;
        for(int i=1;i<=nums[index];i++){
            ans = min(ans,minJump(nums,index + i));
        }
        if(ans == INT_MAX){
            return dp[index] = INT_MAX;
        }
        return dp[index] = (ans + 1);
    }

    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        numsLength = nums.size();
        return minJump(nums,0);
    }
};