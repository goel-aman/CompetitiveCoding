#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        int matrix[rows][cols];
        for(int i=rows - 1;i>=0;i--){
            for(int j=cols - 1;j>=0;j--){
                if(i == rows - 1 && j == cols - 1){
                    if(dungeon[i][j] >= 0){
                        matrix[i][j] = 0;
                    }
                    else{
                        matrix[i][j] = dungeon[i][j];
                    }
                }
                else if(i == rows - 1){
                    if(matrix[i][j + 1] + dungeon[i][j] >= 0){
                        matrix[i][j] = 0;
                    }else{
                        matrix[i][j] = matrix[i][j + 1] + dungeon[i][j];
                    }
                }
                else if(j == cols - 1){
                    if(matrix[i + 1][j] + dungeon[i][j] >= 0){
                        matrix[i][j] = 0;
                    }
                    else{
                        matrix[i][j] = matrix[i + 1][j] + dungeon[i][j];
                    }
                }
                else{
                    int ans = max(matrix[i + 1][j],matrix[i][j+1]) + dungeon[i][j];
                    if(ans >= 0 ){
                        matrix[i][j] = 0;
                    }
                    else{
                        matrix[i][j] = ans;
                    }
                }
            }
        }
        return abs(matrix[0][0]) + 1;
    }
};