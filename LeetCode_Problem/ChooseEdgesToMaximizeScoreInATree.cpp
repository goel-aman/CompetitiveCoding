#include<bits/stdc++.h>
using namespace std;

// 2378. Choose Edges to Maximize Score in a Tree
// You are given a weighted tree consisting of n nodes numbered from 0 to n - 1.
// The tree is rooted at node 0 and represented with a 2D array edges of size n
//  where edges[i] = [pari, weighti] indicates that node pari is the parent of 
// node i, and the edge between them has a weight equal to weighti. Since the root
//  does not have a parent, you have edges[0] = [-1, -1].

// Choose some edges from the tree such that no two chosen edges are adjacent and 
// the sum of the weights of the chosen edges is maximized.

// Return the maximum sum of the chosen edges.

// Note:
// You are allowed to not choose any edges in the tree, the sum of weights in this
//  case will be 0.
// Two edges Edge1 and Edge2 in the tree are adjacent if they have a common node.
// In other words, they are adjacent if Edge1 connects nodes a and b and Edge2 connects
//  nodes b and c.
 
// Example 1:
// Input: edges = [[-1,-1],[0,5],[0,10],[2,6],[2,4]]
// Output: 11
// Explanation: The above diagram shows the edges that we have to choose colored in red.
// The total score is 5 + 6 = 11.
// It can be shown that no better score can be obtained.

// Example 2:
// Input: edges = [[-1,-1],[0,5],[0,-6],[0,7]]
// Output: 7
// Explanation: We choose the edge with weight 7.
// Note that we cannot choose more than one edge because all edges are adjacent to each other.

// Constraints:
// n == edges.length
// 1 <= n <= 105
// edges[i].length == 2
// par0 == weight0 == -1
// 0 <= pari <= n - 1 for all i >= 1.
// pari != i
// -106 <= weighti <= 106 for all i >= 1.
// edges represents a valid tree.
//j = 0 means we are going to consider edge from current node
//  and j = 1 means we are not going to consider.

// mode = 0 means we are going to consider edge from the current node
// m = 1 means we are not going to consider edge from the current node

class Solution {
    long long int dp[100001][2];
    public:
    long long solve(int mode,int node,unordered_map<int,vector<pair<int,int>>> &store){
        long long sum = 0;

        if(dp[node][mode] != -1){
            return dp[node][mode];
        }
        
        for(auto var: store[node]){
            sum += solve(0,var.first,store);
        }

        if(mode == 0){
            long long int tempValue = 0;
            for(auto var : store[node]){
                tempValue = max(tempValue,sum - solve(0,var.first,store)  + solve(1,var.first,store) + var.second);
            }
            tempValue = max(tempValue,sum);
            return dp[node][mode] = tempValue;
        }
        sum = max(sum,(long long )0);
        return dp[node][mode] = sum;
    }

    long long maxScore(vector<vector<int>>& edges) {
        int edgesLength = edges.size();
        unordered_map<int,vector<pair<int,int>>> store;
        int rootNode;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<edgesLength;i++){
            if(edges[i][0] < 0){
                rootNode = i;
            }else{
                store[edges[i][0]].push_back({i,edges[i][1]});    
            }
        }
        long long int ans = solve(0,rootNode,store);
        return ans;
    }
};