#include<bits/stdc++.h>
using namespace std;

// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// Given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums 
// such that the sum of the minimum and maximum element 
// on it is less or equal to target. Since the answer may 
// be too large, return it modulo 109 + 7.

// Example 1:
// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences
//  that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)

// Example 2:
// Input: nums = [3,3,6,8], target = 10
// Output: 6
// Explanation: There are 6 subsequences that satisfy the
//  condition. (nums can have repeated numbers).
// [3] , [3] , [3,3], [3,6] , [3,6] , [3,3,6]

// Example 3:
// Input: nums = [2,3,3,4,6,7], target = 12
// Output: 61
// Explanation: There are 63 non-empty subsequences, two 
// of them don't satisfy the condition ([6,7], [7]).
// Number of valid subsequences (63 - 2 = 61).

// Example 4:
// Input: nums = [5,2,4,1,7,6,8], target = 16
// Output: 127
// Explanation: All non-empty subset satisfy 
// the condition (2^7 - 1) = 127
 
// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 106
// 1 <= target <= 106

class Solution {
    long long int mod = 1e9 + 7;
public:
    long long int powerOfTwo(int y){
        if(y == 0){
            return 1;
        }
        if(y == 1){
            return 2;
        }
        
        long long int ans = 1;
        
        if(y%2 == 0){
            long long value = powerOfTwo(y/2);
            ans = (value * value);
        }else{
            ans = powerOfTwo(y/2);
            ans = (ans * ans * 2);
        }
        
        ans %= mod;
        return ans;
    }

    int numSubseq(vector<int>& nums, int target) {
        int numsLength = nums.size();
        sort(nums.begin(),nums.end());
        int start = 0, end = numsLength - 1;
        long long int ans = 0;
        while(start <= end){
            int value = nums[start] +  nums[end];
            if(value <= target){
                ans = (ans + powerOfTwo(end - start))%mod;
                start++;
                continue;
            }else{
                end--;
            }
        }
        return ans%mod;
    }
};