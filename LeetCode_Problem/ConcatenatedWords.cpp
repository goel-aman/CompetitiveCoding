// 472. Concatenated Words
// Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
// A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

// Example:
// Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

// Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

// Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
//  "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
// "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
// Note:
// The number of elements of the given array will not exceed 10,000
// The length sum of elements in the given array will not exceed 600,000.
// All the input string will only include lower case letters.
// The returned elements order does not matter.

#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<string,bool> um;
public:
    bool isPresent(string input){
        if(um.count(input) > 0){
            return true;
        }

        int length = input.length();
        for(int i=1;i<=length - 1;i++){
            bool ans = false;
            string one = input.substr(0,i);
            string two = input.substr(i);
            if(um.count(one) > 0) {
                ans = (ans || isPresent(two));
            }
            if(ans){
                return true;
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto s : words){
            um[s] = true;
        }
        vector<string> anss;
        for(auto s : words){
            int length = s.length();
            bool ans = false;
            for(int i=1;i<=length - 1;i++){
                string one = s.substr(0,i);
                string two = s.substr(i);
                if(um.count(one) > 0){
                    ans = ans || isPresent(two);
                }
                if(ans){
                    anss.push_back(s);
                    break;
                }
            }
        }
        return anss;
    }
};