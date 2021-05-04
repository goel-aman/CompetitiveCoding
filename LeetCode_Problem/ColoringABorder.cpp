#include<bits/stdc++.h>
using namespace std;

// 1034. Coloring A Border

// Given a 2-dimensional grid of integers, each value in the grid represents
//  the color of the grid square at that location.

// Two squares belong to the same connected component if and only if they have
//  the same color and are next to each other in any of the 4 directions.

// The border of a connected component is all the squares in the connected 
// component that are either 4-directionally adjacent to a square not in the 
// component, or on the boundary of the grid (the first or last row or column).

// Given a square at location (r0, c0) in the grid and a color, color the border
//  of the connected component of that square with the given color, and return the final grid.

// Example 1:
// Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
// Output: [[3, 3], [3, 2]]

// Example 2:
// Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
// Output: [[1, 3, 3], [2, 3, 3]]

// Example 3:
// Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
// Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
 
// Note:
// 1 <= grid.length <= 50
// 1 <= grid[0].length <= 50
// 1 <= grid[i][j] <= 1000
// 0 <= r0 < grid.length
// 0 <= c0 < grid[0].length
// 1 <= color <= 1000



class Solution {
public:
    // m means rows , n means cols
    bool inside(int m,int n,int r,int c){
        if(r >= m || r < 0 || c >= n || c < 0 ){
            return false;
        }

        return true;
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int rows = grid.size();
        int original = grid[r0][c0];
        int cols = grid[0].size();
        vector<int> visited(2505, -1);
        queue<pair<int,int>> que;
        int x[] = {1,-1,0,0};
        int y[] = {0,0,-1,1};
        que.push({r0,c0});
        visited[r0 * cols + c0] = 1;
        while(!que.empty()){
            pair<int,int> front = que.front();
            que.pop();
            if(inside(rows,cols,front.first,front.second) && front.first == rows - 1 || front.first == 0 || front.second == 0 || front.second == cols - 1){
                grid[front.first][front.second] = color;
            }          
            
            for(int i=0;i<4;i++){
                if(inside(rows,cols,front.first + x[i],front.second + y[i]) && visited[((front.first + x[i]) * cols )+ front.second + y[i]] == -1){
                    if(grid[front.first + x[i]][front.second + y[i]] == original){
                        visited[(front.first + x[i]) * cols + front.second] = 1;
                        que.push({front.first + x[i],front.second + y[i]});
                    }else{
                        grid[front.first][front.second] = color;
                    }
                }           
            }
        }
        return grid;
    }
};