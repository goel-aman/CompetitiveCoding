#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int ans = true;
        int sLength = s.length();
        for(int i=0;i<sLength;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if(st.size() == 0){
                    return false;
                }
                char top = st.top();
                if(s[i] == ')' && top == '('){
                    st.pop();
                    continue;
                }

                if(s[i] == '}' && top == '{'){
                    st.pop();
                    continue;
                }

                if(s[i] == ']' && top == '['){
                    st.pop();
                    continue;
                }
                else{
                    ans = false;
                    break;
                }
            }
        }
        if(ans == false || st.size() > 0){
            return false;
        }
        return true;
    }
};