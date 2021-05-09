#include<bits/stdc++.h>
using namespace std;

// 324. Wiggle Sort II

// Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
// You may assume the input array always has a valid answer.

// Example 1:
// Input: nums = [1,5,1,1,6,4]
// Output: [1,6,1,5,1,4]
// Explanation: [1,4,1,5,1,6] is also accepted.

// Example 2:
// Input: nums = [1,3,2,2,3,1]
// Output: [2,3,1,3,1,2]
 
// Constraints:
// 1 <= nums.length <= 5 * 104
// 0 <= nums[i] <= 5000
// It is guaranteed that there will be an answer for the given input nums.
 
// Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int numsLength = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> vec(numsLength);
        
        int i,m;
        if(numsLength%2 == 0){
            i = (numsLength / 2) - 1;
            m = numsLength - 1;
        }else{
            i = numsLength / 2;
            m = numsLength - 2;
        }
        int j = numsLength - 1;
        for(int w = 0;w<numsLength;w+=2){
            vec[w] = nums[i];
            i--;
        }

        for(int m = 1;m < numsLength;m += 2){
            vec[m] = nums[j];
            j--;
        }

        for(int i=0;i<numsLength;i++){
            nums[i] = vec[i];
        }
        return ;
    }
};