#include<bits/stdc++.h>
using namespace std;

// 5. Longest Palindromic Substring

// Given a string s, return the longest 
// palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

// Example 3:
// Input: s = "a"
// Output: "a"

// Example 4:
// Input: s = "ac"
// Output: "a"
 
// Constraints:
// 1 <= s.length <= 1000
// s consist of only digits and English 
// letters (lower-case and/or upper-case),

class Solution {
public:
    string longestPalindrome(string s) {
        int ans = 0;
        string value = "";
        int sLength = s.length();
        vector<vector<int>> vec(sLength,vector<int>(sLength,0));
        for(int i=0;i<sLength;i++){
            vec[i][i] = 1;
            int len = i - i + 1;
            if(len > ans){
                ans = len;
                value = s.substr(i,len);
            }
        }

        int row = 0;
        int col = 1;
        while(row < sLength && col < sLength){
            if(s[row] == s[col]){
                vec[row][col] = 1;
                int len = col - row + 1;
                if(len > ans){
                    ans = len;
                    value = s.substr(row,len);
                }
            }
            row++;
            col++;
        }

        for(int i=2;i<sLength;i++){
            row = 0;
            col = i;
            while(row < sLength && col < sLength){
                if(s[row] == s[col]){
                    vec[row][col] = vec[row + 1][col - 1];
                    int len = col - row + 1;
                    if(len > ans){
                        ans = len;
                        value = s.substr(row,len);
                    }
                }
                row++;
                col++;
            }
        }

        return value;
    }
};