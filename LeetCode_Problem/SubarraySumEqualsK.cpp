#include<bits/stdc++.h>
using namespace std;

// 560. Subarray Sum Equals K
// Given an array of integers nums and an integer k, return the 
// total number of continuous subarrays whose sum equals to k.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

// Constraints:
// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int numsLength = nums.size();
        unordered_map<int,int> um;
        int sum = 0;
        int count = 0;
        um[0] = 1;
        for(int i=0;i<numsLength;i++){
            sum += nums[i];
            if(um.count(sum - k) > 0){
                count += um[sum - k]; 
            }
            um[sum]++;
        }
        
        return count;
    }
};