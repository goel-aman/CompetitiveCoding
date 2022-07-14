#include<bits/stdc++.h>
using namespace std;

// 269. Alien Dictionary
// There is a new alien language that uses the English
//  alphabet. However, the order among the letters is 
// unknown to you.

// You are given a list of strings words from the alien 
// language's dictionary, where the strings in words are
//  sorted lexicographically by the rules of this new 
// language.

// Return a string of the unique letters in the new alien 
// language sorted in lexicographically increasing order by
//  the new language's rules. If there is no solution, 
// return "". If there are multiple solutions, return any of
//  them.

// A string s is lexicographically smaller than a string t if 
// at the first letter where they differ, the letter in s comes 
// before the letter in t in the alien language. If the first 
// min(s.length, t.length) letters are the same, then s is smaller
//  if and only if s.length < t.length.

// Example 1:
// Input: words = ["wrt","wrf","er","ett","rftt"]
// Output: "wertf"

// Example 2:
// Input: words = ["z","x"]
// Output: "zx"

// Example 3:
// Input: words = ["z","x","z"]
// Output: ""
// Explanation: The order is invalid, so return "".
 
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.

class Solution {
    unordered_map<char,int> indegree;
    unordered_map<char,unordered_set<char>> graph;
public:
    string alienOrder(vector<string>& words) {
        int wordsLength = words.size();
        
        for(int i=0;i<wordsLength;i++){
            for(int j=0;j<words[i].length();j++){
                indegree[words[i][j]] = 0;  
            }
        }

        for(int i=0;i<wordsLength - 1;i++){
            string current = words[i];
            string next = words[i + 1];

            int minLength = min(current.length(),next.length());
            for(int j=0;j<minLength;j++){
                if(current[j] != next[j]){
                    if(!graph[current[j]].count(next[j])){
                        indegree[next[j]]++;
                        graph[current[j]].insert(next[j]);
                    }   
                    break; 
                }

                if(j == minLength - 1 && current.size() > next.size()){
                    return "";
                }

            }
        }

        queue<char> que;
        for(auto var : indegree){
            if(var.second == 0){
                que.push(var.first);
            }
        }
        string ans = "";
        while(!que.empty()){
            char front = que.front();
            que.pop();
            ans += front;

            for(auto var : graph[front]){
                indegree[var]--;
                if(indegree[var] == 0){
                    que.push(var);
                }
            }
        }
        if(ans.length() != indegree.size())
        {
            return "";
        }
        return ans;
    }
};