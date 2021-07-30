#include<bits/stdc++.h>
using namespace std;

// 1262. Greatest Sum Divisible by Three
// Given an array nums of integers, we need to find the
//  maximum possible sum of elements of the array such that
//  it is divisible by three.

// Example 1:
// Input: nums = [3,6,5,1,8]
// Output: 18
// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18
//  (maximum sum divisible by 3).

// Example 2:
// Input: nums = [4]
// Output: 0
// Explanation: Since 4 is not divisible by 3, do not pick any number.

// Example 3:
// Input: nums = [1,2,3,4,4]
// Output: 12
// Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12
//  (maximum sum divisible by 3).
 
// Constraints:
// 1 <= nums.length <= 4 * 10^4
// 1 <= nums[i] <= 10^4

class Solution {
    int numsLength;
    int dp[40001][3];
public:
    int solve(vector<int>& nums,int index,int remainder){   
        if(index == numsLength){
            if(remainder != 0){
                return INT_MIN;
            }
            return 0;
        }

        if(dp[index][remainder] != -1){
            return dp[index][remainder];
        }

        // lets include
        int value1 = nums[index] + solve(nums,index + 1,(remainder + nums[index])%3);
        int value2 = solve(nums,index + 1,remainder);

        return dp[index][remainder] = max(value1,value2);
    }

    int maxSumDivThree(vector<int>& nums) {
        numsLength = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = solve(nums,0,0);
        return max(ans,0);
    }
};