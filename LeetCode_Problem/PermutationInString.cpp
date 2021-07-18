#include<bits/stdc++.h>
using namespace std;

// 567. Permutation in String
// Given two strings s1 and s2, return true if
// s2 contains the permutation of s1.
// In other words, one of s1's permutations is 
// the substring of s2.

// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

// Constraints:
// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

class Solution {
public:
    // s1 is a part of s2 or not
    bool checkInclusion(string s1, string s2) {
        int s2Length = s2.length();
        int s1Length = s1.length();

        vector<int> freqS1(27,0);
        for(int i=0;i<s1Length;i++){
            freqS1[s1[i] - 'a' + 1]++;
        }

        vector<vector<int>> prefix(s2Length,vector<int> (27,0));
        for(int i=0;i<s2Length;i++){
            prefix[i][s2[i] - 'a' + 1]++;
            if(i + 1 - s1Length >= 0){
                for(int j=1;j<=26;j++)
                {
                    if(freqS1[j] == prefix[i][j] - prefix[i + 1 - s1Length][j]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};





