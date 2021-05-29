#include<bits/stdc++.h>
using namespace std;

// 740. Delete and Earn
// Given an array nums of integers, you can perform operations on the array.
// In each operation, you pick any nums[i] and delete it to earn nums[i] points.
//  After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
// You start with 0 points. Return the maximum number of points you can earn by
//  applying such operations.

// Example 1:
// Input: nums = [3,4,2]
// Output: 6
// Explanation: Delete 4 to earn 4 points, consequently 3 is also deleted.
// Then, delete 2 to earn 2 points.
// 6 total points are earned.

// Example 2:
// Input: nums = [2,2,3,3,3,4]
// Output: 9
// Explanation: Delete 3 to earn 3 points, deleting both 2's and the 4.
// Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
// 9 total points are earned.
 
// Constraints:
// 1 <= nums.length <= 2 * 104
// 1 <= nums[i] <= 104


class Solution {
    int numsLength;
    int dp[20001];
public:
    int solve(vector<int>& nums,int index){
        if(index == numsLength){
            return 0;
        }
        int tempVal = index;

        if(dp[tempVal] != -1){
            return dp[tempVal];
        }

        // lets skip it
        int tempIndex = index;
        while(tempIndex + 1 < numsLength && nums[tempIndex + 1] == nums[tempIndex]){
            tempIndex++;
        }

        int value2 = solve(nums,tempIndex + 1);
        int sum = nums[index];
        // first lets take it;
        while(index + 1 < numsLength  &&  nums[index] == nums[index + 1]){
            sum += nums[index];
            index++;
        }

        int val = nums[index] + 1; 

        while(index + 1 < numsLength && nums[index + 1] == val){
            index++;
        }

        int value = sum + solve(nums,index + 1);
        return dp[tempVal] = max(value,value2);
    }

    int deleteAndEarn(vector<int>& nums) {
        numsLength = nums.size();
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        int value = solve(nums,0);
        return value;
    }
};