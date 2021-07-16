#include<bits/stdc++.h>
using namespace std;

// Longest Word in Dictionary through Deleting
// Given a string s and a string array dictionary, return the longest
//  string in the dictionary that can be formed by deleting some of the
//  given string characters. If there is more than one possible result,
//  return the longest word with the smallest lexicographical order. 
// If there is no possible result, return the empty string.

// Example 1:
// Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
// Output: "apple"

// Example 2:
// Input: s = "abpcplea", dictionary = ["a","b","c"]
// Output: "a"
 
// Constraints:
// 1 <= s.length <= 1000
// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 1000
// s and dictionary[i] consist of lowercase
//  English letters.


bool compare(string s1,string s2){
    if(s1.length() > s2.length()){
        return true;
    }

    if(s1.length() == s2.length()){
        if(s1  < s2){
            return true;
        }
    }
    return false;
}

class Solution {
public:
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

        if(i == s1Length){
            return true;
        }

        return false;
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(),dictionary.end(),compare);
        for(auto var : dictionary){
            if(isSubsequence(var,s))
            {
                return var;
            }
        }
        return "";
    }
};