#include<bits/stdc++.h>
using namespace std;

// 1653. Minimum Deletions to Make String Balanced
// You are given a string s consisting only of characters 'a' and 'b'​​​​.
// You can delete any number of characters in s to make s balanced. 
// s is balanced if there is no pair of indices (i,j) such that i < j
//  and s[i] = 'b' and s[j]= 'a'.
// Return the minimum number of deletions needed to make s balanced.

// Example 1:
// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").

// Example 2:
// Input: s = "bbaaaaabb"
// Output: 2
// Explanation: The only solution is to delete the first two characters.
 
// Constraints:
// 1 <= s.length <= 105
// s[i] is 'a' or 'b'​​.


class Solution {
public:
    int minimumDeletions(string s) {
        int sLength = s.length();
        vector<int> countA(sLength + 1,0);
        vector<int> countB(sLength + 1,0);
        for(int i=1;i<=sLength;i++){
            if(s[i - 1] == 'a'){
                countA[i] = countA[i - 1] + 1;
            }
        }

        for(int i=sLength - 1;i>=0;i--){
            if(s[i] == 'b'){
                countB[i] = countB[i + 1] + 1;
            }
        }

        int deletion = INT_MAX;
        for(int i=0;i<=sLength;i++){
            int totalA = countA[i];
            int totalB = countB[i];

            int del = (i - totalA) + ((sLength - i) - totalB);
            deletion = min(deletion,del);
        }
        return deletion;
    }
};
class Solution {
public:
    int minimumDeletions(string s) {
        int sLength = s.length();
        vector<int> countA(sLength + 1,0);
        vector<int> countB(sLength + 1,0);
        for(int i=1;i<=sLength;i++){
            if(s[i - 1] == 'a'){
                countA[i] = countA[i - 1] + 1;
            }else{
                countA[i] = countA[i - 1];
            }
        }

        for(int i=sLength - 1;i>=0;i--){
            if(s[i] == 'b'){
                countB[i] = countB[i + 1] + 1;
            }else{
                countB[i] = countB[i + 1];
            }
        }

        int deletion = INT_MAX;
        for(int i=0;i<=sLength;i++){
            int totalA = countA[i];
            int totalB = countB[i];

            int del = (i - totalA) + ((sLength - i) - totalB);
            deletion = min(deletion,del);
        }
        return deletion;
    }
};