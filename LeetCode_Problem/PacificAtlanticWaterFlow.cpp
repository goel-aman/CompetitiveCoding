#include<bits/stdc++.h>
using namespace std;

// You are given an m x n integer matrix heights representing the
//  height of each unit cell in a continent. The Pacific ocean touches the 
// continent's left and top edges, and the Atlantic ocean touches the continent's 
// right and bottom edges.

// Water can only flow in four directions: up, down, left, and right. Water flows 
// from a cell to an adjacent one with an equal or lower height.

// Return a list of grid coordinates where water can flow to both the Pacific
//  and Atlantic oceans.

// Example 1:
// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

// Example 2:
// Input: heights = [[2,1],[1,2]]
// Output: [[0,0],[0,1],[1,0],[1,1]]

// Constraints:
// m == heights.length
// n == heights[i].length
// 1 <= m, n <= 200
// 1 <= heights[i][j] <= 105

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> Visited(rows,vector<int>(cols,0));
        vector<vector<int>> ans(rows,vector<int>(cols,0));
        queue<pair<int,int>> que;
        for(int i=0;i<rows;i++){
            Visited[i][cols - 1] = true;
            ans[i][cols - 1] += 1;
            que.push({i,cols - 1});
        }

        for(int i=0;i<cols;i++){
            Visited[rows - 1][i] = true;
            ans[rows - 1][i] += 1;
            que.push({rows - 1,i});
        }
        ans[rows - 1][cols - 1] -= 1;
       
        while(!que.empty()){
            pair<int,int> front = que.front();
            que.pop();

            int tempi = front.first;
            int tempj = front.second;

            if(tempi + 1 < rows && tempi + 1 >= 0 && Visited[tempi + 1][tempj] == 0 && heights[tempi + 1][tempj] >= heights[tempi][tempj]){
                Visited[tempi + 1][tempj] = 1;
                que.push({tempi + 1,tempj});
                ans[tempi + 1][tempj] += 1;
            }

            if(tempi - 1 < rows && tempi - 1 >= 0 && Visited[tempi - 1][tempj] == 0 && heights[tempi - 1][tempj] >= heights[tempi][tempj] ){
                Visited[tempi - 1][tempj] = 1;
                que.push({tempi - 1,tempj});
                ans[tempi - 1][tempj] += 1;
            }

            if(tempj + 1 < cols && tempj + 1 >= 0 && Visited[tempi][tempj + 1] == 0 && heights[tempi][tempj + 1] >= heights[tempi][tempj]){
                Visited[tempi][tempj + 1] = 1;
                que.push({tempi,tempj + 1});
                ans[tempi][tempj + 1] += 1;
            }

            if(tempj - 1 < cols && tempj - 1 >= 0 && Visited[tempi][tempj - 1] == 0 && heights[tempi][tempj - 1] >= heights[tempi][tempj]){
                Visited[tempi][tempj - 1] = 1;
                que.push({tempi,tempj - 1});
                ans[tempi][tempj - 1] += 1;
            }
        }
       
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
            Visited[i][j] = 0;
            }
        }
        for(int i=0;i<rows;i++){
            que.push({i,0});
            Visited[i][0] = 1;
            ans[i][0] += 1;
        }

        for(int i=0;i<cols;i++){
            que.push({0,i});
            Visited[0][i] = 1;
            ans[0][i] += 1;
        }
        
        ans[0][0] -= 1;
       
        
        while(!que.empty()){
            pair<int,int> front = que.front();
            que.pop();

            int tempi = front.first;
            int tempj = front.second;

            if(tempi + 1 < rows && tempi + 1 >= 0 && Visited[tempi + 1][tempj] == 0 && heights[tempi + 1][tempj] >= heights[tempi][tempj]){
                Visited[tempi + 1][tempj] = 1;
                que.push({tempi + 1,tempj});
                ans[tempi + 1][tempj] += 1;
            }

            if(tempi - 1 < rows && tempi - 1 >= 0 && Visited[tempi - 1][tempj] == 0 && heights[tempi - 1][tempj] >= heights[tempi][tempj] ){
                Visited[tempi - 1][tempj] = 1;
                que.push({tempi - 1,tempj});
                ans[tempi - 1][tempj] += 1;
            }

            if(tempj + 1 < cols && tempj + 1 >= 0 && Visited[tempi][tempj + 1] == 0 && heights[tempi][tempj + 1] >= heights[tempi][tempj]){
                Visited[tempi][tempj + 1] = 1;
                que.push({tempi,tempj + 1});
                ans[tempi][tempj + 1] += 1;
            }

            if(tempj - 1 < cols && tempj - 1 >= 0 && Visited[tempi][tempj - 1] == 0 && heights[tempi][tempj - 1] >= heights[tempi][tempj]){
                Visited[tempi][tempj - 1] = 1;
                que.push({tempi,tempj - 1});
                ans[tempi][tempj - 1] += 1;
            }
        }

        vector<vector<int>> anss;
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(ans[i][j] == 2){
                    anss.push_back({i,j});
                }
            }
        }
        return anss;
    }
};