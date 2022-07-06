#include<bits/stdc++.h>
using namespace std;

// 1273. Delete Tree Nodes
// A tree rooted at node 0 is given as follows:
// The number of nodes is nodes;
// The value of the ith node is value[i];
// The parent of the ith node is parent[i].
// Remove every subtree whose sum of values of nodes is zero.
// Return the number of the remaining nodes in the tree.

// Example 1:
// Input: nodes = 7, parent = [-1,0,0,1,2,2,2],
// value = [1,-2,4,0,-2,-1,-1]
// Output: 2

// Example 2:
// Input: nodes = 7, parent = [-1,0,0,1,2,2,2], 
// value = [1,-2,4,0,-2,-1,-2]
// Output: 6
 
// Constraints:
// 1 <= nodes <= 104
// parent.length == nodes
// 0 <= parent[i] <= nodes - 1
// parent[0] == -1 which indicates that 0 is the root.
// value.length == nodes
// -105 <= value[i] <= 105
// The given input is guaranteed to represent a valid tree.

class Solution {
    unordered_map<int,vector<int>> graph;
    int ans = 0;
public:
    void EraseChilds(int node){
        for(auto var : graph[node]){
            EraseChilds(var);
        }
        
        graph.erase(node);
        return ;
    }
    
    int solve(int node,vector<int>& value){
        int sum = 0;
        for(auto var : graph[node]){
            sum += solve(var,value);    
        }
        
        sum += value[node];
        if(sum == 0){
            EraseChilds(node);
        }
        
        return sum;
    }
    
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        int parentLength = parent.size();
        for(int i=0;i<parentLength;i++){
            int parentNode = parent[i];
            int childNode = i;
            graph[parentNode].push_back(childNode);
        }
        
        solve(0,value);
        int count = 0;
        for(int i=0;i<nodes;i++){
            if(graph.count(i)){
                count++;
            }
        }
        return count;
    }
};