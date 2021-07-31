#include<bits/stdc++.h>
using namespace std;

// 1191. K-Concatenation Maximum Sum
// Given an integer array arr and an integer k, modify the 
// array by repeating it k times.

// For example, if arr = [1, 2] and k = 3 then the modified
//  array will be [1, 2, 1, 2, 1, 2].

// Return the maximum sub-array sum in the modified array. 
// Note that the length of the sub-array can be 0 and its 
// sum in that case is 0.
// As the answer can be very large, return the answer modulo 109 + 7.

// Example 1:
// Input: arr = [1,2], k = 3
// Output: 9

// Example 2:
// Input: arr = [1,-2,1], k = 5
// Output: 2

// Example 3:
// Input: arr = [-1,-2], k = 7
// Output: 0
 
// Constraints:
// 1 <= arr.length <= 105
// 1 <= k <= 105
// -104 <= arr[i] <= 104


class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int mod = 1e9 + 7;
        long long int previousSum = arr[0];
        long long int currentSum = arr[0];
        long long int arrLength =(long long int)arr.size();
        long long int sum = 0;
        for(long long int i=0;i<arrLength;i++){
            sum += arr[i];
        }
        // sum = sum%mod;
        long long int res = max(previousSum,currentSum);
        for(long long int i=1;i<arrLength * min(2,k);i++){
            currentSum = max((previousSum + arr[i%arrLength]),(long long int) arr[i%arrLength]);
            previousSum = currentSum;
            res = max(res,previousSum);
        }

        return max({(long long int) 0,sum * max(k - 2,0) + res,(res)})%mod;
    }
};