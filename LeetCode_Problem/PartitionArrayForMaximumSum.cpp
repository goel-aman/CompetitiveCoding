#include<bits/stdc++.h>
using namespace std;

// 1043. Partition Array for Maximum Sum
// Given an integer array arr, partition the array 
// into (contiguous) subarrays of length at most k.
//  After partitioning, each subarray has their values
//  changed to become the maximum value of that subarray.

// Return the largest sum of the given array after 
// partitioning. Test cases are generated so that the 
// answer fits in a 32-bit integer.

// Example 1:
// Input: arr = [1,15,7,9,2,5,10], k = 3
// Output: 84
// Explanation: arr becomes [15,15,15,9,10,10,10]

// Example 2:
// Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
// Output: 83

// Example 3:
// Input: arr = [1], k = 1
// Output: 1
 
// Constraints:
// 1 <= arr.length <= 500
// 0 <= arr[i] <= 109
// 1 <= k <= arr.length

class Solution {
    int dp[501][501];
public:
    int solve(vector<int>& arr,int start,int end,int &k){
        if(start == end){
            return arr[start];
        }

        if(start > end){
            return 0;
        }

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        int value = 0;
        int maxValue = INT_MIN;
        for(int i=0;i<k;i++){
            if(start + i <= end){
                maxValue = max(maxValue,arr[start + i]);
                int temp = (i + 1) * maxValue;
                value = max(value,temp  +solve(arr,start + i + 1,end,k));
            }else{
                break;
            }
        }
        return dp[start][end] = value;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int arrLength = arr.size();
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,arrLength - 1,k);
    }
};