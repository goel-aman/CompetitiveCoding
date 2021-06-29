#include<bits/stdc++.h>
using namespace std;

// Fraction to Recurring Decimal

// Given two integers representing the numerator and denominator of
//  a fraction, return the fraction in string format.
// If the fractional part is repeating, enclose the repeating part
//  in parentheses.
// If multiple answers are possible, return any of them.
// It is guaranteed that the length of the answer string is less 
// than 104 for all the given inputs.

// Example 1:
// Input: numerator = 1, denominator = 2
// Output: "0.5"

// Example 2:
// Input: numerator = 2, denominator = 1
// Output: "2"

// Example 3:
// Input: numerator = 2, denominator = 3
// Output: "0.(6)"

// Example 4:
// Input: numerator = 4, denominator = 333
// Output: "0.(012)"

// Example 5:
// Input: numerator = 1, denominator = 5
// Output: "0.2"
 
// Constraints:
// -231 <= numerator, denominator <= 231 - 1
// denominator != 0


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool numeratorNegative = false;
        bool denominatorNegative = false;
        
        if(numerator < 0){
            numeratorNegative = true;
        }
        
        if(denominator < 0){
            denominatorNegative = true;
        }
        bool isPositive = true;
        
        if(numeratorNegative){
            isPositive = false;
        }
        
        if(denominatorNegative){
            isPositive = false;
        }
        
        if(numeratorNegative && denominatorNegative){
            isPositive = true;
        }
        numerator = abs(numerator);
        denominator = abs(denominator);
        string ans = "";
        long long int q = numerator / denominator;
        long long int r = numerator % denominator;
        ans += to_string(q);

        if(r == 0){
            if(ans == "0"){
                return ans;
            }
            if(isPositive){
                return ans;
            }
            string temp = "-" + ans;
            return temp;
        }
        unordered_map<long long int,long long int> um;
        ans += ".";
        bool recur = false;      
        while(r != 0){
           
            if(um.count(r) > 0){
           
                recur = true;
                break;
            }else{
                um[r] = ans.length();
            }
            r = r * 10;
            q = r / denominator;
            r = r % denominator;
           
            
            ans += to_string(q);
           
        }

        
        
        if(recur == false){
            if(ans == "0"){
                return ans;
            }
            if(isPositive){
                return ans;
            }else{
                string temp = "-" + ans;
                return temp;
            }
            return ans;
        }

        string newAns = ans.substr(0,um[r]) + "(" + ans.substr(um[r],ans.length() - um[r]) + ")";
        if(isPositive){
            
            return newAns;
        }
        if(newAns == "0"){
            return newAns;
        }
        string temp = "-" + newAns;
        return temp; 
    }
};