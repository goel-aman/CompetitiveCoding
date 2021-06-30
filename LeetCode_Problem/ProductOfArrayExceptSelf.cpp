#include<bits/stdc++.h>
using namespace std;

// 238. Product of Array Except Self
// Given an integer array nums, return an array answer 
// such that answer[i] is equal to the product of all 
// the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed
//  to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and 
// without using the division operation.

// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]

// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 
// Constraints:
// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The product of any prefix or suffix of nums
//  is guaranteed to fit in a 32-bit integer.
 
// Follow up: Can you solve the problem in O(1) extra space 
// complexity? (The output array does not count as extra space
//  for space complexity analysis.)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        prefix.push_back(1);
        int mul = 1;
        int numsLength = nums.size();
        for(int i=0;i<numsLength;i++){
            mul *= nums[i];
            prefix.push_back(mul);
        }

        stack<int> st;
        st.push(1);
        mul = 1;
        for(int i=numsLength - 1;i>=0;i--){
            mul *= nums[i];
            st.push(mul);
        }

        vector<int> sufix;
        while(!st.empty()){
            sufix.push_back(st.top());
            st.pop();
        }

        vector<int> ret;
        for(int i=0;i<numsLength;i++){
            ret.push_back(prefix[i] * sufix[i + 1]);

        }
        return ret;
    }
};