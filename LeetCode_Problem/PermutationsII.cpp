#include<bits/stdc++.h>
using namespace std;

// 47. Permutations II
// Given a collection of numbers, nums, that might contain
//  duplicates, return all possible unique permutations in any order.

// Example 1:
// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

// Example 2:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 
// Constraints:
// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

class Solution {
    set<vector<int>> s;
    int length;
public:
    void solve(vector<int>& nums,vector<int>& visited,vector<int>& res){
        bool allVisited = true;
        for(int i=0;i<length;i++){
            if(visited[i] == 0){
                allVisited = false;
                break;
            }
        }

        if(allVisited){
            s.insert(res);
            return;
        }

        for(int i=0;i<length;i++){
            if(visited[i] == 0){
                visited[i] = 1;
                res.push_back(nums[i]);
                solve(nums,visited,res);
                res.pop_back();
                visited[i] = 0;
            }
        }
        return ;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        length = nums.size();
        vector<int> res;
        vector<int> visited(length,0);
        solve(nums,visited,res);
        vector<vector<int>> ret;
        for(auto element : s){
            ret.push_back(element);
        }
        return ret;
    }
};