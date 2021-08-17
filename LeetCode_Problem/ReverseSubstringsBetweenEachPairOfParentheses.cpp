#include<bits/stdc++.h>
using namespace std;

// 1190. Reverse Substrings Between Each Pair of Parentheses
// You are given a string s that consists of lower case English
//  letters and brackets. 
// Reverse the strings in each pair of matching parentheses,
//  starting from the innermost one.
// Your result should not contain any brackets.

// Example 1:
// Input: s = "(abcd)"
// Output: "dcba"

// Example 2:
// Input: s = "(u(love)i)"
// Output: "iloveu"
// Explanation: The substring "love" is reversed first,
//  then the whole string is reversed.

// Example 3:
// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
// Explanation: First, we reverse the substring "oc", then "etco", 
// and finally, the whole string.

// Example 4:
// Input: s = "a(bcdefghijkl(mno)p)q"
// Output: "apmnolkjihgfedcbq"
 
// Constraints:
// 0 <= s.length <= 2000
// s only contains lower case English characters and 
// parentheses.
// It's guaranteed that all parentheses are balanced.

class Solution {
public:
    string reverseParentheses(string s) {
        int sLength = s.length();
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i] != ')'){
                st.push(s[i]);
            }else{
                string temp = "";
                while(!st.empty() && st.top() != '('){
                    temp += st.top();
                    st.pop();
                }
                st.pop(); 

                for(int i=0;i<temp.length();i++){
                    st.push(temp[i]);
                }
                continue;
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};