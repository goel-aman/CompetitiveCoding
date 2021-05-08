#include<bits/stdc++.h>
using namespace std;

// 357. Count Numbers with Unique Digits

// Given an integer n, return the count of all numbers with unique 
// digits, x, where 0 <= x < 10n.

// Example 1:
// Input: n = 2
// Output: 91
// Explanation: The answer should be the total numbers in the range 
// of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99

// Example 2:
// Input: n = 0
// Output: 1
 
// Constraints:
// 0 <= n <= 8

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int dp[10];
        dp[0] = 1;
        dp[1] = 10;
        dp[2] = (9 * 9);
        int last = 8;
        for(int i=3;i<=9;i++){
            dp[i] = (dp[i - 1] * last);
            last--;
        }
        int answer = 0;
        if(n == 0){
            return 1;
        }
        for(int i=1;i<=n;i++){
            answer += dp[i];
        }
        return answer;
    }
};