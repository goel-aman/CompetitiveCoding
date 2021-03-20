// 1579. Remove Max Number of Edges to Keep Graph Fully Traversable
// // Hard

// Alice and Bob have an undirected graph of n nodes and 3 types of edges:

// Type 1: Can be traversed by Alice only.
// Type 2: Can be traversed by Bob only.
// Type 3: Can by traversed by both Alice and Bob.
// Given an array edges where edges[i] = [typei, ui, vi] represents a bidirectional edge of type typei between nodes ui and vi, find the maximum number of edges you can remove so that after removing the edges, the graph can still be fully traversed by both Alice and Bob. The graph is fully traversed by Alice and Bob if starting from any node, they can reach all other nodes.

// Return the maximum number of edges you can remove, or return -1 if it's impossible for the graph to be fully traversed by Alice and Bob.

 

// Example 1:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,3],[1,2,4],[1,1,2],[2,3,4]]
// Output: 2
// Explanation: If we remove the 2 edges [1,1,2] and [1,1,3]. The graph will still be fully traversable by Alice and Bob. Removing any additional edge will not make it so. So the maximum number of edges we can remove is 2.
// Example 2:



// Input: n = 4, edges = [[3,1,2],[3,2,3],[1,1,4],[2,1,4]]
// Output: 0
// Explanation: Notice that removing any edge will not make the graph fully traversable by Alice and Bob.
// Example 3:



// Input: n = 4, edges = [[3,2,3],[1,1,2],[2,3,4]]
// Output: -1
// Explanation: In the current graph, Alice cannot reach node 4 from the other nodes. Likewise, Bob cannot reach 1. Therefore it's impossible to make the graph fully traversable.
 

 

// Constraints:

// 1 <= n <= 10^5
// 1 <= edges.length <= min(10^5, 3 * n * (n-1) / 2)
// edges[i].length == 3
// 1 <= edges[i][0] <= 3
// 1 <= edges[i][1] < edges[i][2] <= n
// // All tuples (typei, ui, vi) are distinct.

#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a,vector<int> &b){
    if(a[0] > b[0]){
        return true;
    }

    return false;
}

class Solution {
    int* redParent;
    int* blueParent;

    // 1 means red && 0 means blue;
    int findParent(int x,int value){
        if(value == 1){
            if(x == redParent[x]){
                return x;
            }

            return redParent[x] = findParent(redParent[x],1);
        }

        if(x == blueParent[x]){
            return x;
        }

        return blueParent[x] = findParent(blueParent[x],0);
    }

    // 1 means red && 0 means blue
    void merge(int x,int y,int value){
        if(value == 1){
            int xPar = findParent(x,1);
            int yPar = findParent(y,1);
            if(xPar != yPar){
                redParent[xPar] = yPar;
            }
            return;
        }

        int xPar = findParent(x,0);
        int yPar = findParent(y,0);
        if(xPar != yPar){
            blueParent[xPar] = yPar;
        }
        return ;
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),compare);
        redParent = new int[n + 1];
        blueParent = new int[n + 1];
        for(int i=1;i<=n;i++){
            redParent[i] = i;
            blueParent[i] = i;
        }
        int ans = 0;
        // 1 alic3(red)   // 2 bob(0)   // 3 both
        for(auto edge : edges){
            if(edge[0] == 3){
                int x = findParent(edge[1],1);
                int y = findParent(edge[2],1);
                if(x != y){
                    merge(x,y,0);
                    merge(x,y,1);
                }else{
                    ans++;
                }
                continue;
            }

            if(edge[0] == 1){
                int x = findParent(edge[1],1);
                int y = findParent(edge[2],1);
                if(x != y){
                    merge(x,y,1);
                }else{
                    ans++;
                }
                continue;
            }

            if(edge[0] == 2){
                int x = findParent(edge[1],0);
                int y = findParent(edge[2],0);
                if(x != y){
                    merge(x,y,0);
                }
                else{
                    ans++;
                }
                continue;
            }
        }
        unordered_set<int> val1;
        for(int i=1;i<=n;i++){
            int w = findParent(i,1);
            val1.insert(w);
            if(val1.size() > 1){
                return -1;
            }
        }

        unordered_set<int> val2;
        for(int i=1;i<=n;i++){
            int w = findParent(i,0);
            val2.insert(w);
            if(val2.size() > 1)
            {
                return -1;
            }
        } 

        return ans;
    }
};