#include<bits/stdc++.h>
using namespace std;

// 376. Wiggle Subsequence

// A wiggle sequence is a sequence where the differences between successive numbers
//  strictly alternate between positive and negative. The first difference (if one exists)
//  may be either positive or negative. A sequence with one element and a sequence with two
//   non-equal elements are trivially wiggle sequences.

// For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence because the differences
//  (6, -3, 5, -7, 3) alternate between positive and negative.
// In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
// The first is not because its first two differences are positive, and the 
// second is not because its last difference is zero.
// A subsequence is obtained by deleting some elements (possibly zero) from the 
// original sequence, leaving the remaining elements in their original order.

// Given an integer array nums, return the length of the longest wiggle subsequence of nums.

 

// Example 1:

// Input: nums = [1,7,4,9,2,5]
// Output: 6
// Explanation: The entire sequence is a wiggle sequence with differences (6, -3, 5, -7, 3).
// Example 2:

// Input: nums = [1,17,5,10,13,15,10,5,16,8]
// Output: 7
// Explanation: There are several subsequences that achieve this length.
// One is [1, 17, 10, 13, 10, 16, 8] with differences (16, -7, 3, -3, 6, -8).
// Example 3:

// Input: nums = [1,2,3,4,5,6,7,8,9]
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000

class Solution {
    int numsLength;
    unordered_map<string,int> um;
public:
    // if great == 1 then it means next element should be greater 
    // , 0 means the next element should be strcitly less than.
    int wiggle(vector<int>& nums,int index,int prev,int great){
        if(index == numsLength){
            return 0;
        }
        
        string s = to_string(index) + ";" + to_string(prev) + ";" + to_string(great);
        if(um.count(s) > 0)
        {
            return um[s];
        }
        int ans1 = INT_MIN;
        if(great && nums[index] > prev){
            ans1 = max(ans1, 1 + wiggle(nums,index + 1,nums[index],(!great) ));
        }
        
        if((!great) && nums[index] < prev){
            ans1 = max(ans1,1 + wiggle(nums,index + 1,nums[index] ,(!great)));
        }

        int ans2 = wiggle(nums,index + 1, prev,great);
        return um[s] = max(ans1,ans2);
    }

    int wiggleMaxLength(vector<int>& nums) {
        numsLength = nums.size();
        if(numsLength <= 1){
            return 1;
        }
        
        int value = INT_MIN;
        for(int i=0;i<numsLength;i++){
            value = max(value,max(wiggle(nums,i,INT_MAX,0),wiggle(nums,i,INT_MIN,1)));
        }
        
        return value;
    }
};