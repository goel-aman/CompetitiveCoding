#include<bits/stdc++.h>
using namespace std;

// 90. Subsets II

// Given an integer array nums that may contain duplicates, return all
//  possible subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

// Constraints:
// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

class Solution {
    int numsLength;
public:
    void subsets(vector<int>& nums,int index,set<vector<int>>& uniqueVector,vector<int>& temp){
        if(index == numsLength){
            uniqueVector.insert(temp);
            return ;
        }

        // lets take element on this index.
        temp.push_back(nums[index]);
        subsets(nums,index + 1,uniqueVector,temp);
        temp.pop_back();

        // lets omit the element on the current index.
        subsets(nums,index + 1,uniqueVector,temp);
        return ;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> uniqueVector;
        sort(nums.begin(),nums.end());
        numsLength = nums.size();
        vector<int> temp;
        subsets(nums,0,uniqueVector,temp);
        vector<vector<int>> answer;
        for(auto element : uniqueVector){
            answer.push_back(element);
        }
        return answer;
    }
};