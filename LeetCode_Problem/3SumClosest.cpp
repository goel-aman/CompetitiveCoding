#include<bits/stdc++.h>
using namespace std;

// 16. 3Sum Closest

// Given an array nums of n integers and an integer target, find three 
// integers in nums such that the sum is closest to target. Return the 
// sum of the three integers. You may assume that each input would have exactly one solution.

 
// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 
// Constraints:
// 3 <= nums.length <= 10^3
// -10^3 <= nums[i] <= 10^3
// -10^4 <= target <= 10^4

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int numsLength = nums.size();
        int difference = INT_MAX;
        int answer = INT_MIN;
        for(int i = 0;i<numsLength - 2;i++){
            int start = i + 1, end = numsLength - 1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == target){
                    return target;
                }
                int diff = abs(target - sum);
                if(diff < difference){
                    difference = diff;
                    answer = sum;
                }
                
                if(sum < target){
                    start++;
                    continue;
                }

                if(sum > target){
                    end--;
                    continue;
                }
            }
        }
        return answer;
    }
};