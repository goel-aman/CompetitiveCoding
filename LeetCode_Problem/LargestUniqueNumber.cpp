#include<bits/stdc++.h>
using namespace std;

// 1133. Largest Unique Number
// Given an integer array nums, return the largest integer that
//  only occurs once. If no integer occurs once, return -1.

// Example 1:
// Input: nums = [5,7,3,9,4,9,8,3,1]
// Output: 8
// Explanation: The maximum integer in the array is 9 but it
//  is repeated. The number 8 occurs only once, so it is the
//  answer.

// Example 2:
// Input: nums = [9,9,8,8]
// Output: -1
// Explanation: There is no number that occurs only once.
 
// Constraints:
// 1 <= nums.length <= 2000
// 0 <= nums[i] <= 1000

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int numsLength = nums.size();
        if(numsLength == 1){
            return nums[0];
        }
        sort(nums.begin(),nums.end(),greater<int>());
        int ans = -1;
        for(int i=0;i<numsLength;i++){
            if(i == numsLength - 1){
                if(nums[i] != nums[i - 1]){
                ans = nums[i];
                }
                continue;
            }
            if(nums[i] != nums[i + 1]){
                if(i > 0){
                    if(nums[i] != nums[i - 1]){
                        ans = nums[i];
                        break;
                    }
                }else{
                    ans = nums[i];
                    break;
                }
            }
        }
        return ans;
    }
};