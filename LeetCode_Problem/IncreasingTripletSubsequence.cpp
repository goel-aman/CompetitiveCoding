#include<bits/stdc++.h>
using namespace std;

// 334. Increasing Triplet Subsequence

// Given an integer array nums, return true 
// if there exists a triple
//  of indices (i, j, k) such that i < j < k and 
// nums[i] < nums[j] < nums[k]. If no such 
// indices exists, return false.

// Example 1:
// Input: nums = [1,2,3,4,5]
// Output: true
// Explanation: Any triplet where i < j < k is valid.

// Example 2:
// Input: nums = [5,4,3,2,1]
// Output: false
// Explanation: No triplet exists.

// Example 3:
// Input: nums = [2,1,5,0,4,6]
// Output: true
// Explanation: The triplet (3, 4, 5) is valid because
//  nums[3] == 0 < nums[4] == 4 < nums[5] == 6.

// Constraints:
// 1 <= nums.length <= 5 * 105
// -231 <= nums[i] <= 231 - 1
 
// Follow up: Could you implement a solution that 
// runs in O(n) time complexity and O(1) space complexity?

class Solution {
    int numsLength;
    int dp[500001];
public:

    int increasingTrip(vector<int>& nums,int index){
        if(index == numsLength){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int val = nums[index];
        int ans = 0;
        for(int j = index + 1;j<numsLength;j++){
            if(nums[j] > val){
                ans = max(ans,increasingTrip(nums,j));
            }
            if(ans >= 3){
                dp[index] = 3;
                return dp[index];
            }
        }

        return dp[index] = (ans + 1);
    }

    bool increasingTriplet(vector<int>& nums) {
        numsLength = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        for(int i=0;i<numsLength;i++){
            ans = max(ans,increasingTrip(nums,i));
            if(ans >= 3){
                return true;
            }
        }
        return false;
    }
};


// Alternate Solution

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int numsLength = nums.size();
        int first = INT_MAX , second = INT_MAX;
        for(int i=0;i<numsLength;i++){
            if(nums[i] <= first){
                first = nums[i];
            }
            else if(nums[i] <= second){
                second = nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }
};