#include<bits/stdc++.h>
using namespace std;

// 813. Largest Sum of Averages
// You are given an integer array nums and an integer k.
// You can partition the array into at most k non-empty 
// adjacent subarrays. The score of a partition is the sum
//  of the averages of each subarray.
// Note that the partition must use every integer in nums,
//  and that the score is not necessarily an integer.

// Return the maximum score you can achieve of all the
//  possible partitions. Answers within 10-6 of the actual 
// answer will be accepted.

// Example 1:
// Input: nums = [9,1,2,3,9], k = 3
// Output: 20.00000
// Explanation: 
// The best choice is to partition nums into
//  [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
// We could have also partitioned nums into [9, 1], [2], [3, 9], for example.
// That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.

// Example 2:
// Input: nums = [1,2,3,4,5,6,7], k = 4
// Output: 20.50000
 
// Constraints:
// 1 <= nums.length <= 100
// 1 <= nums[i] <= 104
// 1 <= k <= nums.length

class Solution {
    int numsLength;
    int ans = 0;
    double dp[101][101];
public:
    double solve(vector<int>& nums,int k,int index){
        if(index == numsLength){
            return 0;
        }

        if(k < 0){
            return INT_MAX;
        }

        if(k == 1){
            double count = 0;
            double sum = 0;
            for(int i=index;i<numsLength;i++){
                count += 1;
                sum += nums[i];
            }

            double value = sum / count;
            return value;
        }

        if(dp[index][k] != -1){
            return dp[index][k];
        }

        double ans = INT_MIN;
        double sum = 0;
        double count = 0;
        for(int i=index;i<numsLength;i++){
            sum += nums[i];
            count += 1;

            double tempValue = (sum / count);
            double subAnswer = solve(nums,k - 1,i + 1);
            ans = max(ans,subAnswer + tempValue);
        }

        return dp[index][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        numsLength = nums.size();
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j] = -1;
            }
        }
        double value = solve(nums,k,0);
        return value;
    }
};