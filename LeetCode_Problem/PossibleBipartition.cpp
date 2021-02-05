// 886. Possible Bipartition

// Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.

// Each person may dislike some other people, and they should not go into the same group. 

// Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.

// Return true if and only if it is possible to split everyone into two groups in this way.

 

// Example 1:

// Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4], group2 [2,3]
// Example 2:

// Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:

// Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false
 

// Constraints:

// 1 <= N <= 2000
// 0 <= dislikes.length <= 10000
// dislikes[i].length == 2
// 1 <= dislikes[i][j] <= N
// dislikes[i][0] < dislikes[i][1]
// There does not exist i != j for which dislikes[i] == dislikes[j].

#include<bits/stdc++.h>
using namespace std;

class elem{
    public:
    int node;
    int level;
};

class Solution {
    unordered_map<int,vector<int>> um;
public:

    bool isBipartite(int source,vector<int> &visited){
        queue<elem> q;
        q.push({source,0});
        while(!q.empty()){
            elem a = q.front();
            q.pop();

            if(visited[a.node] != -1){
                if(a.level != visited[a.node]){
                    return false;
                }
            }else{
                visited[a.node] = a.level;
            }

            for(auto x : um[a.node]){
                if(visited[x] == -1){
                    q.push({x,a.level + 1});
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(auto x : dislikes){
            um[x[0]].push_back(x[1]);
            um[x[1]].push_back(x[0]);
        }
        vector<int> visited(N + 1,-1);
        for(int i=1;i<=N;i++){
            if(visited[i] == -1){
                bool ans = isBipartite(i,visited);
                // cout<<"value of i is : "<<i<<" and ans is : "<<ans<<endl;
                if(!ans){
                    return false;
                }
            }
        }
        return true;
    }
};