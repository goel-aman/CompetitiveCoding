// 69. Sqrt(x)

// Given a non-negative integer x, compute and 
// return the square root of x.

// Since the return type is an integer, the decimal 
// digits are truncated, and only the integer part 
// of the result is returned.

// Example 1:
// Input: x = 4
// Output: 2

// Example 2:
// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
 
// Constraints:
// 0 <= x <= 231 - 1
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 1){
            return 1;
        }
        int ans = 0;
        for(int i=0;i<= x / 2;i++){
            long long int val = (long long int) i * (long long int) i;
            if(val >= INT_MAX){
                break;
            }
            if(i*i <=  x){
                ans = i;
            }
        }
        return ans;
    }
};