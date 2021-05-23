#include<bits/stdc++.h>
using namespace std;

// 46. Permutations

// Given an array nums of distinct integers, return all the possible
//  permutations. You can return the answer in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:
// Input: nums = [1]
// Output: [[1]]
 
// Constraints:
// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.

class Solution {
    int length;
    vector<vector<int>> ans;
public:
    void solve(vector<int>& nums,vector<int>& visited,vector<int> &res){

        bool allVisited = true;
        for(int i=0;i<length;i++){
            if(visited[i] == 0){
                allVisited = false;
                break;
            }
        }

        if(allVisited == true){
            ans.push_back(res);
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

    vector<vector<int>> permute(vector<int>& nums) {
        length = nums.size();
        vector<int> res;
        vector<int> visited(length,0);
        solve(nums,visited,res);
        return ans;
    }
};