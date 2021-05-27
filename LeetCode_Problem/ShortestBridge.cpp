#include<bits/stdc++.h>
using namespace std;

// 934. Shortest Bridge
// In a given 2D binary array grid, there are two islands.  
// (An island is a 4-directionally connected group of 1s not 
// connected to any other 1s.)

// Now, we may change 0s to 1s so as to connect the two islands 
// together to form 1 island.
// Return the smallest number of 0s that must be flipped.  
// (It is guaranteed that the answer is at least 1.)

// Example 1:
// Input: grid = [[0,1],[1,0]]
// Output: 1

// Example 2:
// Input: grid = [[0,1,0],[0,0,0],[0,0,1]]
// Output: 2

// Example 3:
// Input: grid = [[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]
// Output: 1
 
// Constraints:
// 2 <= grid.length == grid[0].length <= 100
// grid[i][j] == 0 or grid[i][j] == 1

class Solution {
    int rows;
    int cols;

public:
    void dfs(vector<vector<int>>& grid,int i,int j,queue<pair<int,int>> &que){
        if(i >= rows || i < 0 || j >= cols || j < 0 || grid[i][j] == 0 || grid[i][j] == 2){
            return ;
        }

        if(grid[i][j] == 1){
            que.push({i,j});
            grid[i][j] = 2;
        }

        dfs(grid,i + 1,j,que);
        dfs(grid,i - 1,j,que);
        dfs(grid,i,j + 1,que);
        dfs(grid,i,j - 1,que);
        return ;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        rows = grid.size();
        cols = grid[0].size();
        int gotAnswer = 0;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    dfs(grid,i,j,que);
                    gotAnswer = 1;
                    break;
                }
            }
            if(gotAnswer == 1){
                break;
            }
        }

        int answer = 0;
        while(!que.empty()){
            int siz = que.size();
            while(siz--){
                pair<int,int> front = que.front();
                que.pop();
                int x = front.first;
                int y = front.second;

                if(x + 1 < rows && x + 1 >= 0 && grid[x+ 1][y] == 0){
                    grid[x + 1][y] = 2;
                    que.push({x + 1,y});
                }
                
                if(x - 1 < rows && x - 1 >= 0 && grid[x - 1][y] == 0){
                    grid[x - 1][y] = 2;
                    que.push({x - 1,y});
                }

                if(y + 1 < cols && y + 1 >= 0 && grid[x][y + 1] == 0){
                    grid[x][y + 1] = 2;
                    que.push({x,y + 1});
                }
                
                if(y - 1 < cols && y - 1 >= 0 && grid[x][y - 1] == 0){
                    grid[x][y - 1] = 2;
                    que.push({x,y - 1});
                }

                if( (x + 1 <  rows && x + 1 >= 0 && grid[x + 1][y] == 1) || (x - 1 < rows && x - 1 >= 0 && grid[x - 1][y] == 1) 
                    || (y - 1 < cols && y - 1 >= 0 && grid[x][y - 1] == 1) || (y + 1 < cols && y + 1 >= 0 && grid[x][y + 1] == 1) ){
                    
                    return answer;     
                }
            }
            answer++;
        }
        return answer;
    }
}; 
