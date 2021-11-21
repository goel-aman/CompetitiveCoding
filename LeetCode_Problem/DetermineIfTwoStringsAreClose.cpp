#include<bits/stdc++.h>
using namespace std;

// 1657. Determine if Two Strings Are Close
// Two strings are considered close if you can attain 
// one from the other using the following operations:
// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing
//  character into another existing character, and do the 
// same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, 
// and all b's turn into a's)
// You can use the operations on either string as many 
// times as necessary.

// Given two strings, word1 and word2, return true if word1 
// and word2 are close, and false otherwise.

// Example 1:
// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"

// Example 2:
// Input: word1 = "a", word2 = "aa"
// Output: false
// Explanation: It is impossible to attain word2 from word1, or 
// vice versa, in any number of operations.

// Example 3:
// Input: word1 = "cabbba", word2 = "abbccc"
// Output: true
// Explanation: You can attain word2 from word1 in 3 operations.
// Apply Operation 1: "cabbba" -> "caabbb"
// Apply Operation 2: "caabbb" -> "baaccc"
// Apply Operation 2: "baaccc" -> "abbccc"

// Example 4:
// Input: word1 = "cabbba", word2 = "aabbss"
// Output: false
// Explanation: It is impossible to attain word2 from word1, or 
// vice versa, in any amount of operations.
 
// Constraints:
// 1 <= word1.length, word2.length <= 105
// word1 and word2 contain only lowercase English letters.


class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int word1Length = word1.length(), word2Length = word2.length();
        if(word1Length != word2Length){
            return false;
        }

        unordered_set<char> first,second;
        unordered_map<char,int> firstFrequency,secondFrequency;
        for(int i=0;i<word1Length;i++){
            first.insert(word1[i]);
            firstFrequency[word1[i]]++;
        }      

        for(int i=0;i<word2Length;i++){
            if(!first.count(word2[i])){
                return false;
            }
            secondFrequency[word2[i]]++;
            second.insert(word2[i]);
        }

        for(auto var : first){
            if(!second.count(var)){
                return false;
            }
        }

        vector<int> arr1,arr2;
        for(auto var : firstFrequency){
            arr1.push_back(var.second);
        }
        for(auto var : secondFrequency){
            arr2.push_back(var.second);
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr1.size();i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
};