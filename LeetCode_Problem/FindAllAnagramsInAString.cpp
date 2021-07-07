#include<bits/stdc++.h>
using namespace std;

// 438. Find All Anagrams in a String
// Given two strings s and p, return an array of all the 
// start indices of p's anagrams in s. You may return the
//  answer in any order.

// Example 1:
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", 
// which is an anagram of "abc".
// The substring with start index = 6 is "bac",
//  which is an anagram of "abc".

// Example 2:
// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab",
//  which is an anagram of "ab".
// The substring with start index = 1 is "ba",
//  which is an anagram of "ab".
// The substring with start index = 2 is "ab",
//  which is an anagram of "ab".

// Constraints:
// 1 <= s.length, p.length <= 3 * 104
// s and p consist of lowercase English letters.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec(26,0);
        int sLength = s.length();
        int pLength = p.length();
        
        for(int i=0;i<pLength;i++){
            vec[p[i] - 'a']++;
        }

        vector<int> ans;
        
        if(pLength > sLength){
            return ans;
        }
        for(int i=0;i<= s.length() - pLength;i++){
            string sub = s.substr(i,pLength);
            vector<int> vecc(26,0);
            for(int j=0;j<pLength;j++){
                vecc[sub[j] - 'a']++;
            }

            bool isValid = true;
            for(int j = 0;j<26;j++){
                if(vecc[j] != vec[j]){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                ans.push_back(i);
            }
        }
        return ans;
    }
};