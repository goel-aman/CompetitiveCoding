#include<bits/stdc++.h>
using namespace std;

// 1139. Largest 1-Bordered Square
// Given a 2D grid of 0s and 1s, return the number of elements
//  in the largest square subgrid that has all 1s on its border,
//  or 0 if such a subgrid doesn't exist in the grid.

// Example 1:
// Input: grid = [[1,1,1],[1,0,1],[1,1,1]]
// Output: 9

// Example 2:
// Input: grid = [[1,1,0,0]]
// Output: 1
 
// Constraints:
// 1 <= grid.length <= 100
// 1 <= grid[0].length <= 100
// grid[i][j] is 0 or 1

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        // first is vertical , second is horizontal
        vector<vector<pair<int,int>>> vec(rows,vector<pair<int,int>>(cols));
        if(grid[0][0] == 0){
            vec[0][0].first = 0;
            vec[0][0].second = 0;
        }

        if(grid[0][0] == 1){
            vec[0][0].first = 1;
            vec[0][0].second = 1;
            ans = max(ans,1);
        }

        for(int i=1;i<cols;i++){
            if(grid[0][i] == 0){
                vec[0][i].first = 0;
                vec[0][i].second = 0;
            }else{
                vec[0][i].second = vec[0][i - 1].second + 1;
                vec[0][i].first = 1;
                ans = max(ans,1);
            }
        }

        for(int i=1;i<rows;i++){
            if(grid[i][0] == 0){
                vec[i][0].first = 0;
                vec[i][0].second = 0;
            }else{
                vec[i][0].first = vec[i - 1][0].first + 1;
                vec[i][0].second = 1;
                ans = max(ans,1);
            }
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(grid[i][j] == 0){
                    vec[i][j].first = 0;
                    vec[i][j].second = 0;
                }else{
                    vec[i][j].first = vec[i - 1][j].first + 1;
                    vec[i][j].second = vec[i][j - 1].second + 1;
                    ans = max(ans,1);
                }
            }
            cout<<endl;
        }   
        
        for(int i=rows - 1;i>=1;i--){
            for(int j=cols - 1;j>=1;j--){
                if(grid[i][j]==1){
                    int minLength = min(vec[i][j].first,vec[i][j].second);
                    for(int k=minLength;k>=1;k--){
                        int targetRow = i - (k  - 1);
                        int targetCol = j;
                        int targetRow2 = i;
                        int targetCol2 = j - (k - 1);
                        if(targetRow >= 0 && targetCol2 >= 0 && vec[targetRow][targetCol].second >= k && vec[targetRow2][targetCol2].first >= k){
                            ans = max(ans,k);
                        }
                    }
                }
            }
        }
        return ans* ans;
    }
};