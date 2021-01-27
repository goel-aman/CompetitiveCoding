// 797. All Paths From Source to Target

// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible
//  paths from node 0 to node n - 1, and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i 
// (i.e., there is a directed edge from node i to node graph[i][j]).

 
// Example 1:


// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Example 2:


// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
// Example 3:

// Input: graph = [[1],[]]
// Output: [[0,1]]
// Example 4:

// Input: graph = [[1,2,3],[2],[3],[]]
// Output: [[0,1,2,3],[0,2,3],[0,3]]
// Example 5:

// Input: graph = [[1,3],[2],[3],[]]
// Output: [[0,1,2,3],[0,3]]
 

// Constraints:

// n == graph.length
// 2 <= n <= 15
// 0 <= graph[i][j] < n
// graph[i][j] != i (i.e., there will be no self-loops).
// The input graph is guaranteed to be a DAG.



// Solution

#include<bits/stdc++.h>
using namespace std;

class Solution {
    int nn;
public:
    
    vector<vector<int>> allPathsSourceTargeth(vector<vector<int>>& graph,int source,vector<int> visited){
        
        if(source == nn - 1){
            vector<vector<int>> v;
            vector<int> vv;
            vv.push_back(nn - 1);
            v.push_back(vv);
            return v;
        }

        vector<vector<int>> ans;
        visited[source] = 1;
        for(int i=0;i<graph[source].size();i++){
            if(!visited[ graph[source][i] ]){
                vector<vector<int>> vm = allPathsSourceTargeth(graph,graph[source][i],visited);
                for(int j=0;j<vm.size();j++){
                    vector<int> vvv(vm[j]);
                    vvv.push_back(source);
                    ans.push_back(vvv);
                }
            }
        }
        visited[source] = 0;
        return ans;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n+1,0);
        nn = n;
        vector<vector<int>> v = allPathsSourceTargeth(graph,0,visited);
        vector<vector<int>> ans;
        for(int i=0;i<v.size();i++){
            reverse(v[i].begin(),v[i].end());
        }
        return v;
    }
};