// // Next Permutation

// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

// The replacement must be in place and use only constant extra memory.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
// Example 4:

// Input: nums = [1]
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        for(;i>=0;i--)
        {
            if(nums[i] < nums[i + 1]){
                break;
            }
        }
        if(i == - 1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int storeI = i;
        i = n - 1;
        for(;i>=0;i--){
            if(nums[i] > nums[storeI] ){
                break;
            }
        }
        int var = nums[i];
        nums[i] = nums[storeI];
        nums[storeI] =var; 
        // swap(nums[storeI],nums[i]);
        reverse(nums.begin() + storeI + 1,nums.end());
        return ;
    }
};