#include<bits/stdc++.h>
using namespace std;

// 150. Evaluate Reverse Polish Notation

// Evaluate the value of an arithmetic expression in Reverse 
// Polish Notation.
// Valid operators are +, -, *, and /. Each operand may be an
//  integer or another expression.
// Note that division between two integers should truncate 
// toward zero.
// It is guaranteed that the given RPN expression is always valid.
//  That means the expression would always evaluate to a result, and 
// there will not be any division by zero operation.

// Example 1:
// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

// Example 2:
// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

// Example 3:
// Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
// Output: 22
// Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
// = ((10 * (6 / (12 * -11))) + 17) + 5
// = ((10 * (6 / -132)) + 17) + 5
// = ((10 * 0) + 17) + 5
// = (0 + 17) + 5
// = 17 + 5
// = 22
 
// Constraints:
// 1 <= tokens.length <= 104
// tokens[i] is either an operator: "+", "-", "*", or "/", or an 
// integer in the range [-200, 200].

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "*"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first * second);
                continue;
            }

            if(tokens[i] == "/"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push( second / first);
                continue;
            }

            if(tokens[i] == "+"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(first + second);
                continue;
            }

            if(tokens[i] == "-"){
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                st.push(second - first);
                continue;
            }

            st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};