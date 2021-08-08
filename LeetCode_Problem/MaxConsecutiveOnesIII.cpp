#include<bits/stdc++.h>
using namespace std;

// 1004. Max Consecutive Ones III
// Given a binary array nums and an integer k, return the 
// maximum number of consecutive 1's in the array if you 
// can flip at most k 0's.

// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest 
// subarray is underlined.

// Example 2:
// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest 
// subarray is underlined.
 
// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length


class Solution {
    int numsLength;
public:
    int longestOnes(vector<int>& nums, int k) {
        int simpleStreak = 0;
        int ans = 0;
        numsLength = nums.size();
        if(k == 0){
            for(int i=0;i<numsLength;i++){
                if(nums[i] == 1){
                    simpleStreak++;
                    ans = max(ans,simpleStreak);
                }else{
                    simpleStreak = 0;
                }
            }
            return ans;
        }
        
        int start = 0 ,end = 0, streak = 0;
        while(end < numsLength){
            if(nums[end] == 1){
                streak++;
                end++;
                ans = max(ans,streak);
            }else{
                if(k > 0){
                    streak++;
                    ans = max(ans,streak);
                    k--;
                    end++;
                    continue;
                }

                while(start < end && k == 0){
                    if(nums[start] == 0){
                        k++;
                        start++;
                        streak--;
                        continue;
                    }else{
                        start++;
                        streak--;
                    }
                }
            }
        }
        return ans;
    }
};