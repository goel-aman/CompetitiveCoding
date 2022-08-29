#include<bits/stdc++.h>
using namespace std;

// 286. Walls and Gates
// You are given an m x n grid rooms initialized with
//  these three possible values.
// -1 A wall or an obstacle.
// 0 A gate.
// INF Infinity means an empty room. We use the
//  value 231 - 1 = 2147483647 to represent INF as you may 
// assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate.
//  If it is impossible to reach a gate, it should be filled
//  with INF.

// Example 1:
// Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,
// 2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],
// [0,-1,2147483647,2147483647]]
// Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

// Example 2:
// Input: rooms = [[-1]]
// Output: [[-1]]
 
// Constraints:
// m == rooms.length
// n == rooms[i].length
// 1 <= m, n <= 250
// rooms[i][j] is -1, 0, or 231 - 1.


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        int cols = rooms[0].size();

        vector<vector<int>> visited(rows,vector<int> (cols,-1));

        queue<pair<int,int>> que;
        int level = 1;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(rooms[i][j] == 0){
                    que.push({i,j});
                    visited[i][j] = 1;
                }
            }
        } 

        while(!que.empty()){
            int length = que.size();
            while(length--){
                pair<int,int> front = que.front();
                que.pop();
                
                //direction one
                int row1 = front.first,col1 = front.second + 1;
                if(row1 >= 0 && row1 < rows && col1 >= 0 && col1 < cols && rooms[row1][col1] != -1 && visited[row1][col1] == -1){
                    visited[row1][col1] = 1;
                    rooms[row1][col1] = level;
                    que.push({row1,col1});
                }

                int row2 = front.first, col2 = front.second - 1;
                if(row2 >= 0 && row2 < rows && col2 >= 0 && col2 < cols && rooms[row2][col2] != -1 && visited[row2][col2] == -1){
                    visited[row2][col2] = 1;
                    rooms[row2][col2] = level;
                    que.push({row2,col2});
                } 

                int row3 = front.first + 1, col3 = front.second;
                if(row3 >= 0 && row3 < rows && col3 >= 0 && col3 < cols && rooms[row3][col3] != -1 && visited[row3][col3] == -1){
                    visited[row3][col3] = 1;
                    rooms[row3][col3] = level;
                    que.push({row3,col3});
                }

                int row4 = front.first - 1, col4 = front.second;
                if(row4 >= 0 & row4 < rows && col4 >= 0 && col4 < cols && rooms[row4][col4] != -1 && visited[row4][col4] == -1){
                    visited[row4][col4] = 1;
                    rooms[row4][col4] = level;
                    que.push({row4,col4});
                } 
            }
            level++;
        }

        return ;
    }
};