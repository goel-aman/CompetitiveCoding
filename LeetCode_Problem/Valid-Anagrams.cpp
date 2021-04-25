// 242. Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

// Constraints:
// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 
// Follow up: What if the inputs contain Unicode characters? 
// How would you adapt your solution to such a case?

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um;
        for(int i=0;i<s.length();i++){
            um[s[i]]++;
        }
        
        for(int i=0;i<t.length();i++){
            if(um.count(t[i]) > 0){
                if(um[t[i]] >= 1){
                    um[t[i]]--;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        for(auto x : um){
            if(x.second != 0){
                return false;
            }
        }
        return true;
    }
};