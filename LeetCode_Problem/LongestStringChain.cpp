#include<bits/stdc++.h>
using namespace std;

// 1048. Longest String Chain
// You are given an array of words where each word consists
//  of lowercase English letters.
// wordA is a predecessor of wordB if and only if we can insert
//  exactly one letter anywhere in wordA without changing the 
// order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is
//  not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk]
//  with k >= 1, where word1 is a predecessor of word2, word2 is a
//  predecessor of word3, and so on. A single word is trivially a
// word chain with k == 1.

// Return the length of the longest possible word chain with words
//  chosen from the given list of words.

// Example 1:
// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].

// Example 2:
// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc"
// , "pcxbc", "pcxbcf"].

// Example 3:
// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest
//  word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of
//  the letters is changed.
 
// Constraints:
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

bool compare(string &s1,string &s2){
    if(s1.length() < s2.length()){
        return true;
    }
    
    return false;
}

class Solution {
public:
    bool isPredecessor(string &s1,string &s2){
        int s1Length = s1.length();
        int s2Length = s2.length();

        // is s1 a predecessor of s2
        if( !(s2Length - 1 == s1Length)){
            return false;
        }

        int value = 1;
        int j = 0;
        for(int i=0;i<s2Length;i++){
            if(j == s1Length && value == 1){
                return true;
            }

            if(s2[i] == s1[j]){
                j++;
                continue;
            }

            value--;
            if(value < 0){
                return false;
            }
        }
        if(value == 0){
            return true;
        }
        return false;
    }
    
    int longestStrChain(vector<string>& words) {
        int wordsLength = words.size();
        sort(words.begin(),words.end(),compare);
        vector<int> ans(wordsLength,1);
        int maxValue = 1;
        for(int i=wordsLength - 2;i>=0;i--){
            int word1Length = words[i].length();
            for(int j = i + 1;j<wordsLength;j++){
                
                int word2Length = words[j].length();
                if(word2Length - word1Length > 1){
                    break;
                }
                if(isPredecessor(words[i],words[j])){
                    // cout<<words[i]<<" "<<words[j]<<" are predecessor"<<endl;
                    ans[i] = max(ans[i],ans[j] + 1);
                    maxValue = max(ans[i],maxValue);
                }
                
            }
        }
        return maxValue;
    }
};