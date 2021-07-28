#include<bits/stdc++.h>
using namespace std;

// 795. Number of Subarrays with Bounded Maximum
// Given an integer array nums and two integers left and right,
//  return the number of contiguous non-empty subarrays such that
//  the value of the maximum array element in that subarray is in
//  the range [left, right].
// The test cases are generated so that the answer will fit in a
//  32-bit integer.

// Example 1:
// Input: nums = [2,1,4,3], left = 2, right = 3
// Output: 3
// Explanation: There are three subarrays that meet 
// the requirements: [2], [2, 1], [3].

// Example 2:
// Input: nums = [2,9,2,5,6], left = 2, right = 8
// Output: 7
 
// Constraints:
// 1 <= nums.length <= 105
// 0 <= nums[i] <= 109
// 0 <= left <= right <= 109

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int numsLength = nums.size();
        int ans = 0;
        int start = 0;
        int end = 0;
        int window = 0;

        while(end < numsLength){
            if(nums[end] >= left && nums[end] <= right){
                window = (end - start + 1);
                ans += window;
            }

            else if(nums[end] < left){
                ans += window;
            }

            else if(nums[end] > right){
                window = 0;
                start = end + 1;
            }

            end++;
        }
        return ans;
    }
};