#include<bits/stdc++.h>
using namespace std;

// 695. Max Area of Island
// You are given an m x n binary matrix grid. An island is
//  a group of 1's (representing land) connected 4-directionally
//  (horizontal or vertical.) You may assume all four edges of 
// the grid are surrounded by water.
// The area of an island is the number of cells with a value 1
//  in the island.
// Return the maximum area of an island in grid. If there is no
//  island, return 0.

// Example 1:
// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],
// [0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],
// [0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],
// [0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must
//  be connected 4-directionally.

// Example 2:
// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] is either 0 or 1.

class Solution {
    int rows;
    int cols;
public:
    int dfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j){
        if(i < 0 || i >= rows || j < 0 || j >= cols){
            return 0;
        }

        int ans = 1;
        visited[i][j] = 1;
        if(i + 1 < rows && visited[i + 1][j] == -1 && grid[i + 1][j] == 1){
            ans += dfs(grid,visited,i + 1,j);
        }

        if(i - 1 >= 0 && visited[i - 1][j] == -1 && grid[i - 1][j] == 1){
            ans += dfs(grid,visited,i - 1,j);
        }

        if(j + 1 < cols && visited[i][j + 1] == -1 && grid[i][j + 1] == 1){
            ans += dfs(grid,visited,i,j + 1);
        }

        if(j - 1 >= 0 && visited[i][j - 1] == -1 && grid[i][j - 1] == 1){
            ans += dfs(grid,visited,i,j - 1);
        }

        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<vector<int>> visited(rows,vector<int>(cols,-1));
        int answer = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1 && visited[i][j] == -1){
                    answer = max(answer,dfs(grid,visited,i,j));
                }
            }
        }
        return answer;
    }
};