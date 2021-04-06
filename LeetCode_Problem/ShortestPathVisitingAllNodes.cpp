// 847. Shortest Path Visiting All Nodes

// An undirected, connected graph of N nodes (labeled 0, 1, 2, ..., N-1) is given as graph.
// graph.length = N, and j != i is in the list graph[i] exactly once, if and only if nodes 
// i and j are connected.
// Return the length of the shortest path that visits every node. You may start and stop at
//  any node, you may revisit nodes multiple times, and you may reuse edges.

// Example 1:
// Input: [[1,2,3],[0],[0],[0]]
// Output: 4
// Explanation: One possible path is [1,0,2,0,3]

// Example 2:
// Input: [[1],[0,2,4],[1,3,4],[2],[1,2]]
// Output: 4
// Explanation: One possible path is [0,1,4,2,3]
 
// Note:
// 1 <= graph.length <= 12
// 0 <= graph[i].length < graph.length

#include<bits/stdc++.h>
using namespace std;

class elem{
    public:
    int currNode;
    int cost;
    int bitmask;
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();

        queue<elem> q;
        set<pair<int,int>> s;

        for(int i=0;i<n;i++){
            q.push({i,1,1<<i});
            s.insert({i,1<<i});
        }

        while(!q.empty()){
            elem front = q.front();
            q.pop();


            if(front.bitmask ==  ((1 << n)  - 1) ){
                return front.cost - 1;
            }
            
            for(auto v : graph[front.currNode]){
                int newbitmask = (front.bitmask | (1 << v));
                elem nn = {v,front.cost + 1,newbitmask};
                if(!s.count({v,newbitmask})){
                    q.push(nn);
                    s.insert({v,newbitmask});
                }
            }
        }
        return -1;
    }
};