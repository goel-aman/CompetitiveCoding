#include<bits/stdc++.h>
using namespace std;

// 916. Word Subsets
// You are given two string arrays words1 and words2.
// A string b is a subset of string a if every letter in
//  b occurs in a including multiplicity.

// For example, "wrr" is a subset of "warrior" but is not
//  a subset of "world".
// A string a from words1 is universal if for every string 
// b in words2, b is a subset of a.

// Return an array of all the universal strings in words1. 
// You may return the answer in any order.

// Example 1:
// Input: words1 = ["amazon","apple","facebook","google","leetcode"],
//  words2 = ["e","o"]
// Output: ["facebook","google","leetcode"]

// Example 2:
// Input: words1 = ["amazon","apple","facebook","google","leetcode"],
//  words2 = ["l","e"]
// Output: ["apple","google","leetcode"]

// Example 3:
// Input: words1 = ["amazon","apple","facebook","google","leetcode"],
//  words2 = ["e","oo"]
// Output: ["facebook","google"]

// Example 4:
// Input: words1 = ["amazon","apple","facebook","google","leetcode"],
//  words2 = ["lo","eo"]
// Output: ["google","leetcode"]

// Example 5:
// Input: words1 = ["amazon","apple","facebook","google","leetcode"],
//  words2 = ["ec","oc","ceo"]
// Output: ["facebook","leetcode"]
 
// Constraints:
// 1 <= words1.length, words2.length <= 104
// 1 <= words1[i].length, words2[i].length <= 10
// words1[i] and words2[i] consist only of lowercase English letters.
// All the strings of words1 are unique.

class Solution {
    int words1Length;
    int words2Length;
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        words1Length = words1.size();
        words2Length = words2.size();
        vector<unordered_map<char,int>> vec(words1Length);
        for(int i=0;i<words1Length;i++){
            for(int j=0;j<words1[i].length();j++){
                vec[i][words1[i][j]]++;
            }
        }
        

        vector<unordered_map<char,int>> vec2(words2Length);
        unordered_map<char,int> maxOccurence;
        for(int i=0;i<words2Length;i++){
            for(int j=0;j<words2[i].length();j++){
                vec2[i][words2[i][j]]++;
                maxOccurence[words2[i][j]] = max(vec2[i][words2[i][j]],maxOccurence[words2[i][j]]);
            }
        }
        
        vector<string> ans;

        for(int i=0;i<words1Length;i++){
            unordered_map<char,int> first = vec[i];
            int gotAnswer = true;
            for(auto var : maxOccurence){
                if(!(first[var.first] >= var.second)){
                    gotAnswer = false;
                    break;
                }
            }
            if(gotAnswer){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};