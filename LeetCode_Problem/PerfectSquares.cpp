#include<bits/stdc++.h>
using namespace std;

// 279. Perfect Squares

// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is 
// the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

// Example 1:
// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

// Example 2:
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 
// Constraints:
// 1 <= n <= 104

class Solution {
    unordered_map<int,int> um;
public:
    int numSquares(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        
        if(um.count(n) > 0){
            return um[n];
        }
            
        int answer = INT_MAX;
        int val;
        for(int i=1;i<=sqrt(n);i++){
            int value = n - (i*i);
            int value2 = numSquares(value);
            um[value] = value2;
            val = 1 + value2;
            answer = min(answer,val);;
        }
        return um[n] = answer;
    }
};