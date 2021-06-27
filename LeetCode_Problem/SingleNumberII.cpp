#include<bits/stdc++.h>
using namespace std;

// 137. Single Number II

// Given an integer array nums where every element appears three times 
// except for one, which appears exactly once. Find the single element
//  and return it.

// You must implement a solution with a linear runtime complexity and 
// use only constant extra space.

// Example 1:
// Input: nums = [2,2,3,2]
// Output: 3

// Example 2:
// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
 
// Constraints:
// 1 <= nums.length <= 3 * 104
// -231 <= nums[i] <= 231 - 1
// Each element in nums appears exactly three times except for 
// one element which appears once.

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int numsLength = nums.size();
        for(int i=0;i<numsLength;i+=3){
            if(i + 1 < numsLength && nums[i] != nums[i + 1]){
                return nums[i];
            }
        }
        return nums[numsLength - 1];
    }
};