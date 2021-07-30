#include<bits/stdc++.h>
using namespace std;

// 856. Score of Parentheses
// Given a balanced parentheses string s, return the score of the string.
// The score of a balanced parentheses string is based on the following rule:
// "()" has score 1.
// AB has score A + B, where A and B are balanced parentheses strings.
// (A) has score 2 * A, where A is a balanced parentheses string.
 
// Example 1:
// Input: s = "()"
// Output: 1

// Example 2:
// Input: s = "(())"
// Output: 2

// Example 3:
// Input: s = "()()"
// Output: 2

// Example 4:
// Input: s = "(()(()))"
// Output: 6

// Constraints:
// 2 <= s.length <= 50
// s consists of only '(' and ')'.
// s is a balanced parentheses string.


class Solution {
public:
    int scoreOfParentheses(string s) {
        int sLength = s.length();
        stack<int> st;
        for(int i=0;i<sLength;i++){
            if(s[i] == '('){
                st.push(0);
            }else{
                int value = 0;
                while(st.top() != 0) { value += st.top(); st.pop(); }
                value = max(1,2 * value);
                st.pop();
                st.push(value);
            }
        }

        int ans = 0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};