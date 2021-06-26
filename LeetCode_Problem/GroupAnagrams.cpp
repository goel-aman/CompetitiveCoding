#include<bits/stdc++.h>
using namespace std;

// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together. You can 
// return the answer in any order.

// An Anagram is a word or phrase formed by rearranging the letters of a 
// different word or phrase, typically using all the original letters 
// exactly once.

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]
 
// Constraints:
// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lower-case English letters.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copyStrs = strs;
        int strsLength = strs.size();
        unordered_map<string,vector<string>> um;
        vector<vector<string>> ans;
        for(int i=0;i<strsLength;i++){
            sort(strs[i].begin(),strs[i].end());
            um[strs[i]].push_back(copyStrs[i]);
        }

        for(auto var : um){
            ans.push_back(var.second);
        }
        return ans;
    }
};