#include<bits/stdc++.h>
using namespace std;

// 1020. Number of Enclaves

// You are given an m x n binary matrix grid, where 0 represents
//  a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent
//  (4-directionally) land cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off 
// the boundary of the grid in any number of moves.

// Example 1:
// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

// Example 2:
// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] is either 0 or 1.

class Solution {
    vector<vector<int>> visited;
    int rows,cols;
    vector<vector<int>> gridd;
public:
    void dfs(int i,int j){
        visited[i][j] = 1;

        if( i + 1 < rows && i + 1 >= 0 && j >= 0 && j < cols && gridd[i + 1][j] == 1 && visited[i + 1][j] == -1){
            dfs(i + 1, j);
        }

        if(i - 1 < rows && i - 1 >= 0 && j >= 0 && j < cols && visited[i -1 ][j] == -1 && gridd[i - 1][j] == 1){
            dfs(i - 1,j);
        }

        if(i >= 0 && i < rows && j + 1 >= 0 && j + 1 < cols && visited[i][j + 1] == -1 && gridd[i][j + 1] == 1){
            dfs(i,j + 1);
        }

        if(i >= 0 && i < rows && j - 1 >= 0 && j - 1 < cols && visited[i][j - 1] == -1 && gridd[i][j - 1] == 1){
            dfs(i,j - 1);
        }

        return ;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        visited.resize(rows,vector<int> (cols,-1));
        gridd = grid;
        for(int i=0;i<rows;i++){
            if(grid[i][0] == 1 && visited[i][0] == -1){
                dfs(i,0);
            }
        }

        for(int i = 0;i<rows;i++){
            if(grid[i][cols - 1] == 1 && visited[i][cols - 1] == -1){
                dfs(i,cols - 1);
            }
        }

        for(int i=0;i<cols;i++){
            if(grid[0][i] == 1 && visited[0][i] == -1){
                dfs(0,i);
            }
        }

        for(int i=0;i<cols;i++){
            if(grid[rows - 1][i] == 1 && visited[rows - 1][i] == -1){
                dfs(rows - 1,i);
            }
        }

        int count = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1 && visited[i][j] == -1){
                    count++;
                }
            }
        }
        return count;
    }
};