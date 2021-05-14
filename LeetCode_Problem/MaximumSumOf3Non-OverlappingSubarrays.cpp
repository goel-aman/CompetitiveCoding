#include<bits/stdc++.h>
using namespace std;

// Given an integer array nums and an integer k, find three non-overlapping 
// subarrays of length k with maximum sum and return them.

// Return the result as a list of indices representing the starting position 
// of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

// Example 1:
// Input: nums = [1,2,1,2,6,7,5,1], k = 2
// Output: [0,3,5]
// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.

// Example 2:
// Input: nums = [1,2,1,2,1,2,1,2,1], k = 2
// Output: [0,2,4]
 
// Constraints:
// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] < 216
// 1 <= k <= floor(nums.length / 3)

class Solution {
    int numsLength;
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        numsLength = nums.size();
        vector<int> sum,left(numsLength,0), right(numsLength,numsLength - k);
        sum.push_back(0);
        // cout<<"hello"<<endl;
        // prefix calculation
        for(int i=1;i<=numsLength;i++){
            sum.push_back(sum[i - 1] + nums[i-1]);
        }
        // cout<<"hello"<<endl;
        // left calculation
        int tillNow = 0;
        for(int i=k - 1;i<numsLength;i++){
            // cout<<"value of i is "<<i<<endl;
            if(sum[i + 1] - sum[i + 1 - k] > tillNow){
                // cout<<"hello world from aman"<<endl;
                tillNow = sum[i + 1] - sum[i + 1 - k];
                left[i] = i - (k - 1) ;
            }else{
                // cout<<"hello aman"<<endl;
                left[i] = left[i - 1];
            }
        }
        // cout<<"hello world"<<endl;
        // right Calculation
        tillNow = 0;
        for(int i = numsLength - k;i >= 0;i--){
            if(sum[i + k] - sum[i] >= tillNow){
                tillNow = sum[i + k] - sum[i];
                right[i] = i;
            }else{
                right[i] = right[i + 1];
            }
        }

        // middle portion
        vector<int> ans;
        int value = 0;
        for(int i = k;i<= numsLength - 2*k;i++){
            if((sum[i + k] - sum[i])  +  (sum[left[i - 1] + k] - sum[left[i - 1]])  +  (sum[right[i + k] + k] - sum[right[i + k]]) > value){
                value = (sum[i + k] - sum[i])  +  (sum[left[i - 1] + k] - sum[left[i - 1]])  +  (sum[right[i + k] + k] - sum[right[i + k]]);
                ans = {left[i - 1],i,right[i + k]};
            }
        }
        return ans;
    }
};