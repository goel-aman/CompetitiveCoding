#include<bits/stdc++.h>
using namespace std;

// 18. 4Sum
// Given an array nums of n integers, return an array of all the unique 
// quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

// Example 1:
// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// Example 2:
// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 
// Constraints:
// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> ans;
        unordered_map<int,set<pair<int,int>>> um;
        int numsLength = nums.size();
        unordered_map<int,int> umm;
        for(int i=0;i<numsLength;i++){
            umm[nums[i]]++;
            for(int j=0;j<i;j++){
                int val = nums[i] + nums[j];
                if(um.count(target - val) > 0){
                    for(auto w : um[target - val]){
                        vector<int> temp;
                        unordered_map<int,int> count;
                        temp.push_back(nums[i]);
                        count[nums[i]]++;
                        temp.push_back(nums[j]);
                        count[nums[j]]++;
                        temp.push_back(w.first);
                        count[w.first]++;
                        temp.push_back(w.second);
                        count[w.second]++;
                        
                        bool isValid = true;
                        for(auto t : count){
                            if(umm[t.first] >= t.second){
                                continue;
                            }else{
                                isValid = false;
                                break;
                            }
                        }
                        if(isValid){
                            sort(temp.begin(),temp.end());
                            ans.insert(temp);    
                        }
                        
                    }
                }
                um[val].insert({nums[i],nums[j]});
            }
        }
        vector<vector<int>> ret;
        for(auto h: ans){
            ret.push_back(h);
        }
        return ret;
    }
};