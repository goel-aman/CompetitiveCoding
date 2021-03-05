// 172. Factorial Trailing Zeroes

// Given an integer n, return the number of trailing zeroes in n!.
// Follow up: Could you write a solution that works in logarithmic 
// time complexity?

// Example 1:
// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.

// Example 2:
// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.

// Example 3:
// Input: n = 0
// Output: 0

// Constraints:
// 0 <= n <= 104

class Solution {
public:
    int trailingZeroes(int n) {
        int count5 = n;
        int answer5 = 0;
        int num = 5;
        while(floor(count5/num)){
            answer5 += floor(count5/num);
            num = num * 5;
        }
        
        num = 2;
        int count2 = n;
        int answer2 = 0;
        while(floor(count2/num)){
            answer2 += floor(count2/num);
            num *= 2;
        }
        return min(answer5,answer2);
    }
};