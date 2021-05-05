#include<bits/stdc++.h>
using namespace std;

// 1799. Maximize Score After N Operations

// You are given nums, an array of positive integers of size 2 * n. 
// You must perform n operations on this array.
// In the ith operation (1-indexed), you will:

// Choose two elements, x and y.
// Receive a score of i * gcd(x, y).
// Remove x and y from nums.
// Return the maximum score you can receive after performing n operations.

// The function gcd(x, y) is the greatest common divisor of x and y.

// Example 1:
// Input: nums = [1,2]
// Output: 1
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 2)) = 1

// Example 2:
// Input: nums = [3,4,6,8]
// Output: 11
// Explanation: The optimal choice of operations is:
// (1 * gcd(3, 6)) + (2 * gcd(4, 8)) = 3 + 8 = 11

// Example 3:
// Input: nums = [1,2,3,4,5,6]
// Output: 14
// Explanation: The optimal choice of operations is:
// (1 * gcd(1, 5)) + (2 * gcd(2, 4)) + (3 * gcd(3, 6)) = 1 + 4 + 9 = 14
 
// Constraints:
// 1 <= n <= 7
// nums.length == 2 * n
// 1 <= nums[i] <= 106

class Solution {
    int length;
    int dp[8][16384];
public:
    int findAnswer(vector<int>& nums,int mask = 0,int count = 1){
        if(count > length / 2){
            return 0;
        }

        if(dp[count][mask] == 0){
            for(int i=0;i<length;i++){
                int tempMask = (1<<i);
                if((mask & tempMask) == 0){
                    for(int j=i + 1;j<length;j++){
                        int newMask = ((1 << i) | (1 << j));
                        if( (newMask & mask) == 0 ){
                         dp[count][mask] = max(dp[count][mask],(count * __gcd(nums[i],nums[j])) + findAnswer(nums,(newMask | mask),count+1));
                        }
                    }
                }
            }
        }      
        return dp[count][mask];
    }

    int maxScore(vector<int>& nums) {
        length = nums.size();
        memset(dp,0,sizeof(dp));
        return findAnswer(nums,0,1);
    }
};