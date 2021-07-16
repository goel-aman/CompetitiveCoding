#include<bits/stdc++.h>
using namespace std;

// 525. Contiguous Array
// Given a binary array nums, return the maximum length 
// of a contiguous subarray with an equal number of 0 and 1.

// Example 1:
// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous 
// subarray with an equal number of 0 and 1.

// Example 2:
// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous 
// subarray with equal number of 0 and 1.
 
// Constraints:
// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int numsLength = nums.size();
        int sum = 0;

        int ans = 0;
        unordered_map<int,int> um;
        for(int i=0;i<numsLength;i++){
            if(nums[i] == 0){
                sum += -1;
            }else{
                sum += 1;
            }

            if(!um.count(sum) && sum != 0){
                um[sum] = i;
            }else{
                if(sum != 0){                   
                    ans = max(ans,i - um[sum]);
                    
                }
            }
            if(sum == 0){
                ans = max(ans,i + 1);
            }
        }
        return ans;
    }
    
};