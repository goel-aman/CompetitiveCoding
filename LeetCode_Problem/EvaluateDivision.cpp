// 399. Evaluate Division

// You are given an array of variable pairs equations and an array of real
//  numbers values, where equations[i] = [Ai, Bi] and values[i] represent 
// the equation Ai / Bi = values[i]. Each Ai or Bi is a string that 
// represents a single variable.

// You are also given some queries, where queries[j] = [Cj, Dj] represents
//  the jth query where you must find the answer for Cj / Dj = ?.

// Return the answers to all queries. If a single answer cannot
//  be determined, return -1.0.

// Note: The input is always valid. You may assume that evaluating 
// the queries will not result in division by zero and that there is no contradiction.


// Example 1:
// Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
// Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
// Explanation: 
// Given: a / b = 2.0, b / c = 3.0
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
// return: [6.0, 0.5, -1.0, 1.0, -1.0 ]


// Example 2:
// Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
// Output: [3.75000,0.40000,5.00000,0.20000]


// Example 3:
// Input: equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
// Output: [0.50000,2.00000,-1.00000,-1.00000]
 
 // Constraints:

// 1 <= equations.length <= 20
// equations[i].length == 2
// 1 <= Ai.length, Bi.length <= 5
// values.length == equations.length
// 0.0 < values[i] <= 20.0
// 1 <= queries.length <= 20
// queries[i].length == 2
// 1 <= Cj.length, Dj.length <= 5
// Ai, Bi, Cj, Dj consist of lower case English letters and digits.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // answer is initialized with -1 only.
    // temp is initialized with 1.
    void dfs(string start,string end,unordered_map<string,unordered_map<string,double>>& um,unordered_map<string,bool> visited,double &ans,double temp){
        if(start == end){
            ans = temp;
            return;
        }

        if(!um.count(start)){
            return ;
        }

        for(auto x: um[start]){
            if(!visited.count(x.first)){
                visited[x.first] = true;
                dfs(x.first,end,um,visited,ans,temp * x.second);
            }
        }
        return ;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> um;
        
        for(int i=0;i<equations.size();i++){
            um[equations[i][0]][equations[i][1]] = values[i];
            um[equations[i][1]][equations[i][0]] = (1/values[i]);
        }
        vector<double> vv;
        for(int i=0;i<queries.size();i++){
            if(!um.count(queries[i][0]) || !um.count(queries[i][1])){
                vv.push_back(-1);
                continue;
            }
            double ans = -1;
            unordered_map<string,bool> visited;
            visited[queries[i][0]] = true;
            dfs(queries[i][0],queries[i][1],um,visited,ans,1);
            vv.push_back(ans);
        }
        return vv;
    }
};