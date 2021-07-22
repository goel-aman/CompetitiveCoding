#include<bits/stdc++.h>
using namespace std;

// 659. Split Array into Consecutive Subsequences
// You are given an integer array nums that is 
// sorted in non-decreasing order.
// Determine if it is possible to split nums into
//  one or more subsequences such that both of the
//  following conditions are true:

// Each subsequence is a consecutive increasing sequence
//  (i.e. each integer is exactly one more than the 
// previous integer).
// All subsequences have a length of 3 or more.
// Return true if you can split nums according to the above
//  conditions, or false otherwise.

// A subsequence of an array is a new array that is formed 
// from the original array by deleting some (can be none) of
//  the elements without disturbing the relative positions
//  of the remaining elements. (i.e., [1,3,5] is a subsequence
//  of [1,2,3,4,5] while [1,3,2] is not).

// Example 1:
// Input: nums = [1,2,3,3,4,5]
// Output: true
// Explanation: nums can be split into the following subsequences:
// [1,2,3,3,4,5] --> 1, 2, 3
// [1,2,3,3,4,5] --> 3, 4, 5

// Example 2:
// Input: nums = [1,2,3,3,4,4,5,5]
// Output: true
// Explanation: nums can be split into the following subsequences:
// [1,2,3,3,4,4,5,5] --> 1, 2, 3, 4, 5
// [1,2,3,3,4,4,5,5] --> 3, 4, 5

// Example 3:
// Input: nums = [1,2,3,4,4,5]
// Output: false
// Explanation: It is impossible to split nums into consecutive
//  increasing subsequences of length 3 or more.
 
// Constraints:
// 1 <= nums.length <= 104
// -1000 <= nums[i] <= 1000
// nums is sorted in non-decreasing order.

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int numsLength = nums.size();
        unordered_map<int,int> freq;
        for(auto var : nums){
            freq[var]++;
        }

        unordered_map<int,int> canBeAppended;
        
        for(int i=0;i<numsLength;i++){
            if(freq[nums[i]] == 0){
                continue;
            }
            if(canBeAppended.count(nums[i]) > 0 && canBeAppended[nums[i]] >= 1){
                canBeAppended[nums[i]]--;
                canBeAppended[nums[i] + 1]++;
            }
            else if(freq.count(nums[i] + 1) > 0 && freq.count(nums[i] + 2) > 0 && freq[nums[i] + 1] >= 1 && freq[nums[i] + 2] >= 1) {
                freq[nums[i] + 1]--;
                freq[nums[i] + 2]--;
                canBeAppended[nums[i] + 3]++;
            }
            else{
                return false;
            }

            freq[nums[i]]--;
        }
        return true;
    }
};