#include<bits/stdc++.h>
using namespace std;

// 1297. Maximum Number of Occurrences of a Substring
// Given a string s, return the maximum number of ocurrences
//  of any substring under the following rules:
// The number of unique characters in the substring must be 
// less than or equal to maxLetters.
// The substring size must be between minSize and maxSize
//  inclusive.
 
// Example 1:
// Input: s = "aababcaab", maxLetters = 2, minSize = 3, maxSize = 4
// Output: 2
// Explanation: Substring "aab" has 2 ocurrences in the
//  original string.
// It satisfies the conditions, 2 unique letters and size 3
//  (between minSize and maxSize).

// Example 2:
// Input: s = "aaaa", maxLetters = 1, minSize = 3, maxSize = 3
// Output: 2
// Explanation: Substring "aaa" occur 2 times in the string.
//  It can overlap.

// Example 3:
// Input: s = "aabcabcab", maxLetters = 2, minSize = 2, maxSize = 3
// Output: 3

// Example 4:
// Input: s = "abcde", maxLetters = 2, minSize = 3, maxSize = 3
// Output: 0
 
// Constraints:
// 1 <= s.length <= 10^5
// 1 <= maxLetters <= 26
// 1 <= minSize <= maxSize <= min(26, s.length)
// s only contains lowercase English letters.


class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int sLength = s.length();
        // int ans = 0;
        vector<vector<int>> vec(sLength + 1,vector<int> (26,0));
        for(int i=0;i<sLength;i++){
            int value = s[i] - 'a';
            if(i == 0){
                vec[i + 1][value] = 1;
                continue; 
            }

            vec[i + 1] = vec[i];
            vec[i + 1][value] = vec[i][value] + 1;
        }

        
        unordered_map<string,int> um;
        int i = minSize;
            for(int j=0;j<=sLength - i;j++){
                string temp = s.substr(j,i);
                int target = j + i;
                int differentCharacters = 0;
                for(int iter = 0;iter < 26;iter++){
                    if(vec[target][iter] - vec[j][iter] > 0){
                        differentCharacters++;
                    }
                }
                if(differentCharacters <= maxLetters){
                    um[temp]++;
                }
            }
        

        int ans = INT_MIN;
        for(auto &var : um){
            ans = max(ans,var.second);
        }
        return (ans == INT_MIN) ? 0 : ans;
    }
};