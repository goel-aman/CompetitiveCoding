#include<bits/stdc++.h>
using namespace std;

// 280. Wiggle Sort
// Given an integer array nums, reorder it such 
// that nums[0] <= nums[1] >= nums[2] <= nums[3]....
// You may assume the input array always has a
//  valid answer.

// Example 1:
// Input: nums = [3,5,2,1,6,4]
// Output: [3,5,1,6,2,4]
// Explanation: [1,6,2,5,3,4] is also accepted.

// Example 2:
// Input: nums = [6,6,5,6,3,8]
// Output: [6,6,5,6,3,8]
 
// Constraints:
// 1 <= nums.length <= 5 * 104
// 0 <= nums[i] <= 104
// It is guaranteed that there will be an answer for the given input nums.
// Follow up: Could you solve the problem in O(n) time complexity?

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int numsLength = nums.size();
        vector<int> ans(numsLength);
        
        sort(nums.begin(),nums.end());
        
        int index = 0;
        int currentPosition = 0;
        while(currentPosition < numsLength){
            ans[currentPosition] = nums[index];
            index++;
            currentPosition += 2;
        }
        
        index = numsLength - 1;
        currentPosition = 1;
        while(currentPosition < numsLength){
            ans[currentPosition] = nums[index];
            index--;
            currentPosition += 2;
        }
        
        for(int i=0;i<numsLength;i++){
            nums[i] = ans[i];
        }
        return ;
    }
};