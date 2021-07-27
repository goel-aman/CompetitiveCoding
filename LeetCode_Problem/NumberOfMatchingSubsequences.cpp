#include<bits/stdc++.h>
using namespace std;

// 792. Number of Matching Subsequences
// Given a string s and an array of strings words, 
// return the number of words[i] that is a subsequence of s.
// A subsequence of a string is a new string generated
//  from the original string with some characters (can
//  be none) deleted without changing the relative order 
// of the remaining characters.
// For example, "ace" is a subsequence of "abcde".

// Example 1:
// Input: s = "abcde", words = ["a","bb","acd","ace"]
// Output: 3
// Explanation: There are three strings in words that are 
// a subsequence of s: "a", "acd", "ace".

// Example 2:
// Input: s = "dsahjpjauf", words = ["ahjpjau","ja",
// "ahbwzgqnuk","tnmlanowax"]
// Output: 2
 
// Constraints:
// 1 <= s.length <= 5 * 104
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 50
// s and words[i] consist of only lowercase English letters.

class Solution {
    int wordsLength;
    int sLength;
    unordered_map<string,int> um;
public:
    bool isSubsequence(string s,string word){
        int wordLength = word.length();
        int i=0, j=0;
        while(i < sLength && j < wordLength){
            if(s[i] == word[j]){
                i++;
                j++;
                continue;
            }

            i++;
        }

        if(j == wordLength){
            return true;
        }

        return false;
    }

    int numMatchingSubseq(string s, vector<string>& words) {
        wordsLength = words.size();
        sLength = s.length();
        set<string> uniqueWords;
        for(auto var : words){
            um[var]++;
            uniqueWords.insert(var);
        }
        int count = 0;
        for(auto var : uniqueWords){
            if(isSubsequence(s,var)){
                count += um[var];
            }
        }
        return count;
    }
};