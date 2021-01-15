// Problem statement.
// 17. Letter Combinations of a Phone Number
// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// Example 2:

// Input: digits = ""
// Output: []
// Example 3:

// Input: digits = "2"
// Output: ["a","b","c"]
 

// Constraints:

// 0 <= digits.length <= 4
// digits[i] is a digit in the range ['2', '9'].


#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> numberValue = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        int digitlength = digits.length();
        if(digitlength == 0){
            vector<string> ans;
            return ans;
        }
        
        if(digitlength == 1){
            vector<string> ret;
            string num = numberValue[digits[0] - '0'];
            for(int i=0;i<num.length();i++){
                string inp = "";
                inp.push_back(num[i]);
                ret.push_back(inp);
            }
            return ret;
        }
        
        vector<string> anss = letterCombinations(digits.substr(1));
        vector<string> ret;
        string num =  numberValue[digits[0] - '0'];
        for(int i=0;i<num.length();i++){
            for(int j=0;j<anss.size();j++){
                string inp = "";
                inp.push_back(num[i]);
                inp += anss[j];
                ret.push_back(inp);
            }
        }
        return ret;
    }
};