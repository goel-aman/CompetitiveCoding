#include<bits/stdc++.h>
using namespace std;

// 767. Reorganize String
// Given a string s, rearrange the characters of s so that any two 
// adjacent characters are not the same.
// Return any possible rearrangement of s or return "" if not possible.

// Example 1:
// Input: s = "aab"
// Output: "aba"

// Example 2:
// Input: s = "aaab"
// Output: ""
 
// Constraints:
// 1 <= s.length <= 500
// s consists of lowercase English letters.


class Solution {
public:
    string reorganizeString(string s) {
        int sLength = s.length();
        unordered_map<char,int> um;
        for(int i=0;i<sLength;i++){
            um[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto var : um){
            pq.push({var.second,var.first});
        }
        string ans = "";
        char lastChar = '-';
        while(!pq.empty() && (pq.size() > 1)){
            pair<int,char> p1 = pq.top();
            pq.pop();
            pair<int,char> p2 = pq.top();
            pq.pop();
            ans += p1.second;
            ans += p2.second;
            lastChar = p2.second;

            p1.first -= 1;
            p2.first -= 1;
            if(p1.first > 0){
                pq.push({p1.first,p1.second});
            }

            if(p2.first > 0){
                pq.push({p2.first,p2.second});
            }
        }
        if(pq.size() == 0){
            return ans;
        }

        pair<int,char> top = pq.top();
        if(top.first == 1){
            if(lastChar != top.second){
                ans += top.second;
                return ans;
            }
        }

        return "";
    }
};