// 1420. Build Array Where You Can Find The Maximum Exactly K Comparisons

// Given three integers n, m and k. Consider the following algorithm to
//  find the maximum element of an array of positive integers:


// You should build the array arr which has the following properties:
// arr has exactly n integers.
// 1 <= arr[i] <= m where (0 <= i < n).
// After applying the mentioned algorithm to arr, the value search_cost is equal to k.
// Return the number of ways to build the array arr under the mentioned conditions.
//  As the answer may grow large, the answer must be computed modulo 10^9 + 7.

// Example 1:
// Input: n = 2, m = 3, k = 1
// Output: 6
// Explanation: The possible arrays are [1, 1], [2, 1], [2, 2], [3, 1], [3, 2] [3, 3]

// Example 2:
// Input: n = 5, m = 2, k = 3
// Output: 0
// Explanation: There are no possible arrays that satisify the mentioned conditions.

// Example 3:
// Input: n = 9, m = 1, k = 1
// Output: 1
// Explanation: The only possible array is [1, 1, 1, 1, 1, 1, 1, 1, 1]

// Example 4:
// Input: n = 50, m = 100, k = 25
// Output: 34549172
// Explanation: Don't forget to compute the answer modulo 1000000007

// Example 5:
// Input: n = 37, m = 17, k = 7
// Output: 418930126

// Constraints:
// 1 <= n <= 50
// 1 <= m <= 100
// 0 <= k <= n

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int mod = 1000000007;
    // k , largest PRev, index
    int dp[51][101][51];
public:
    int numOfArrays(int &n,int &m,int k,int largestPrev,int index){
        if(index == n && k != 0){
            return 0;
        }
        
        if(index == n && k == 0){
            return 1;
        }
        if(m - largestPrev < k){
            return 0;
        }
        if(k == 0){
            long long int val = largestPrev;
            for(int i=2;i<=(n - index);i++){
                val = (val * largestPrev)%mod;
            }
            val = val % mod;
            return (int) val;
        }
        
        if(dp[k][largestPrev][index] != -1){
            return dp[k][largestPrev][index];
        }
        
        int ans = 0;
        // without swap
        for(int i = 1;i<= largestPrev;i++){
            ans = (ans + numOfArrays(n,m,k,largestPrev,index + 1)) % mod;
        }
        
        // with swap
        for(int i = largestPrev + 1;i<=m;i++){
            if(k > 0){
                ans = (ans + numOfArrays(n,m,k - 1,i,index + 1) )%mod;    
            }
        }
        
        return dp[k][largestPrev][index] = (ans%mod);
    }
    
    int numOfArrays(int n, int m, int k) {
        if(m < k){
            return 0;
        }
        if(n < k){
            return 0;
        }
        
        if(n == m && m == k){
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        return numOfArrays(n,m,k,0,0);
        
    }
};