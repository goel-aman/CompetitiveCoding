#include<bits/stdc++.h>
using namespace std;

// 397. Integer Replacement

// Given a positive integer n, you can apply one of
//  the following operations:
// If n is even, replace n with n / 2.
// If n is odd, replace n with either n + 1 or n - 1.
// Return the minimum number of operations needed 
// for n to become 1.

// Example 1:
// Input: n = 8
// Output: 3
// Explanation: 8 -> 4 -> 2 -> 1

// Example 2:
// Input: n = 7
// Output: 4
// Explanation: 7 -> 8 -> 4 -> 2 -> 1
// or 7 -> 6 -> 3 -> 2 -> 1

// Example 3:
// Input: n = 4
// Output: 2
 
// Constraints:
// 1 <= n <= 231 - 1

class Solution {
public:
    
    long long int integerReplacementt(long long int n) {
        if(n == 1){
            return 0;
        }
        if(n == INT_MAX){
            return 32;
        }
        if(n < 1){
            return INT_MAX;
        }

        if(n%2 == 0){
            return 1 + integerReplacement(n / 2);
        }
        
        long long int value1 = integerReplacement(n - 1);
        long long int value2 = INT_MAX;
        value2 = integerReplacement(n + 1);
        
        if(value1 == INT_MAX && value2 == INT_MAX){
            return INT_MAX;
        }
        return 1 + min(value1,value2);
        
    }
    
    int integerReplacement(int n){
        return integerReplacementt(n);
    }
    
};