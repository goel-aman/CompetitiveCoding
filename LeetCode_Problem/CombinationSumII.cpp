//  Combination Sum II
#include<bits/stdc++.h>
using namespace std;

// Given a collection of candidate numbers (candidates) and a target number (target),
//  find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Example 1:
// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// Example 2:
// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 
// Constraints:
// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

class Solution {
    int candidatesLength;
    set<vector<int>> ms;
public:
    void combinationSum2(vector<int> &candidates,int target,set<vector<int>> &res,vector<int> &combination,int index){
        if(target == 0){
            // for(auto w : combination){
            //     cout<<w<<" ";
            // }
            cout<<endl;
            ms.insert(combination);
            res.insert(combination);
        }
        
        if(index >= candidatesLength ){
            return ;
        }
        
        if(target >= candidates[index]){
            combination.push_back(candidates[index]);
            combinationSum2(candidates,target - candidates[index],res,combination,index + 1);
            combination.pop_back();
        }
        
        combinationSum2(candidates,target,res,combination,index + 1);
        return ;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        candidatesLength = candidates.size();
        set<vector<int>> res;
        vector<vector<int>> vs;
        
        vector<int> combination;
        sort(candidates.begin(),candidates.end());
        combinationSum2(candidates,target,res,combination,0);
        for(auto m : res){
            // for(auto w : m){
            //     cout<<w<<" ";
            // }
            // cout<<endl;
            vs.push_back(m);
        }
        return vs;
    }
};