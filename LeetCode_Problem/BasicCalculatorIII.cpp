#include<bits/stdc++.h>
using namespace std;

// 772. Basic Calculator III
// Implement a basic calculator to evaluate
// a simple expression string.

// The expression string contains only non-negative 
// integers, '+', '-', '*', '/' operators, and open
//  '(' and closing parentheses ')'. The integer division
//  should truncate toward zero.

// You may assume that the given expression is always 
// valid. All intermediate results will be in the range
//  of [-231, 231 - 1].

// Note: You are not allowed to use any built-in function
//  which evaluates strings as mathematical expressions, 
// such as eval().

// Example 1:
// Input: s = "1+1"
// Output: 2

// Example 2:
// Input: s = "6-4/2"
// Output: 4

// Example 3:
// Input: s = "2*(5+5*2)/3+(6/2+8)"
// Output: 21
 
// Constraints:
// 1 <= s <= 104
// s consists of digits, '+', '-', '*', '/', '(', and ')'.
// s is a valid expression.

class Solution {
public:
    int solve(string s,int startingIndex,int endingIndex){
        stack<int> st;
        int currentNumber = 0;
        char oper = '+';
        for(int i=startingIndex;i<=endingIndex;i++){
            if(s[i] != '-' && s[i] != '+' && s[i] != '/' && s[i] != '*' && s[i] != '(' && s[i] != ')'){
                currentNumber = (currentNumber * 10) + (s[i] - '0');
            }
            
            if(s[i] == '('){
                int startPosition = i;
                // find corresponding closing bracket
                int count = -1;
                while(count != 0 && i < endingIndex){
                    i++;
                    if(s[i] == '('){
                        count--;
                    }else if(s[i] == ')'){
                        count++;
                    }
                }
                int endPosition = i;

                int value = solve(s,startPosition + 1,endPosition - 1);
                currentNumber = value;
            }

            if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-' || i == endingIndex){
                if(oper == '+'){
                    st.push(currentNumber);
                }
                else if(oper == '-'){
                    st.push(-1 * currentNumber);
                }
                else if(oper == '*'){
                    int topValue = st.top();
                    st.pop();
                    st.push(topValue * currentNumber);
                }
                else if(oper == '/'){
                    int topValue = st.top();
                    st.pop();
                    st.push(topValue / currentNumber);
                }
                
                oper = s[i];
                currentNumber = 0;
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

    int calculate(string s){
        int sLength = s.length();

        int value = solve(s,0,sLength - 1);
        return value;
    }
};