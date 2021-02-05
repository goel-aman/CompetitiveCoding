// 990. Satisfiability of Equality Equations

// Given an array equations of strings that represent relationships between variables,
// each string equations[i] has length 4 and takes one of two different forms: "a==b"
// or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that
// represent one-letter variable names.

// Return true if and only if it is possible to assign integers to variable
// names so as to satisfy all the given equations.

// Example 1:
// Input: ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, 
// but not the second.  There is no way to assign the variables to satisfy both equations.

// Example 2:
// Input: ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.

// Example 3:
// Input: ["a==b","b==c","a==c"]
// Output: true

// Example 4:
// Input: ["a==b","b!=c","c==a"]
// Output: false

// Example 5:
// Input: ["c==c","b==d","x!=z"]
// Output: true
 
// Note:
// 1 <= equations.length <= 500
// equations[i].length == 4
// equations[i][0] and equations[i][3] are lowercase letters
// equations[i][1] is either '=' or '!'
// equations[i][2] is '='

#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<char,vector<char>> graph;
public:

    bool finddfs(char source,char destination,unordered_map<char,bool>& visited){
        queue<char> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            char front = q.front();
            q.pop();

            if(front == destination){
                return true;
            }

            for(auto x : graph[front]){
                if(!visited.count(x)){
                    visited[x] = true;
                    q.push(x);
                }
            }
        }
        return false;
    }

    bool equationsPossible(vector<string>& equations) {
        int equationsLength = equations.size();
        vector<string> equationsNotEqual;
        for(int i=0;i<equationsLength;i++){
            if(equations[i][1] == '='){
                graph[equations[i][0]].push_back(equations[i][3]);
                graph[equations[i][3]].push_back(equations[i][0]);
            }else{
                equationsNotEqual.push_back(equations[i]);
            }
        }
        for(auto var : equationsNotEqual){
            if(var[0] == var[3]){
                return false;
            }
            if(!graph.count(var[0]) || (!graph.count(var[3]))){
                continue;
            }
            else{
                unordered_map<char,bool> visited;
                bool ans = finddfs(var[0],var[3],visited);
                if(ans){
                    return false;
                }
            }
        }
        return true;
    }
};