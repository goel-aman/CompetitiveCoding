#include<bits/stdc++.h>
using namespace std;

// 994. Rotting Oranges

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent
//  to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no 
// cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) 
// is never rotten, because rotting only happens 4-directionally.

// Example 3:
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0,
//  the answer is just 0.
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 10
// grid[i][j] is 0, 1, or 2.

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> visited(rows,vector<int> (cols,0));
        queue<pair<int,int>> que;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 1;
                    que.push({i,j});
                }
            }
        }
        
        int minutes = 0;
        while(!que.empty()){
            int siz = que.size();
            while(siz--){
                pair<int,int> front = que.front();
                que.pop();

                if(front.first + 1 >= 0 && front.first + 1  < rows && visited[front.first + 1][front.second] == 0 && grid[front.first + 1][front.second] == 1){
                    que.push({front.first + 1, front.second});
                    visited[front.first + 1][front.second] = 1;
                }

                if(front.first - 1 >= 0 && front.first - 1 < rows && visited[front.first - 1][front.second] == 0 && grid[front.first - 1][front.second] == 1){
                    que.push({front.first - 1,front.second});
                    visited[front.first - 1][front.second] = 1;
                }

                if(front.second + 1 >= 0 && front.second + 1 < cols && visited[front.first][front.second + 1] == 0 && grid[front.first][front.second + 1] == 1){
                    que.push({front.first,front.second + 1});
                    visited[front.first][front.second + 1] = 1;
                }

                if(front.second - 1 >= 0 && front.second - 1 < cols && visited[front.first][front.second - 1] == 0 && grid[front.first][front.second - 1] == 1){
                    que.push({front.first,front.second - 1});
                    visited[front.first][front.second - 1] = 1;
                }
            }
            minutes++;
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(visited[i][j] == 0 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if(minutes == 0){
            return 0;
        }
        return minutes - 1;
    }
};