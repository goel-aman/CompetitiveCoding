#include<bits/stdc++.h>
using namespace std;

// 1698. Number of Distinct Substrings in a String
// Given a string s, return the number of distinct substrings of s.
// A substring of a string is obtained by deleting any number of 
// characters (possibly zero) from the front of the string and 
// any number (possibly zero) from the back of the string.

// Example 1:
// Input: s = "aabbaba"
// Output: 21
// Explanation: The set of distinct strings is ["a","b","aa","bb","ab"
// ,"ba","aab","abb","bab","bba","aba","aabb","abba","bbab","baba",
// "aabba","abbab","bbaba","aabbab","abbaba","aabbaba"]

// Example 2:
// Input: s = "abcdefg"
// Output: 28
 
// Constraints:
// 1 <= s.length <= 500
// s consists of lowercase English letters.
 
// Follow up: Can you solve this problem in O(n) time complexity?

class TrieNode {
    public:
    TrieNode* children[26];  
};

class Solution {
public:
    int countDistinct(string s) {
        int count = 0;
        TrieNode* root = new TrieNode();
        int sLength = s.length();

        for(int i=0;i<sLength;i++){
            TrieNode* temp = root;
            for(int j=i;j<sLength;j++){
                int index = s[j] - 'a';
                if(temp->children[index] == NULL){
                    count++;
                    temp->children[index] = new TrieNode();
                }                
                temp = temp->children[index];
            }
        }      

        return count;
    }
};