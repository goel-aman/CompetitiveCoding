#include<bits/stdc++.h>
using namespace std;

// 494. Target Sum

// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the 
// symbols '+' and '-' before each integer in nums and then concatenate
//  all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before
//  1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, 
// which evaluates to target.

// Example 1:
// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3

// Example 2:
// Input: nums = [1], target = 1
// Output: 1
 
// Constraints:
// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000

class Solution {
    int numsLength;
    unordered_map<int,int> um;
public:
    int findWays(vector<int>& nums,int s,int index){
        if(index == numsLength){
            if(s == 0){
                return 1;
            }
            return 0;
        }
        string s = to_string(s) + ";" + to_string(index);
        if(um.count(s)){
            return um[s];
        }
        int answer = 0;
        // first option consider this number as positive;
        answer += findWays(nums,s - nums[index],index + 1);

        // second option to consider the number at index position to be negative
        answer += findWays(nums,s + nums[index],index + 1);

        return um[s] = answer;
    }

    int findTargetSumWays(vector<int>& nums, int S) {
        numsLength = nums.size();
        return findWays(nums,S,0);
    }
};