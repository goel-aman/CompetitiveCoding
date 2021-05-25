#include<bits/stdc++.h>
using namespace std;

// 1466. Reorder Routes to Make All Paths Lead to the City Zero

// There are n cities numbered from 0 to n-1 and n-1 roads such that there
//  is only one way to travel between two different cities (this network form
//  a tree). Last year, The ministry of transport decided to orient the roads
//  in one direction because they are too narrow.

// Roads are represented by connections where connections[i] = [a, b] represents
//  a road from city a to b.

// This year, there will be a big event in the capital (city 0), and many
//  people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit 
// the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach the city 0 after reorder.

// Example 1:
// Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
// Output: 3
// Explanation: Change the direction of edges show in red such that 
// each node can reach the node 0 (capital).

// Example 2:
// Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
// Output: 2
// Explanation: Change the direction of edges show in red such that each
//  node can reach the node 0 (capital).

// Example 3:
// Input: n = 3, connections = [[1,0],[2,0]]
// Output: 0
 
// Constraints:
// 2 <= n <= 5 * 10^4
// connections.length == n-1
// connections[i].length == 2
// 0 <= connections[i][0], connections[i][1] <= n-1
// connections[i][0] != connections[i][1]

class Solution {
    unordered_map<int,vector<int>> incoming;
    unordered_map<int,vector<int>> outgoing;
    unordered_map<int,bool> visited;
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto element : connections){
            incoming[element[1]].push_back(element[0]);
            outgoing[element[0]].push_back(element[1]);
        }
        int ans = 0;
        queue<int> que;
        que.push(0);
        visited[0] = true;

        while(!que.empty()){
            int front = que.front();
            que.pop();

            for(auto value : outgoing[front]){
                if(!visited.count(value)){
                    visited[value] = true;
                    ans++;
                    que.push(value);
                }
            }

            for(auto value : incoming[front]){
                if(!visited.count(value)){
                    visited[value] = true;
                    que.push(value);
                }
            }
        }
        return ans;
    }
};