#include<bits/stdc++.h>
using namespace std;

// 161. One Edit Distance
// Given two strings s and t, return true if they are
//  both one edit distance apart, otherwise return false.

// A string s is said to be one distance apart from a 
// string t if you can:

// Insert exactly one character into s to get t.
// Delete exactly one character from s to get t.
// Replace exactly one character of s with a different 
// character to get t.
 
// Example 1:
// Input: s = "ab", t = "acb"
// Output: true
// Explanation: We can insert 'c' into s to get t.

// Example 2:
// Input: s = "", t = ""
// Output: false
// Explanation: We cannot get t from s by only one step.
 
// Constraints:
// 0 <= s.length, t.length <= 104
// s and t consist of lowercase letters, uppercase letters,
//  and digits.


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int sLength = s.length();
        int tLength = t.length();

        if(sLength == tLength){
            int count = 0;
            for(int i=0;i<sLength;i++){
                if(s[i] != t[i]){
                    count++;
                }
            }
            if(count == 1){
                return true;
            }
            return false;
        }
        else if(sLength > tLength){
            if(sLength - tLength > 1){
                return false;
            }
            // We have to perform Delete Operation
            int j = 0;
            int mismatch = 0;
            for(int i=0;i<tLength;i++){
                if(s[j] == t[i]){
                    j++;
                    continue;
                }else{
                    mismatch++;
                    j++;
                    i--;
                    if(mismatch > 1){
                        return false;
                    }
                }
            }
            return true;
        }
        else{
            if(abs(tLength - sLength) > 1){
                return false;
            }
            // tLength > sLength // addition of one character in s
            int j = 0;
            int count = 0;
            for(int i=0;i<tLength;i++){
                if(t[i] == s[j]){
                    j++;
                    continue;
                }else{
                    count++;
                    if(count > 1){
                        return false;
                    }
                    continue;
                }
            }
            return true;
        }
        return true;
    }
};