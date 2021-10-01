#include<bits/stdc++.h>
using namespace std;

// 962. Maximum Width Ramp
// A ramp in an integer array nums is a pair (i, j) for
//  which i < j and nums[i] <= nums[j]. The width of such 
// a ramp is j - i.

// Given an integer array nums, return the maximum width of
//  a ramp in nums. If there is no ramp in nums, return 0.

// Example 1:
// Input: nums = [6,0,8,2,1,5]
// Output: 4
// Explanation: The maximum width ramp is achieved 
// at (i, j) = (1, 5): nums[1] = 0 and nums[5] = 5.

// Example 2:
// Input: nums = [9,8,1,0,1,9,4,0,4,1]
// Output: 7
// Explanation: The maximum width ramp is achieved 
// at (i, j) = (2, 9): nums[2] = 1 and nums[9] = 1.
 
// Constraints:
// 2 <= nums.length <= 5 * 104
// 0 <= nums[i] <= 5 * 104


bool compare(pair<int,int> &first,pair<int,int>& second){
    if(first.first < second.first){
        return true;
    }

    if(first.first == second.first){
        if(first.second < second.second){
            return true;
        }
    }

    return false;
}

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int numsLength = nums.size();
        int ans = 0;
        vector<pair<int,int>> numsWithIndex;

        for(int i=0;i<numsLength;i++){
            numsWithIndex.push_back({nums[i],i});
        }

        sort(numsWithIndex.begin(),numsWithIndex.end(),compare);
        int smallest = numsWithIndex[0].second,highest = numsWithIndex[0].second;
        for(int i=1;i<numsLength;i++){
            if(numsWithIndex[i].second > highest){
                highest = numsWithIndex[i].second;
                ans = max(ans,highest - smallest);
                continue;
            }

            if(numsWithIndex[i].second < smallest){
                smallest = numsWithIndex[i].second;
                highest = numsWithIndex[i].second;
                continue;
            }
        }
        return ans;
    }
};