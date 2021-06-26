#include<bits/stdc++.h>
using namespace std;

// 55. Jump Game
// Given an array of non-negative integers nums, you are initially 
// positioned at the first index of the array.

// Each element in the array represents your maximum jump 
// length at that position.

// Determine if you are able to reach the last index.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum 
// jump length is 0, which makes it impossible to reach the last index.

// Constraints:
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

class Solution {
    int dp[10001];
    int numsLength;
public:
    bool canJump(vector<int>& nums,int index){
        if(index >= numsLength - 1){
            return true;
        }

        if(nums[index] == 0){
            return false;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        if(index + nums[index] >= numsLength - 1){
            return dp[index]= true;
        }
        bool ans = false;
        for(int i=1;i<=nums[index];i++){
            ans = (ans | canJump(nums,index + i));
            if(ans == true){
                return dp[index] = ans;
            }
        }

        return dp[index]= ans;
    }

    bool canJump(vector<int>& nums) {
        numsLength = nums.size();
        memset(dp,-1,sizeof(dp));
        return canJump(nums,0);
    }
};