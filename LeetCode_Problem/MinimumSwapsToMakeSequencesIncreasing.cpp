#include<bits/stdc++.h>
using namespace std;

// 801. Minimum Swaps To Make Sequences Increasing
// You are given two integer arrays of the same length 
// nums1 and nums2. In one operation, you are allowed 
// to swap nums1[i] with nums2[i].
// For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4],
//  you can swap the element at i = 3 to obtain nums1 = [1,2,3,4]
//  and nums2 = [5,6,7,8].
// Return the minimum number of needed operations to make nums1
//  and nums2 strictly increasing. The test cases are generated 
// so that the given input always makes it possible.

// An array arr is strictly increasing if and only if 
// arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].

// Example 1:
// Input: nums1 = [1,3,5,4], nums2 = [1,2,3,7]
// Output: 1
// Explanation: 
// Swap nums1[3] and nums2[3]. Then the sequences are:
// nums1 = [1, 3, 5, 7] and nums2 = [1, 2, 3, 4]
// which are both strictly increasing.

// Example 2:
// Input: nums1 = [0,3,5,8,9], nums2 = [2,1,4,6,9]
// Output: 1
 
// Constraints:
// 2 <= nums1.length <= 105
// nums2.length == nums1.length
// 0 <= nums1[i], nums2[i] <= 2 * 105


class Solution {
    int nums1Length;
    int dp[100001][2];
public:
    // 1 means it was swapped , 0 means it was not swapped.
    int solve(vector<int>& nums1,vector<int>& nums2,int index,int swapped,int prevA,int prevB){
        if(index == nums1Length){
            return 0;
        }

        if(dp[index][swapped] != -1){
            return dp[index][swapped];
        }

        int minSwap = INT_MAX;

        if(nums1[index] > prevA && nums2[index] > prevB){
            minSwap = min(minSwap,solve(nums1,nums2,index + 1,0,nums1[index],nums2[index]));
        }
        
        // now we are going to swap.
        if(nums1[index] > prevB && nums2[index] > prevA){
            minSwap = min(minSwap,solve(nums1,nums2,index + 1,1,nums2[index],nums1[index]) + 1);
        }

        return dp[index][swapped] = minSwap;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1Length = nums1.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0,-1,-1);
    }
};