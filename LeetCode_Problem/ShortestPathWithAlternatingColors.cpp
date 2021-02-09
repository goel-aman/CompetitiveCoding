// 1129. Shortest Path with Alternating Colors

// Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph,
//  each edge is either red or blue, and there could be self-edges or parallel edges.

// Each [i, j] in red_edges denotes a red directed edge from node i to node j.  Similarly,
//  each [i, j] in blue_edges denotes a blue directed edge from node i to node j.

// Return an array answer of length n, where each answer[X] is the length of the shortest
//  path from node 0 to node X such that the edge colors alternate along the path (or -1 if such a path doesn't exist).

// Example 1:
// Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
// Output: [0,1,-1]

// Example 2:
// Input: n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
// Output: [0,1,-1]

// Example 3:
// Input: n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
// Output: [0,-1,-1]


// Example 4:
// Input: n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
// Output: [0,1,2]


// Example 5:
// Input: n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
// Output: [0,1,1]
 
// Constraints:
// 1 <= n <= 100
// red_edges.length <= 400
// blue_edges.length <= 400
// red_edges[i].length == blue_edges[i].length == 2
// 0 <= red_edges[i][j], blue_edges[i][j] < n


#include<bits/stdc++.h>
using namespace std;

class elem{
    public:
    int node;
    int color;
};

class Solution {
    unordered_map<string,bool> visited;
    unordered_map<int,vector<int>> umRed;
    unordered_map<int,vector<int>> umBlue;

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        for(auto var : red_edges){
            umRed[var[0]].push_back(var[1]);            
        }

        for(auto var : blue_edges){
            umBlue[var[0]].push_back(var[1]);
        }

        vector<int> v(n,INT_MAX);

        // 1 means red
        // -1 means blue
        queue<elem> q;
        q.push({0,1});
        q.push({0,-1});
        int len = -1;
        while(!q.empty()){
            len++;
            int qsize = q.size();
            while(qsize--)
            {
                elem a = q.front();
                q.pop();
                v[a.node] = min(v[a.node],len);
                string s;
                s += to_string(a.node) + to_string(a.color);
                visited[s] = true;
                if(a.color == 1){
                    for(auto x : umBlue[a.node]){
                        string ss;
                        ss += to_string(x) + to_string(-1);
                        if(!visited.count(ss)){
                            q.push({x,-1});
                        }
                    }
                }

                if(a.color == -1){
                    for(auto x : umRed[a.node]){
                        string ss;
                        ss += to_string(x) + to_string(1);
                        if(!visited.count(ss)){
                            q.push({x,1});
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(v[i] == INT_MAX){
                v[i] = -1;
            }
        }
        return v;
    }
};