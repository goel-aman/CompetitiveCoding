#include<bits/stdc++.h>
using namespace std;

// 616. Add Bold Tag in String
// You are given a string s and an array of strings
//  words. You should add a closed pair of bold tag 
// <b> and </b> to wrap the substrings in s that exist 
// in words. If two such substrings overlap, you should 
// wrap them together with only one pair of closed bold-tag. 
// If two substrings wrapped by bold tags are consecutive, you
//  should combine them.
// Return s after adding the bold tags.

// Example 1:
// Input: s = "abcxyz123", words = ["abc","123"]
// Output: "<b>abc</b>xyz<b>123</b>"

// Example 2:
// Input: s = "aaabbcc", words = ["aaa","aab","bc"]
// Output: "<b>aaabbc</b>c"
 
// Constraints:
// 1 <= s.length <= 1000
// 0 <= words.length <= 100
// 1 <= words[i].length <= 1000
// s and words[i] consist of English letters and digits.
// All the values of words are unique.

// Note: This question is the same as 758: https://leetcode.com/problems/bold-words-in-string/


class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        int sLength = s.length();
        int wordsLength = words.size();
        vector<vector<int>> sections;
        
        if(wordsLength == 0){
            return s;
        }
        
        for(int i=0;i<wordsLength;i++){
            string word = words[i];
            int wordLength = word.length();
            for(int i=0;i<=sLength - wordLength;i++){
                if(s.substr(i,wordLength) == word){
                    sections.push_back({i,i + wordLength - 1});
                }
            }
        }

        unordered_set<int> store;
        sort(sections.begin(),sections.end());
        
        int sectionsLength = sections.size();
        if(sectionsLength == 0){
            return s;
        }
        bool zeroNegative = false;
        int firstStart = sections[0][0], firstEnd = sections[0][1];
        
        for(int i=1;i<sectionsLength;i++){
            int secondStart = sections[i][0],secondEnd = sections[i][1];
            if(secondStart > firstEnd + 1){
                store.insert(firstStart);
                store.insert(-1* (firstEnd));
                if(firstEnd == 0){
                    zeroNegative = true;
                }
                firstStart = secondStart;
                firstEnd = secondEnd;
                continue;
            }
            else{
                firstEnd = max(firstEnd,secondEnd);
            }
        }
        store.insert(firstStart);
        store.insert(-1 * firstEnd);
        if(firstEnd == 0){
            zeroNegative = true;
        }
        
        string ans = "";
        
        for(int i=0;i<sLength;i++){
            if(store.count(i)){
                ans += "<b>";
            }

            ans += s[i];
            
            if(i != 0 && store.count(-1 * i)){
                    ans += "</b>";
            }
            
            if(i == 0 && zeroNegative){
                ans += "</b>";
            }
        }
        
        return ans;
    }
};