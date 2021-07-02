#include<bits/stdc++.h>
using namespace std;

// 343. Integer Break
// Given an integer n, break it into the sum of k
//  positive integers, where k >= 2, and maximize the
//  product of those integers.

// Return the maximum product you can get.

// Example 1:
// Input: n = 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.

// Example 2:
// Input: n = 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

// Constraints:
// 2 <= n <= 58

class Solution {
    int dp[59];
public:
    Solution(){
        memset(dp,-1,sizeof(dp));
    }
    int integerBreak(int n) {
        if(n == 1){
            return 1;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        int maxProduct = 0;
        for(int i=1;i<=n/2;i++){
            int value1 = i;
            int value2 = n - i;

            maxProduct = max(maxProduct,value1 * value2);
            maxProduct = max(maxProduct,value1 * integerBreak(value2));
            maxProduct = max(maxProduct,value2 * integerBreak(value1));
        }
        return dp[n] = maxProduct;
    }
};