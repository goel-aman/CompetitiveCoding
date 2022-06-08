#include<bits/stdc++.h>
using namespace std;

// 1858. Longest Word With All Prefixes
// Given an array of strings words, find the longest string in 
// words such that every prefix of it is also in words.

// For example, let words = ["a", "app", "ap"]. The string "app" 
// has prefixes "ap" and "a", all of which are in words.
// Return the string described above. If there is more than one 
// string with the same length, return the lexicographically 
// smallest one, and if no string exists, return "".

// Example 1:
// Input: words = ["k","ki","kir","kira", "kiran"]
// Output: "kiran"
// Explanation: "kiran" has prefixes "kira", "kir", "ki", and "k", 
// and all of them appear in words.

// Example 2:
// Input: words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
// Output: "apple"
// Explanation: Both "apple" and "apply" have all their prefixes in words.
// However, "apple" is lexicographically smaller, so we return that.

// Example 3:
// Input: words = ["abc", "bc", "ab", "qwe"]
// Output: ""
 
// Constraints:
// 1 <= words.length <= 105
// 1 <= words[i].length <= 105
// 1 <= sum(words[i].length) <= 105

class Solution {
public:
    bool static compare(string& first,string& second){
        if(first.length() < second.length()){
            return true;
        }
        
        return false;
    }
    
    string longestWord(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        string ans = "";
        unordered_set<string> isThere;
        isThere.insert("");
        for(int i=0;i<words.size();i++){
            if(isThere.count(words[i].substr(0,words[i].length() - 1))){
                isThere.insert(words[i]);
                if(words[i].length() > ans.length() || words[i] < ans){
                    ans = words[i];
                }
            }
        }
        return ans;
    }
}; 