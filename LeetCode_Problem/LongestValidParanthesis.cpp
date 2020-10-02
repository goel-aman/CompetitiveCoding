#include<bits/stdc++.h>
#include<stack>
#define ll long long int
class Solution {
public:
    int longestValidParentheses(string s) {
        long long int siz =s.length(); 
        long long int dp[siz];
        for(ll i=0;i<siz;i++){
            if(s[i] == '('){
                dp[i] = 0;
                continue;
            }
            int w = 0
            if(s[i] == ')'){
                stack<char> ss;
                ss.push(s[i]);
                int count = 0;
                for(int j=i-1;j>=0;j--){
                    if(s[j] == '('){
                        ss.pop()
                        count += 2;
                    }
                    if(s[j] == ')'){
                        ss.push(')');
                    }
                    if(ss.empty()){
                        dp[i] = count;
                        if(j - 1 >= 0){
                            dp[i] = dp[i] + dp[j - 1];
                        }
                        w = 1;
                        break;
                    }
                }
                if(w == 0){
                    dp[i] = 0;
                }
            }
        }
        int maxx = 0;
        for(int i=0;i<n;i++){
            maxx = max(maxx,dp[i]);
        }
        return maxx;
    }
};