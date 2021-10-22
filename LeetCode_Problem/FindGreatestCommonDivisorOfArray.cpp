#include<bits/stdc++.h>
using namespace std;

// 1979. Find Greatest Common Divisor of Array
// Given an integer array nums, return the greatest common
//  divisor of the smallest number and largest number in nums.

// The greatest common divisor of two numbers is the largest
//  positive integer that evenly divides both numbers.

// Example 1:
// Input: nums = [2,5,6,9,10]
// Output: 2
// Explanation:
// The smallest number in nums is 2.
// The largest number in nums is 10.
// The greatest common divisor of 2 and 10 is 2.

// Example 2:
// Input: nums = [7,5,6,8,3]
// Output: 1
// Explanation:
// The smallest number in nums is 3.
// The largest number in nums is 8.
// The greatest common divisor of 3 and 8 is 1.

// Example 3:
// Input: nums = [3,3]
// Output: 3
// Explanation:
// The smallest number in nums is 3.
// The largest number in nums is 3.
// The greatest common divisor of 3 and 3 is 3.
 
// Constraints:
// 2 <= nums.length <= 1000
// 1 <= nums[i] <= 1000

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minNumber = INT_MAX;
        int maxNumber = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxNumber = max(maxNumber,nums[i]);
            minNumber = min(minNumber,nums[i]);
        }
        
        if(maxNumber%minNumber == 0){
            return minNumber;
        }
        
        int ans = 1;
        for(int i=2;i<=sqrt(minNumber);i++){
            int firstValue = i, secondNumber = minNumber / i;
            if(minNumber%i == 0){
                if(maxNumber%firstValue == 0){
                    ans = max(ans,firstValue);
                }

                if(maxNumber%secondNumber == 0){
                    ans = max(ans,secondNumber);
                }
            }
        }
        // if(ans == INT_MIN)
        return ans;
    }
};