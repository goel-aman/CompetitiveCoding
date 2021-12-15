#include<bits/stdc++.h>
using namespace std;

// 35. Search Insert Position
// Given a sorted array of distinct integers and a target
//  value, return the index if the target is found. If 
// not, return the index where it would be if it were 
// inserted in order.
// You must write an algorithm with O(log n) runtime
//  complexity.

// Example 1:
// Input: nums = [1,3,5,6], target = 5
// Output: 2

// Example 2:
// Input: nums = [1,3,5,6], target = 2
// Output: 1

// Example 3:
// Input: nums = [1,3,5,6], target = 7
// Output: 4
 
// Constraints:
// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums contains distinct values sorted in ascending order.
// -104 <= target <= 104

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int numsLength = nums.size();
        int start = 0,end = numsLength - 1;
        int leastValue = -1;
        int ans = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(nums[mid] == target){
                ans = mid;
                break;
            }
            
            if(nums[mid] > target){
                end = mid - 1;
                leastValue = mid;
                continue;
            }
            
            if(nums[mid] < target){
                start = mid + 1;
                leastValue = mid + 1;
                continue;
            }
        }
        if(ans != -1){
            return ans;
        }
        return leastValue;
    }
};