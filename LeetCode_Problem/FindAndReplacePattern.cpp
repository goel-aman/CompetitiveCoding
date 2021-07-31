#include<bits/stdc++.h>
using namespace std;

// 890. Find and Replace Pattern
// Given a list of strings words and a string pattern, return a
//  list of words[i] that match pattern. You may return the 
// answer in any order.

// A word matches the pattern if there exists a permutation of 
// letters p so that after replacing every letter x in the pattern
//  with p(x), we get the desired word.

// Recall that a permutation of letters is a bijection from letters
//  to letters: every letter maps to another letter, and no two 
// letters map to the same letter.

// Example 1:
// Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
// Output: ["mee","aqq"]
// Explanation: "mee" matches the pattern because there is
//  a permutation {a -> m, b -> e, ...}. 
// "ccc" does not match the pattern because {a -> c, b -> c, ...} is 
// not a permutation, since a and b map to the same letter.

// Example 2:
// Input: words = ["a","b","c"], pattern = "a"
// Output: ["a","b","c"]
 
// Constraints:
// 1 <= pattern.length <= 20
// 1 <= words.length <= 50
// words[i].length == pattern.length
// pattern and words[i] are lowercase English letters.

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        int wordsLength = words.size();
        int patternLength = pattern.length();
        vector<string> ans;
        for(int i=0;i<wordsLength;i++){
            if(words[i].length() == patternLength){
                unordered_map<char,char> um;
                unordered_map<char,int> assigned;
                for(int j=0;j<patternLength;j++){
                    if(!um.count(pattern[j])){
                        um[pattern[j]] = words[i][j];
                        assigned[words[i][j]] = pattern[j];
                    }
                }

                string temp = "";
                for(int j=0;j<patternLength;j++){
                    if(assigned.count(words[i][j]) > 0){
                        temp += assigned[words[i][j]];
                    }
                    else{
                        temp += words[i][j];
                    }
                }
                
                if(temp == pattern){
                    ans.push_back(words[i]);
                }

            }
        }
        return ans;
    }
};