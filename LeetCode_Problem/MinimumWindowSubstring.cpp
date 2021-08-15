#include<bits/stdc++.h>
using namespace std;

// 76. Minimum Window Substring
// Given two strings s and t of lengths m and n respectively,
// return the minimum window substring of s such that every
//  character in t (including duplicates) is included in the
//  window. If there is no such substring, return the empty 
// string "".
// The testcases will be generated such that the answer 
// is unique.

// A substring is a contiguous sequence of characters within
//  the string.

// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes
//  'A', 'B', and 'C' from string t.

// Example 2:
// Input: s = "a", t = "a"
// Output: "a"
// Explanation: The entire string s is the minimum window.

// Example 3:
// Input: s = "a", t = "aa"
// Output: ""
// Explanation: Both 'a's from t must be 
// included in the window.
// Since the largest window of s only has one 'a', 
// return empty string.
 
// Constraints:
// m == s.length
// n == t.length
// 1 <= m, n <= 105
// s and t consist of uppercase and lowercase English letters.
 
// Follow up: Could you find an algorithm that 
// runs in O(m + n) time?


class Solution {
public:
    bool isValid(unordered_map<char,int> &tMap,unordered_map<char,int> &currentMap){
        for(auto &var : tMap){
            if(!currentMap.count(var.first)){
                return false;
            }

            if(currentMap[var.first] < var.second){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int tLength = t.length();
        int sLength = s.length();
        unordered_map<char,int> tMap,currentMap;
        for(int i=0;i<tLength;i++){
            tMap[t[i]]++;
        }

        int ans = INT_MAX; 
        string ansValue = "";
        string currentValue = "";
        int start = 0, end = 0;
        while(end < sLength){
            currentMap[s[end]]++;
            end++;
            if(end == sLength){
                cout<<"start is : "<<start<<"end is : "<<end<<endl;
            }
            if(isValid(tMap,currentMap)){
                if(end - start < ans){
                    ans = end - start;
                    ansValue = s.substr(start,ans);
                }
            }else{
                continue;
            }

            while(start < end && isValid(tMap,currentMap)){
                if(end - start < ans){
                    ans = end - start;
                    ansValue = s.substr(start,ans);
                }
                currentMap[s[start]]--;
                start++;
            }
        }
        return ansValue;
    }
};