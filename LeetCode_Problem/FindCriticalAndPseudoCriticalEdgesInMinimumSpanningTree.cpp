// 1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree

// Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges 
// where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. 
// A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles 
// and with the minimum possible total edge weight.

// Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST 
// edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On 
// the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

// Note that you can return the indices of the edges in any order.

// Example 1:
// Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
// Output: [[0,1],[2,3,4,5]]
// Explanation: The figure above describes the graph.
// The following figure shows all the possible MSTs:

// Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
// The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

// Example 2:
// Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
// Output: [[],[0,1,2,3]]
// Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.
 
// Constraints:
// 2 <= n <= 100
// 1 <= edges.length <= min(200, n * (n - 1) / 2)
// edges[i].length == 3
// 0 <= ai < bi < n
// 1 <= weighti <= 1000
// All pairs (ai, bi) are distinct.

#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a,vector<int>& b){
    if(a[2] < b[2]){
        return true;
    }
    return false;
}

class Solution {
    int * parent;
public:
    void set(int n){
        parent = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    void merge(int x,int y){
        int firstParent = findParent(x);
        int secondParent = findParent(y);
        if(firstParent != secondParent){
            parent[firstParent] = secondParent;
        }
        return ;
    }

    int kruskal(int n,vector<vector<int>> edges,int skip,int mustInclude){
        int edgesLength = edges.size();
        // sorting the edges according to weight
        int edgeadded = 0;
        int totalweight = 0;
        int i =  0;
        set(n);
        if(mustInclude != -1){
            int start = edges[mustInclude][0];
            int end = edges[mustInclude][1];
            int wei = edges[mustInclude][2];
            int firstParent = findParent(start);
            int secondParent = findParent(end);
            if(firstParent != secondParent){
                edgeadded++;
                totalweight += wei;
                merge(firstParent,secondParent);
            }
        }
        int skipstart;
        int skipend;
        int skipwei;
        if(skip != -1){
            skipstart = edges[skip][0];
            skipend = edges[skip][1];
            skipwei = edges[skip][2];
        }
        sort(edges.begin(),edges.end(),compare);
        
        while(edgeadded < n - 1 && i < edgesLength){
            if(skip != -1 && skipstart == edges[i][0] && skipend == edges[i][1] && skipwei == edges[i][2]){
                i++;
                continue;
            }
            int firstParent = findParent(edges[i][0]);
            int secondParent = findParent(edges[i][1]);
            if(firstParent != secondParent){
                edgeadded++;
                totalweight += edges[i][2];
                merge(firstParent,secondParent);
            }
            i++;
        }
        if(edgeadded < n - 1){
            return INT_MAX;
        }
        return totalweight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int weight = kruskal(n,edges,-1,-1);
        int edgeLength = edges.size();
        vector<int> critical;
        for(int i=0;i<edgeLength;i++){
            int newweight = kruskal(n,edges,i,-1);
            if(newweight == INT_MAX){
                critical.push_back(i);
                continue;
            }
            if(newweight > weight){
                critical.push_back(i);
            }          
        }

        unordered_map<int,bool> um;
        for(auto x: critical){
            um[x] = true;
        }
        vector<int> nonCritical;
        for(int i=0;i<edgeLength;i++){
            if(um.count(i) > 0){
                continue;
            }
            int newWeight = kruskal(n,edges,-1,i);
            if(newWeight == weight){
                nonCritical.push_back(i);
            }
        }

        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(nonCritical);
        return ans;
    }
};