#include<bits/stdc++.h>
using namespace std;

// 665. Non-decreasing Array
// Given an array nums with n integers, your task is to check
//  if it could become non-decreasing by modifying at most 
// one element.
// We define an array is non-decreasing if nums[i] <= nums[i + 1]
//  holds for every i (0-based) such that (0 <= i <= n - 2).

// Example 1:
// Input: nums = [4,2,3]
// Output: true
// Explanation: You could modify the first 4 to 1
//  to get a non-decreasing array.

// Example 2:
// Input: nums = [4,2,1]
// Output: false
// Explanation: You can't get a non-decreasing 
// array by modify at most one element.
 
// Constraints:
// n == nums.length
// 1 <= n <= 104
// -105 <= nums[i] <= 105
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int pos= -1;
        int numsLength = nums.size();
        for(int i=0;i<numsLength - 1;i++){
            if(nums[i] > nums[i + 1]){
                if(pos != -1){
                    return false;
                }
                pos = i;
            }
        }
        
        return (pos == -1 || pos == 0 || pos == numsLength - 2 || nums[pos] <= nums[pos + 2] || nums[pos - 1] <= nums[pos + 1]);
    }
};