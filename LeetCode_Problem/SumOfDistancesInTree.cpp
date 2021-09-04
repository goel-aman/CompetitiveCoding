#include<bits/stdc++.h>
using namespace std;

// 834. Sum of Distances in Tree
// There is an undirected connected tree with
//  n nodes labeled from 0 to n - 1 and n - 1 edges.
// You are given the integer n and the array edges where
//  edges[i] = [ai, bi] indicates that there is an edge 
// between nodes ai and bi in the tree.

// Return an array answer of length n where answer[i] is
//  the sum of the distances between the ith node in the
//  tree and all other nodes.

// Example 1:
// Input: n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: The tree is shown above.
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + 
// dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.
// Hence, answer[0] = 8, and so on.

// Example 2:
// Input: n = 1, edges = []
// Output: [0]

// Example 3:
// Input: n = 2, edges = [[1,0]]
// Output: [1,1]
 
// Constraints:
// 1 <= n <= 3 * 104
// edges.length == n - 1
// edges[i].length == 2
// 0 <= ai, bi < n
// ai != bi
// The given input represents a valid tree.

class Solution {
    int number;
    vector<int> childCount;
    vector<int> ans;
    unordered_map<int,vector<int>> um;
public:
    void dfs(int parent,int src){
        for(auto &var : um[src]){
            if(var != parent){
                dfs(src,var);
                childCount[src] += childCount[var];
                ans[src] += ans[var] + childCount[var]; 
            }
        }
        return ;
    }

    void dfs2(int parent,int src){
        for(auto &var : um[src]){
            if(var != parent){
                ans[var] += (ans[src] + (number - childCount[var]) - ans[var] - childCount[var]);
                dfs2(src,var);
                
            }
        }
        return ;
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        childCount.resize(n,1);
        number = n;
        // ansNode.resize(n);
        ans.resize(n,0);
        int edgesLength = edges.size();
        // unordered_map<int,vector<int>> um;
        for(int i=0;i<edgesLength;i++){
            um[edges[i][0]].push_back(edges[i][1]);
            um[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(-1,0);
        dfs2(-1,0);
        return ans;
    }


};