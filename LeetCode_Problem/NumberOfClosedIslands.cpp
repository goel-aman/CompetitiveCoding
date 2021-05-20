#include<bits/stdc++.h>
using namespace std;

// 1254. Number of Closed Islands
// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a
//  maximal 4-directionally connected group of 0s and a closed island is 
// an island totally (all left, top, right, bottom) surrounded by 1s.

// Return the number of closed islands.

// Example 1:
// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).

// Example 2:
// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1

// Example 3:
// Input: grid = [[1,1,1,1,1,1,1],
//                [1,0,0,0,0,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,1,0,1,0,1],
//                [1,0,1,1,1,0,1],
//                [1,0,0,0,0,0,1],
//                [1,1,1,1,1,1,1]]
// Output: 2
 
// Constraints:
// 1 <= grid.length, grid[0].length <= 100
// 0 <= grid[i][j] <=1


class Solution {
    vector<vector<int>> visited;
    int gridrows;
    vector<vector<int>> gridd;
    int gridcols;
public:
    void traverse(int i,int j){
        visited[i][j] = true;
        if(i + 1 < gridrows && i + 1 >= 0 && gridd[i + 1][j] == 0 && !visited[i + 1][j]){
            traverse(i + 1, j);
        }

        if(i - 1 >= 0 && i - 1 < gridrows && gridd[i - 1][j] == 0 && !visited[i - 1][j]){
            traverse(i - 1,j);
        }

        if(j + 1 < gridcols && j + 1 >= 0 && gridd[i][j + 1] == 0 && !visited[i][j + 1]){
            traverse(i,j+ 1);
        }
        

        if(j - 1 < gridcols && j - 1 >= 0 && gridd[i][j - 1] == 0 && !visited[i][j - 1]){
            traverse(i,j - 1);
        }
        return ;
    }

    int closedIsland(vector<vector<int>>& grid) {
        gridrows = grid.size();
        gridcols = grid[0].size();
        visited.resize(gridrows,vector<int>(gridcols,0));
        int total = 0;
        gridd = grid;
        int corner = 0;
        for(int i=0;i<gridrows;i++){
            if(!visited[i][0] && grid[i][0] == 0){
                traverse(i,0);
                corner++;
            }
        }

        for(int i=0;i<gridrows;i++){
            if(!visited[i][gridcols - 1] && grid[i][gridcols - 1] == 0){
                traverse(i,gridcols - 1);
                corner++;
            }
        }

        for(int i=0;i<gridcols;i++){
            if(!visited[0][i] && grid[0][i] == 0){
                traverse(0,i);
                corner++;
            }
        }

        for(int i=0;i<gridcols;i++){
            if(!visited[gridrows - 1][i] && grid[gridrows - 1][i] == 0){
                traverse(gridrows - 1,i);
                corner++;
            }
        }

        for(int i=0;i<gridrows;i++){
            for(int j=0;j<gridcols;j++){
                if(!visited[i][j] && grid[i][j] == 0){                  
                    total++;
                    traverse(i,j);
                }
            }
        }
        return total;
    }
};