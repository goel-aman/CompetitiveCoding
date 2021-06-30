// 227. Basic Calculator II

// Given a string s which represents an expression, 
// evaluate this expression and return its value. 
// The integer division should truncate toward zero.
// Note: You are not allowed to use any built-in function
//  which evaluates strings as mathematical expressions, such as eval().

// Example 1:
// Input: s = "3+2*2"
// Output: 7

// Example 2:
// Input: s = " 3/2 "
// Output: 1

// Example 3:
// Input: s = " 3+5 / 2 "
// Output: 5
 
// Constraints:
// 1 <= s.length <= 3 * 105
// s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
// s represents a valid expression.
// All the integers in the expression are non-negative integers in the range [0, 231 - 1].
// The answer is guaranteed to fit in a 32-bit integer.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sLength = s.length();
        int currNum = 0;
        char oper = '+';
        for(int i=0;i<sLength;i++){
            if(s[i] != ' ' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/'){
                currNum = currNum * 10 + (s[i] - '0');
            }

            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == sLength - 1){
                if(oper == '+'){
                    st.push(currNum);
                }

                if(oper == '-'){
                    st.push(-1 * currNum);
                }

                if(oper == '/'){
                    int val = st.top();
                    st.pop();
                    st.push(val / currNum);
                }

                if(oper == '*'){
                    int val = st.top();
                    st.pop();
                    st.push(val * currNum);
                }
                currNum = 0;
                oper = s[i];
                continue;
            }          
        }
        
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};