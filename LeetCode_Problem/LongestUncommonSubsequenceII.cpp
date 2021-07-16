#include<bits/stdc++.h>
using namespace std;

// 522. Longest Uncommon Subsequence II
// Given an array of strings strs, return the length of 
// the longest uncommon subsequence between them. If the 
// longest uncommon subsequence does not exist, return -1.
// An uncommon subsequence between an array of strings is 
// a string that is a subsequence of one string but not
//  the others.
// A subsequence of a string s is a string that can be obtained 
// after deleting any number of characters from s.

// For example, "abc" is a subsequence of "aebdc" because you can
//  delete the underlined characters in "aebdc" to get "abc". Other 
// subsequences of "aebdc" include "aebdc", "aeb", and "" 
// (empty string).

// Example 1:
// Input: strs = ["aba","cdc","eae"]
// Output: 3

// Example 2:
// Input: strs = ["aaa","aaa","aa"]
// Output: -1
 
// Constraints:
// 1 <= strs.length <= 50
// 1 <= strs[i].length <= 10
// strs[i] consists of lowercase English letters.

bool compare(string& s1,string& s2){
    return (s1.length() > s2.length());
}

bool isSubsequence(string s1,string s2){
    int s1Length = s1.length();
    int s2Length = s2.length();

    int i = 0, j = 0;
    while(i < s1Length && j < s2Length){
        if(s1[i] == s2[j]){
            i++;
        }
        j++;
    }
    return (s1Length == i);
}

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(),strs.end(),compare);
        unordered_map<string,int> s;
        vector<string> temp;
        for(auto var : strs){
            s[var]++;
        }

        for(int i=0;i<strs.size();i++){
            if(s[strs[i]] == 1){
                bool nope = false;
                for(int j = i -1 ;j>=0;j--){
                    if(isSubsequence(strs[i],strs[j])){
                        nope = true;
                        break;
                    }                    
                }
                if(nope){
                    continue;
                }else{
                    return strs[i].length();
                }
            }
        }
        return -1;
    }
};