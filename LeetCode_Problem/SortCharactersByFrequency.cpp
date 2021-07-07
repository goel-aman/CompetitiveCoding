#include<bits/stdc++.h>
using namespace std;

// 451. Sort Characters By Frequency
// Given a string s, sort it in decreasing order based on 
// the frequency of characters, and return the sorted string.

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore 
// "eetr" is also a valid answer.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, 
// so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same 
// characters must be together.

// Example 3:
// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer,
//  but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two 
// different characters.
 
// Constraints:
// 1 <= s.length <= 5 * 105
// s consists of English letters and digits.


class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> um;
        for(auto var : s){
            um[var]++;
        }

        for(auto var : um){
            pq.push({var.second,var.first});
        }
        string ans = "";
        while(!pq.empty()){
            pair<int,char> front = pq.top();
            pq.pop();

            for(int i=0;i<front.first;i++){
                ans.push_back(front.second);
            }
        }        
        return ans;
    }
};