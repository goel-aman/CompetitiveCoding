#include<bits/stdc++.h>
using namespace std;

// 264. Ugly Number II

// An ugly number is a positive integer whose prime 
// factors are limited to 2, 3, and 5.
// Given an integer n, return the nth ugly number.

// Example 1:
// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the 
// sequence of the first 10 ugly numbers.

// Example 2:
// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of 
// its prime factors are limited to 2, 3, and 5.
 
// Constraints:
// 1 <= n <= 1690

class Solution {
public:
    int nthUglyNumber(int n) {
        if(n == 0){
            return 0;
        }
        
        if(n == 1){
            return 1;
        }
        
        int two = 0,three = 0,five = 0;
        vector<int> vec(n,0);
        vec[0] = 1; 
        for(int i=1;i<n;i++){
            vec[i] = min(2* vec[two],min(3 * vec[three],5 * vec[five]));
            if(vec[i] == 2 * vec[two]){
                two++;
            }
            if(vec[i] == 3 * vec[three]){
                three++;
            } 
            if(vec[i] == 5 * vec[five]){
                five++;
            }
        }
        return vec[n - 1];
    }
};