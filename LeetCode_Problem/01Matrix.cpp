// 542. 01 Matrix

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

// Example 1:
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

// Example 2:
// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]
 
// Constraints:
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// mat[i][j] is either 0 or 1.
// There is at least one 0 in mat.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> ans(rows,vector<int>(cols,-1));
        // unordered_map<pair<int,int>,bool> us;
        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }              
            }
        }
        int counter = 1;
        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                pair<int,int> front = q.front();
                q.pop();
                if(front.first >= 0 && front.first < rows && front.second + 1 >= 0 && front.second + 1 < cols && ans[front.first][front.second + 1] == -1){
                    ans[front.first][front.second + 1] = counter;
                    q.push({front.first,front.second + 1}); 
                }

                if(front.first >= 0 && front.first < rows && front.second - 1 >= 0 && front.second - 1 < cols && ans[front.first][front.second - 1] == -1){
                    ans[front.first][front.second - 1] = counter;
                    q.push({front.first,front.second - 1});
                }

                if(front.first + 1 >= 0 && front.first + 1 < rows && front.second >= 0 && front.second < cols && ans[front.first + 1][front.second] == -1){
                    ans[front.first + 1][front.second] = counter;
                    q.push({front.first + 1,front.second});
                }

                if(front.first - 1 >= 0 && front.first - 1 < rows && front.second >= 0 && front.second < cols && ans[front.first - 1][front.second] == -1){
                    ans[front.first - 1][front.second] = counter;
                    q.push({front.first - 1,front.second});
                }
            }
            counter++;
        }
        return ans;
    }
};