#include<bits/stdc++.h>
using namespace std;

// 491. Increasing SubsequencesGiven an integer array nums, return
//  all the different possible increasing subsequences of the given 
// array with at least two elements. You may return the answer in 
// any order.
// The given array may contain duplicates, and two equal integers should
//  also be considered a special case of increasing sequence.

// Example 1:
// Input: nums = [4,6,7,7]
// Output: [[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

// Example 2:
// Input: nums = [4,4,3,2,1]
// Output: [[4,4]]
 
// Constraints:
// 1 <= nums.length <= 15
// -100 <= nums[i] <= 100

class Solution {
    int numsLength;
public:
    void find(vector<int>& nums,int index,vector<vector<int>>& ans,vector<int>& current){
        if(numsLength == index){
            if(current.size() >= 2){
                ans.push_back(current);
            }
            return ;
        }

        if(current.size() == 0){
            // taking the current element
            current.push_back(nums[index]);
            find(nums,index + 1,ans,current);
            // not taking into consideration
            current.pop_back();
            find(nums,index + 1,ans,current);
            return ;
        }

        

        // leave this element first
        find(nums,index + 1,ans,current);

        // taking this element
        if(current.size() >= 0 && nums[index] >= current[current.size() - 1]){
            if(current.size() >= 2){
                ans.push_back(current);
            }
            current.push_back(nums[index]);
            find(nums,index + 1,ans,current);
            current.pop_back();
        }
        return ;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        numsLength = nums.size();
        vector<vector<int>> ans;
        
        vector<int> current;
        find(nums,0,ans,current);
        set<vector<int>> st;
        for(int i=0;i<ans.size();i++){
            st.insert(ans[i]);
        }
        vector<vector<int>> ans2;
        for(auto var : st){
            ans2.push_back(var);
        }
        
        return ans2;      
    }
};