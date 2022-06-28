#include<bits/stdc++.h>
using namespace std;

// 249. Group Shifted Strings
// We can shift a string by shifting each of its letters
//  to its successive letter.

// For example, "abc" can be shifted to be "bcd".
// We can keep shifting the string to form a sequence.

// For example, we can keep shifting "abc" to form the 
// sequence: "abc" -> "bcd" -> ... -> "xyz".
// Given an array of strings strings, group all strings[i] 
// that belong to the same shifting sequence. You may return 
// the answer in any order.

// Example 1:
// Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
// Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]

// Example 2:
// Input: strings = ["a"]
// Output: [["a"]]
 
// Constraints:
// 1 <= strings.length <= 200
// 1 <= strings[i].length <= 50
// strings[i] consists of lowercase English letters.

class Solution {
    unordered_map<string,vector<string>> groups;
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int stringsLength = strings.size();

        for(int i=0;i<stringsLength;i++){
            int ahead = strings[i][0] - 'a';
            string temp = "";
            for(int j=0;j<strings[i].length();j++){
                int val = strings[i][j] - 'a';
                val -= ahead;
                if(val < 0){
                    val += 26;
                }
                char value = 'a' + val;
                temp.push_back(value);
            }
            groups[temp].push_back(strings[i]);
        }      

        vector<vector<string>> ans;
        for(auto var: groups){
            ans.push_back(var.second);
        }
        return ans;
    }
};