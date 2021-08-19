#include<bits/stdc++.h>
using namespace std;

// 1234. Replace the Substring for Balanced String
// You are given a string containing only 4 kinds of
//  characters 'Q', 'W', 'E' and 'R'.

// A string is said to be balanced if each of its characters
// appears n/4 times where n is the length of the string.

// Return the minimum length of the substring that can be
//  replaced with any other string of the same length to 
// make the original string s balanced.

// Return 0 if the string is already balanced.

// Example 1:
// Input: s = "QWER"
// Output: 0
// Explanation: s is already balanced.

// Example 2:
// Input: s = "QQWE"
// Output: 1
// Explanation: We need to replace a 'Q' to 'R', so that
//  "RQWE" (or "QRWE") is balanced.

//Example 3:
// Input: s = "QQQW"
// Output: 2
// Explanation: We can replace the first "QQ" to "ER". 

// Example 4:
// Input: s = "QQQQ"
// Output: 3
// Explanation: We can replace the last 3 'Q' to 
// make s = "QWER".
 
// Constraints:
// 1 <= s.length <= 10^5
// s.length is a multiple of 4
// s contains only 'Q', 'W', 'E' and 'R'.


class Solution {
public:
    bool check(unordered_map<char,int>& need){  
        bool value = true;
        for(auto &var : need){
            if(var.second > 0){
                return false;
            }
        }
        return value;
    }

    int balancedString(string s) {
        int sLength = s.length();
        int exact = sLength / 4;
        unordered_map<char,int> need;
        unordered_map<char,int> count;
        count['Q'] = 0;
        count['W'] = 0;
        count['E'] = 0;
        count['R'] = 0;
        for(int i=0;i<s.length();i++){
            count[s[i]]++;
        }
        int gotAnswer = true;
        for(auto &var : count){
            if(var.second > exact){
                need[var.first] = var.second - exact;
                gotAnswer = false;
            }
        }   

        if(gotAnswer){
            return 0;
        }

        int ans = INT_MAX;
        int start = 0, end = 0;
        while(end < sLength){
            if(check(need) == false){
                need[s[end]]--;
                end++;               
            }
            
            if(check(need) == true){
                ans = min(ans,end - start);
                while(check(need)){
                    ans = min(ans,end - start);
                    need[s[start]]++;
                    start++;
                }
            }
        }      
        return ans;
    }
};