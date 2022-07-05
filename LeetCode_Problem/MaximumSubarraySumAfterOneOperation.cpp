#include<bits/stdc++.h>
using namespace std;

// 1746. Maximum Subarray Sum After One Operation
// You are given an integer array nums. You must perform exactly 
// one operation where you can replace one element nums[i] with
//  nums[i] * nums[i]. 

// Return the maximum possible subarray sum after exactly one 
// operation. The subarray must be non-empty.

// Example 1:
// Input: nums = [2,-1,-4,-3]
// Output: 17
// Explanation: You can perform the operation on index 2 (0-indexed)
//  to make nums = [2,-1,16,-3]. Now, the maximum subarray sum
//  is 2 + -1 + 16 = 17.

// Example 2:
// Input: nums = [1,-1,1,1,-1,-1,1]
// Output: 4
// Explanation: You can perform the operation on index 1 (0-indexed) 
// to make nums = [1,1,1,1,-1,-1,1]. Now, the maximum subarray sum 
// is 1 + 1 + 1 + 1 = 4.
 
// Constraints:
// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int numsLength = nums.size();
        int right[100001];
        memset(right,0,sizeof(right));
        int leftSum = 0;
        for(int i= numsLength - 1;i>=0;i--){
            right[i] = max(0,right[i + 1] + nums[i]);
        }
        int res = 0;
        for(int i = 0;i<numsLength;i++){
            int value = (nums[i] * nums[i]) + leftSum + right[i + 1];
            res = max(res,value);
            leftSum = max(0,nums[i] + leftSum);
        }
        return res;
    }
};