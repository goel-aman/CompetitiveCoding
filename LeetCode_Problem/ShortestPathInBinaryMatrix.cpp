#include<bits/stdc++.h>
using namespace std;

// 1091. Shortest Path in Binary Matrix

// Given an n x n binary matrix grid, return the length of the
//  shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell 
// (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected 
// (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

// Example 1:
// Input: grid = [[0,1],[1,0]]
// Output: 2

// Example 2:
// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4

// Example 3:
// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1
 
// Constraints:
// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

class Solution {
    int rows,cols;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int answer = 1;
        vector<vector<int>> visited(rows,vector<int> (cols, 0));
        queue<pair<int,int>> que;
        if(grid[0][0] != 0){
            return -1;
        }
        visited[0][0] = true;
        que.push({0,0});
        while(!que.empty()){
            int siz = que.size();
            while(siz--){
                pair<int,int> front = que.front();
                que.pop();
                int x = front.first;
                int y = front.second;

                if(x == rows - 1 && y == cols - 1){
                    return answer;
                }

                for(int i=-1;i<=1;i++){
                    for(int j=-1;j<=1;j++){
                        if(i == 0 && j == 0){
                            continue;
                        }

                        if(x + i < rows && x + i >= 0 && y + j >= 0 && y + j < cols && grid[x + i][y + j] == 0 && visited[x + i][y + j] == 0){
                            visited[x + i][y + j] = true;
                            que.push({x + i,y + j});
                        }
                    }
                }
            }
            answer++;
        }
        return -1;
    }
};



