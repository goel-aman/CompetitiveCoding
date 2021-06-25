#include<bits/stdc++.h>
using namespace std;

// 12. Integer to Roman
// Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

// Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000
// For example, 2 is written as II in Roman numeral, just two one's added together. 12
//  is written as XII, which is simply X + II. The number 27 is written as XXVII, which 
// is XX + V + II.

// Roman numerals are usually written largest to smallest from left to right. However, 
// the numeral for four is not IIII. Instead, the number four is written as IV. Because
//  the one is before the five we subtract it making four. The same principle applies to
//  the number nine, which is written as IX. There are six instances where subtraction is used:
// I can be placed before V (5) and X (10) to make 4 and 9. 
// X can be placed before L (50) and C (100) to make 40 and 90. 
// C can be placed before D (500) and M (1000) to make 400 and 900.
// Given an integer, convert it to a roman numeral.

// Example 1:
// Input: num = 3
// Output: "III"

// Example 2:
// Input: num = 4
// Output: "IV"

// Example 3:
// Input: num = 9
// Output: "IX"

// Example 4:
// Input: num = 58
// Output: "LVIII"
// Explanation: L = 50, V = 5, III = 3.

// Example 5:
// Input: num = 1994
// Output: "MCMXCIV"
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
// Constraints:
// 1 <= num <= 3999

class Solution {
    unordered_map<int,string> um;
public:
    Solution(){
        um[1] = "I";
        um[2] = "II";
        um[3] = "III";
        um[4] = "IV";
        um[5] = "V";
        um[6] = "VI";
        um[7] = "VII";
        um[8] = "VIII";
        um[9] = "IX";
        um[10] = "X";
        um[20] = "XX";
        um[30] = "XXX";
        um[40] = "XL";
        um[50] = "L";
        um[60] = "LX";
        um[70] = "LXX";
        um[80] = "LXXX";
        um[90] = "XC";
        um[100] = "C";
        um[200] = "CC";
        um[300] = "CCC";
        um[400] = "CD";
        um[500] = "D";
        um[600] = "DC";
        um[700] = "DCC";
        um[800] = "DCCC";
        um[900] = "CM";
        um[1000] = "M";
        um[2000] = "MM";
        um[3000] = "MMM";
    }

    string intToRoman(int num) {
        string input = to_string(num);
        string ans = "";
        int inputLength = input.length();
        int value = 1;
        stack<string> st;
        for(int i=inputLength - 1;i>=0;i--){
            int numm = input[i] - '0';
            int trueValue = numm * value;
            value = value * 10;
            st.push(um[trueValue]);  
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};