// // 410. Split Array Largest Sum
// Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

// Write an algorithm to minimize the largest sum among these m subarrays.

// Example 1:
// Input: nums = [7,2,5,10,8], m = 2
// Output: 18
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.

// Example 2:
// Input: nums = [1,2,3,4,5], m = 2
// Output: 9

// Example 3:
// Input: nums = [1,4,4], m = 3
// Output: 4
 

// Constraints:
// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 106
// 1 <= m <= min(50, nums.length)

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int ** um;    
public:

    int splitArrayhelper(vector<int>&nums,int m,vector<int> &prefixSum,int startingIndex,int endIndex){
        
        if(um[startingIndex][m] != -1){
            return um[startingIndex][m];
        }
        // cout<<"Starting Index is : "<<startingIndex<<" Ending index is : "<<endIndex<<" Value of M is : " <<m<<endl;
        int length = endIndex - startingIndex + 1;
        // cout<<"Length is : "<<length<<endl;
        if(m > length){
            return INT_MAX;
        }
        if(m == length){
            int ann = INT_MIN;
            for(int i=startingIndex;i<=endIndex;i++){
                ann = max(ann,nums[i]);
            }
            // cout<<"Answer is : "<<ann<<endl;
            return um[startingIndex][m] = ann;
        }
        
        if(m == 1){
            if(startingIndex == 0){
                // cout<<"Answer is : "<<prefixSum[endIndex];
                return um[startingIndex][m] = prefixSum[endIndex];
            }
            if(startingIndex <= endIndex){
                // cout<<"Answer is : "<<prefixSum[endIndex]  - prefixSum[startingIndex - 1]<<endl;
                return um[startingIndex][m] = (prefixSum[endIndex]  - prefixSum[startingIndex - 1]);
            }
        }

        int final_ans = INT_MAX;
        int summ = 0;
        for(int i=startingIndex;i<=endIndex - (m - 1);i++){
            summ += nums[i];
            int value = max(summ,splitArrayhelper(nums,m - 1,prefixSum,i + 1,endIndex));
            final_ans = min(final_ans,value);
        }
        return um[startingIndex][m] = final_ans;
    }

    int splitArray(vector<int>& nums, int m) {
        vector<int> prefixSum;
        int presum = 0;
        int length = nums.size();
        for(auto element : nums)
        {
            presum += element;
            prefixSum.push_back(presum);
        }
        um = new int*[length];
        for(int i=0;i<length;i++){
            um[i] = new int[m + 1];
            for(int j=0;j<=m;j++){
                um[i][j] = -1;
            }
        }

        return splitArrayhelper(nums,m,prefixSum,0,length - 1);
    }
};