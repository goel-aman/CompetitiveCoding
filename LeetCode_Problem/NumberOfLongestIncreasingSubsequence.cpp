#include<bits/stdc++.h>
using namespace std;

// 673. Number of Longest Increasing Subsequence
// Given an integer array nums, return the number
//  of longest increasing subsequences.
// Notice that the sequence has to be strictly increasing.

// Example 1:
// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences 
// are [1, 3, 4, 7] and [1, 3, 5, 7].

// Example 2:
// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of longest continuous increasing 
// subsequence is 1, and there are 5 subsequences' length 
// is 1, so output 5.

// Constraints:
// 1 <= nums.length <= 2000
// -106 <= nums[i] <= 106

class element{
    public:
    int length = 0;
    int count = 0;
};

class Solution {
    element dp[2001];
    int numsLength;
public:
    element findLength(int index,vector<int>& nums){
        if(index == numsLength){
            return {0,0};
        }
        if(dp[index].count != 0 && dp[index].length != 0){
            return dp[index];
        }
        element ans = {0,0};

        for(int i=index + 1;i<numsLength;i++){
            if(nums[i] > nums[index]){
                element front = findLength(i,nums);
                if(front.length > ans.length){
                    ans.length = front.length;
                    ans.count = front.count;
                    continue;
                }
                if(front.length == ans.length){
                    ans.count = ans.count + front.count;
                    continue;
                }
            }
        }

        ans.length = ans.length + 1;
        if(ans.count == 0){
            ans.count = 1;
        }
        dp[index] = ans;
        return ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        numsLength = nums.size();
        // memset(dp,-1,sizeof(dp));
        element ans = {0,0};
        for(int i=0;i<numsLength;i++){
            element val = findLength(i,nums);
            if(val.length > ans.length){
                ans.length = val.length;
                ans.count = val.count;
                continue;
            }
            if(val.length == ans.length){
                ans.length = val.length;
                ans.count = ans.count + val.count;
                continue;
            }
        }
        return ans.count;
    }
};