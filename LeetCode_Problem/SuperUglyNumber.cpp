#include<bits/stdc++.h>
using namespace std;

// 313. Super Ugly Number

// A super ugly number is a positive integer whose 
// prime factors are in the array primes.
// Given an integer n and an array of integers primes,
//  return the nth super ugly number.
// The nth super ugly number is guaranteed to fit in 
// a 32-bit signed integer.

// Example 1:
// Input: n = 12, primes = [2,7,13,19]
// Output: 32
// Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the
//  sequence of the first 12 super ugly numbers given 
// primes = [2,7,13,19].

// Example 2:
// Input: n = 1, primes = [2,3,5]
// Output: 1
// Explanation: 1 has no prime factors, therefore all of
//  its prime factors are in the array primes = [2,3,5].
 
// Constraints:
// 1 <= n <= 106
// 1 <= primes.length <= 100
// 2 <= primes[i] <= 1000
// primes[i] is guaranteed to be a prime number.
// All the values of primes are unique and sorted 
// in ascending order.

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n,0);
        int primeLength = primes.size();
        vector<int> pointer(primeLength,0);
        dp[0] = 1;
        int i = 1;
        while(i < n){
            int val = INT_MAX;
            int index = -1;
            for(int j=0;j<primeLength;j++)
            {
                int temp = dp[pointer[j]] * primes[j];
                if( temp < val){
                    val = temp;
                    index = j;
                }
            }
            for(int w = 0;w<primeLength;w++){
                int temp = dp[pointer[w]]* primes[w];
                if(temp == val){
                    pointer[w] += 1;
                }
            }
            dp[i] = val;
            i++;
        }

        return dp[n - 1];
    }
};