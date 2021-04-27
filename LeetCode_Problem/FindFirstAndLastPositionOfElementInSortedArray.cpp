#include<bits/stdc++.h>
using namespace std;

// // 34. Find First and Last Position of Element in Sorted Array
// Given an array of integers nums sorted in ascending order, find the 
// starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// Follow up: Could you write an algorithm with O(log n) runtime complexity?

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]
 
// Constraints:
// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums is a non-decreasing array.
// -109 <= target <= 109

class Solution {
public:
    
    int findLowerEnd(vector<int>& nums,int& target){
        int numsLength = nums.size();
        int start = 0 , end = numsLength - 1;
        int answer = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target){
                answer = mid;
                end = mid - 1;
                continue;
            }

            if(nums[mid] > target){
                end = mid - 1;
                continue;
            }

            if(nums[mid] < target){
                start = mid + 1;
                continue;
            }
        }
        return answer;
    }
    
    int findHighEnd(vector<int>& nums,int &target){
        int numsLength = nums.size();
        int start = 0 , end = numsLength - 1;
        int answer = -1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target){
                answer = mid;
                start = mid + 1;
                continue;
            }

            if(nums[mid] > target){
                end = mid - 1;
                continue;
            }

            if(nums[mid] < target){
                start = mid + 1;
                continue;
            }
        }
        return answer;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerEnd = findLowerEnd(nums,target);
        int higherEnd = findHighEnd(nums,target);
        return {lowerEnd,higherEnd};
    }
};