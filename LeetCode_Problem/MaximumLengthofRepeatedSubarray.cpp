#include<bits/stdc++.h>
using namespace std;

// 718. Maximum Length of Repeated Subarray

// Given two integer arrays nums1 and nums2, return the
//  maximum length of a subarray that appears in both arrays.

// Example 1:
// Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
// Output: 3
// Explanation: The repeated subarray with maximum length is [3,2,1].

// Example 2:
// Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
// Output: 5
 
// Constraints:
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 100

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int nums1Length = nums1.size();
        int nums2Length = nums2.size();
        int dp[nums1Length + 1][nums2Length + 1];
        memset(dp,0,sizeof(dp));
        int answer = 0;
        for(int i=1;i<=nums1Length;i++){
            for(int j=1;j<=nums2Length;j++){
                if(nums1[i -1] == nums2[j - 1]){
                    dp[i][j] = max(dp[i][j], 1 + dp[i -1][j- 1]);
                    answer = max(answer,dp[i][j]);
                }
            }
        }
        return answer;
    }
};