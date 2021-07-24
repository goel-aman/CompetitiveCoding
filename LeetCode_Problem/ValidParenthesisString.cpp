#include<bits/stdc++.h>
using namespace std;

// 678. Valid Parenthesis String
// Given a string s containing only three types of
//  characters: '(', ')' and '*', return true if s is valid.
// The following rules define a valid string:
// Any left parenthesis '(' must have a corresponding right
//  parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left
//  parenthesis '('.
// Left parenthesis '(' must go before the corresponding 
// right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or
//  a single left parenthesis '(' or an empty string "".

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "(*)"
// Output: true

// Example 3:
// Input: s = "(*))"
// Output: true
 
// Constraints:
// 1 <= s.length <= 100
// s[i] is '(', ')' or '*'.

class Solution {
public:
    bool checkValidString(string s) {
        int sLength = s.length();
        stack<int> opening,star;

        for(int i=0;i<sLength;i++){
            if(s[i] == '('){
                opening.push(i);
                continue;
            }

            if(s[i] == '*'){
                star.push(i);
                continue;
            }

            if(s[i] == ')'){
                if(!opening.empty()){
                    opening.pop();
                    continue;
                }

                if(!star.empty() && star.top() < i){
                    star.pop();
                    continue;
                }

                return false;
            }
        } 

        // balancing opening braces.

        if(opening.empty()){
            return true;
        }

        while(!opening.empty()){
            if(!star.empty() && star.top() > opening.top()){
                opening.pop();
                star.pop();
                continue;
            }

            return false;
        }

        return true;
    }
};