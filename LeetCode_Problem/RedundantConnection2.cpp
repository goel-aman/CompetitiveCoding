// 685. Redundant Connection II

// In this problem, a rooted tree is a directed graph such that, there is exactly 
// one node (the root) for which all other nodes are descendants of this node, 
// plus every node has exactly one parent, except for the root node which has
//  no parents.

// The given input is a directed graph that started as a rooted tree with n nodes 
// (with distinct values from 1 to n), with one additional directed edge added. 
// The added edge has two different vertices chosen from 1 to n, and was not an 
// edge that already existed.

// The resulting graph is given as a 2D-array of edges. Each element of edges 
// is a pair [ui, vi] that represents a directed edge connecting nodes ui and 
// vi, where ui is a parent of child vi.

// Return an edge that can be removed so that the resulting graph is a rooted 
// tree of n nodes. If there are multiple answers, return the answer that occurs
//  last in the given 2D-array.

 

// Example 1:
// Input: edges = [[1,2],[1,3],[2,3]]
// Output: [2,3]

// Example 2:
// Input: edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
// Output: [4,1]
 
// Constraints:
// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ui, vi <= n

#include<bits/stdc++.h>
using namespace std;


class Solution {
    int * parent;
    int siz;
public:
    int findParent(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void merge(int x,int y){
        int xParent = findParent(x);
        int yParent = findParent(y);

        if(xParent != yParent){
            parent[xParent] = yParent;
        }
        return ;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        siz = edges.size();
        parent = new int[siz + 1];
        for(int i=1;i<=siz;i++){
            parent[i] = 0;
        }
        vector<int> first,second;
        for(auto &edge : edges){
            if(parent[edge[1]] == 0){
                parent[edge[1]] = edge[0];
            }

            else{
                first = {parent[edge[1]],edge[1]};
                second = edge;
                edge[1] = 0;
            }
        }

        for(int i=1;i<=siz;i++){
            parent[i] = i;
        }

        for(auto edge :edges){
            if(edge[1] == 0){
                continue;
            }
            
            int xPar = findParent(edge[0]);
            int yPar = findParent(edge[1]);

            if(xPar != yPar){
                merge(edge[0],edge[1]);
            }
            else{
                if(first.empty()){
                    return edge;
                }
                return first;
            }
        }
        return second;
    }
};