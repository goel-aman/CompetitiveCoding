// 310. Minimum Height Trees

// A tree is an undirected graph in which any two vertices are connected by exactly one path.
//  In other words, any connected graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where 
// edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes 
// ai and bi in the tree, you can choose any node of the tree as the root. When you select
//  a node x as the root, the result tree has height h. Among all possible rooted trees, 
// those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return the answer in any order.

// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

// Example 1:
// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]
// Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.

// Example 2:
// Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// Output: [3,4]

// Example 3:
// Input: n = 1, edges = []
// Output: [0]

// Example 4:
// Input: n = 2, edges = [[0,1]]
// Output: [0,1]
 

// Constraints:

// 1 <= n <= 2 * 104
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no repeated edges.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<int>> um;
    unordered_map<int,int> degree;
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1){
            vector<int> ans;
            ans.push_back(0);
            return ans;
        }

        for(auto edge : edges){
            um[edge[0]].push_back(edge[1]);
            um[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int> q;
        for(auto var : degree){
            if(var.second == 1){
                q.push(var.first);
            }
        }
        

        while(n > 2){
            int length = q.size();
            n -= length;

            while(length--){
                int elem = q.front();
                q.pop();
                for(auto var : um[elem]){
                    degree[var]--;
                    if(degree[var] == 1){
                        q.push(var);
                    }
                }
            }

        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};