// 802. Find Eventual Safe States

// We start at some node in a directed graph, and every turn, we walk along a directed
// edge of the graph. If we reach a terminal node (that is, it has no outgoing directed edges), we stop.

// We define a starting node to be safe if we must eventually walk to a terminal node.
//  More specifically, there is a natural number k, so that we must have stopped at a
//  terminal node in less than k steps for any choice of where to walk.

// Return an array containing all the safe nodes of the graph. The answer should be 
// sorted in ascending order.

// The directed graph has n nodes with labels from 0 to n - 1, where n is the length of
//  graph. The graph is given in the following form: graph[i] is a list of labels j such
//  that (i, j) is a directed edge of the graph, going from node i to node j.

 
// Example 1:
// Illustration of graph
// Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
// Output: [2,4,5,6]
// Explanation: The given graph is shown above.

// Example 2:
// Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
// Output: [4]
 

// Constraints:

// n == graph.length
// 1 <= n <= 104
// 0 <= graph[i].legnth <= n
// graph[i] is sorted in a strictly increasing order.
// The graph may contain self-loops.
// The number of edges in the graph will be in the range [1, 4 * 104].

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,bool> safe;

public:
    bool dfs(int start,vector<vector<int>>& graph,vector<int> visited){
        if(visited[start]){
            safe[start] = false;
            return false;
        }

        if(safe.count(start) > 0){
            return safe[start];
        }

        visited[start] = 1;
        for(auto x : graph[start]){
            if(safe.count(x) > 0){
                if(safe[x] == true){
                    continue;
                }
                else{
                    return safe[start] = false;
                }
            }
            if(!dfs(x,graph,visited)){
                return safe[start] = false;
            }
        }

        return safe[start] = true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int length = graph.size();
        vector<int> ans;
        vector<int> visited(length,0);
        for(int i=0;i<length;i++){
            if(safe.count(i) > 0){
                if(safe[i] == true){
                    ans.push_back(i);
                    continue;
                }
                if(safe[i] == false){
                    continue;
                }
            }
            if(dfs(i,graph,visited)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};