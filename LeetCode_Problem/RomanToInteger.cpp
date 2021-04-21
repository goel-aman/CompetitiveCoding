// 13. Roman to Integer

// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together.
//  12 is written as XII, which is simply X + II. The number 27 is written as XXVII,
//  which is XX + V + II.
// Roman numerals are usually written largest to smallest from left to right. However,
//  the numeral for four is not IIII. Instead, the number four is written as IV. Because
//  the one is before the five we subtract it making four. The same principle applies to
//  the number nine, which is written as IX. There are six instances where subtraction is used:

// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given a roman numeral, convert it to an integer.

// Example 1:
// Input: s = "III"
// Output: 3

// Example 2:
// Input: s = "IV"
// Output: 4

// Example 3:
// Input: s = "IX"
// Output: 9

// Example 4:
// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.

// Example 5:
// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
// Constraints:
// 1 <= s.length <= 15
// s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
// It is guaranteed that s is a valid roman numeral in the range [1, 3999].
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<char,int> um;
public:
    Solution(){
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
    }
    int romanToInt(string s) {
        int sLength = s.length();
        int ans = 0;
        int i = sLength - 1;
        while(i >= 0){
            if(i == 0){
                ans += um[s[i]];
                i -= 1;
                continue;
            }
            if(s[i] == 'X' && s[i - 1] == 'I'){
                ans += 9;
                i -= 2;
                continue;
            }
            
            if(s[i] == 'V' && s[i - 1] == 'I'){
                ans += 4;
                i -= 2;
                continue;
            }
            
            if(s[i] == 'L' && s[i - 1] == 'X'){
                ans += 40;
                i -= 2;
                continue;
            }
            
            if(s[i] == 'C' && s[i - 1] == 'X'){
                ans += 90;
                i -= 2;
                continue;
            }
            
            if(s[i] == 'D' && s[i - 1] == 'C'){
                ans += 400;
                i -= 2;
                continue;
            }
            
            if(s[i] == 'M' && s[i - 1] == 'C'){
                ans += 900;
                i -= 2;
                continue;
            }
            
            ans += um[s[i]];
            i -= 1;
        }
        return ans;
    }
};