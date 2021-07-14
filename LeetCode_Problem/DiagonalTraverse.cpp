#include<bits/stdc++.h>
using namespace std;

// 498. Diagonal TraverseGiven an m x n matrix mat, return an array
//  of all the elements of the array in a diagonal order.

// Example 1:
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]

// Example 2:
// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]
 
// Constraints:
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105



class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int i = 0 ,j = 0;
        vector<int> ans;
        int turn = 0;
        while(!(i == rows - 1 && j == cols - 1)){
            ans.push_back(mat[i][j]);
            if(turn%2 == 0){
                if(i - 1 < 0 && j + 1 < cols){
                    i = i;
                    j = j + 1;
                    turn++;
                    continue;
                }
                
                if(i - 1 < 0 || j + 1 == cols){
                    i = i + 1;
                    j = j;
                    turn++;
                    continue;
                }

                i = i - 1;
                j = j + 1;
                continue;
            }
            
            if(turn%2 != 0){
                if(j - 1 < 0 && i + 1 < rows){
                    i = i + 1;
                    j = j;
                    turn++;
                    continue;
                }
                
                if(i + 1 == rows || j - 1 < 0){
                    i = i;
                    j = j + 1;
                    turn++;
                    continue;
                }

                
                i = i + 1;
                j = j - 1;
            }
        }
        ans.push_back(mat[rows - 1][cols - 1]);
        return ans;
    }
};



