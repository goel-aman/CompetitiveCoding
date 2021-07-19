#include<bits/stdc++.h>
using namespace std;

// 581. Shortest Unsorted Continuous Subarray
// Given an integer array nums, you need to find one continuous 
// subarray that if you only sort this subarray in ascending order,
//  then the whole array will be sorted in ascending order.
// Return the shortest such subarray and output its length.

// Example 1:
// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending 
// order to make the whole array sorted in ascending order.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: 0

// Example 3:
// Input: nums = [1]
// Output: 0
 
// Constraints:
// 1 <= nums.length <= 104
// -105 <= nums[i] <= 105

// Follow up: Can you solve it in O(n) time complexity?
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int numsLength = nums.size();
        int mini = INT_MAX;
        int maxm = INT_MIN;
        for(int i=1;i<numsLength;i++){
            if(nums[i] < nums[i - 1]){
                mini = min(mini,nums[i]);
            }
        }

        for(int i=numsLength - 2;i>=0;i--){
            if(nums[i] > nums[i + 1]){
                maxm = max(maxm,nums[i]);
            }
        }
        if(maxm == INT_MIN && mini == INT_MAX){
            return 0;
        }
        // cout<<"value of mini is : "<<mini<<" and value of maxi is : "<<maxm<<endl;
        int start = 0, end = numsLength - 1;
        for(int i=0;i<numsLength;i++){
            if(mini < nums[i]){
                start = i;
                break;
            }
        }
        
        

        for(int j=numsLength - 1;j>=0;j--){
            if(maxm > nums[j]){
                end = j;
                break;
            }
        }

        return (end - start + 1);
    }
};