#include<bits/stdc++.h>
using namespace std;

// 1085. Sum of Digits in the Minimum Number
// Given an integer array nums, return 0 if the sum of the 
// digits of the minimum integer in nums is odd, or 1 otherwise.

// Example 1:
// Input: nums = [34,23,1,24,75,33,54,8]
// Output: 0
// Explanation: The minimal element is 1, and the sum of those
//  digits is 1 which is odd, so the answer is 0.

// Example 2:
// Input: nums = [99,77,33,66,55]
// Output: 1
// Explanation: The minimal element is 33, and the sum of those
//  digits is 3 + 3 = 6 which is even, so the answer is 1.
 
// Constraints:
// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
        int numsLength = nums.size();
        int minValue = INT_MAX;
        for(int i=0;i<numsLength;i++){
            minValue = min(minValue,nums[i]);
        }
        
        int sum = 0;
        
        string tempValue = to_string(minValue);
        
        for(int i=0;i<tempValue.length();i++){
            sum += (tempValue[i] - '0');
        }
        
        return (sum%2 == 0) ? 1 : 0;
    }
};