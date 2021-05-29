#include<bits/stdc++.h>
using namespace std;

// 78. Subsets
// Given an integer array nums of unique elements, return
//  all possible subsets (the power set).

// The solution set must not contain duplicate subsets. 
// Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]
 
// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// All the numbers of nums are unique.

class Solution {
    int numsLength;
public:
    void subset(vector<int>& nums,vector<vector<int>>& res,int index,vector<int>& temp){
        if(index == numsLength){
            res.push_back(temp);
            return ;
        }

        temp.push_back(nums[index]);
        subset(nums,res,index + 1,temp);
        temp.pop_back();

        subset(nums,res,index + 1,temp);
        return ;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        numsLength = nums.size();
        vector<vector<int>> st;
        vector<int> temp;
        subset(nums,st,0,temp);
        return st;
    }
};