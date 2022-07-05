#include<bits/stdc++.h>
using namespace std;

// 1065. Index Pairs of a String
// Given a string text and an array of strings words,
// return an array of all index pairs [i, j] so that 
// the substring text[i...j] is in words.
// Return the pairs [i, j] in sorted order (i.e., sort 
// them by their first coordinate, and in case of ties
// sort them by their second coordinate).

// Example 1:
// Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
// Output: [[3,7],[9,13],[10,17]]

// Example 2:
// Input: text = "ababa", words = ["aba","ab"]
// Output: [[0,1],[0,2],[2,3],[2,4]]
// Explanation: Notice that matches can overlap, see "aba" is
//  found in [0,2] and [2,4].
 
// Constraints:
// 1 <= text.length <= 100
// 1 <= words.length <= 20
// 1 <= words[i].length <= 50
// text and words[i] consist of lowercase English letters.
// All the strings of words are unique.

// abcd

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        int wordsLength = words.size();
        int textLength = text.size();
        vector<vector<int>> ans;
        for(int i=0;i<wordsLength;i++){
            int wordLength = words[i].length();
            
            if(textLength < wordLength){
                continue;
            }
            
            for(int j = 0;j<= textLength - wordLength;j++){
                string temp = text.substr(j,wordLength);
                if(temp == words[i]){
                    ans.push_back({j,j + wordLength - 1});
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};