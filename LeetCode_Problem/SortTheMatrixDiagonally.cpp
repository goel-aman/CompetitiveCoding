#include<bits/stdc++.h>
using namespace std;

// 1329. Sort the Matrix Diagonally
// A matrix diagonal is a diagonal line of cells starting 
// from some cell in either the topmost row or leftmost 
// column and going in the bottom-right direction until 
// reaching the matrix's end. For example, the matrix diagonal
//  starting from mat[2][0], where mat is a 6 x 3 matrix, 
// includes cells mat[2][0], mat[3][1], and mat[4][2].

// Given an m x n matrix mat of integers, sort each 
// matrix diagonal in ascending order and return the
//  resulting matrix.

// Example 1:
// Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
// Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

// Example 2:
// Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],
// [75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
// Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],
// [22,27,31,36,50,66],[84,28,75,33,55,68]]
 
// Constraints:
// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 100
// 1 <= mat[i][j] <= 100


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<pair<int,int>> vec;
        for(int i=cols - 1;i>=0;i--){
            vec.push_back({0,i});          
        }

        for(int j=1;j<rows;j++){
            vec.push_back({j,0});
        }      

        for(int i=0;i<vec.size();i++){
            int row = vec[i].first, col =vec[i].second;
            vector<int> temp;
            while(row < rows && col < cols){
                temp.push_back(mat[row][col]);
                row++;
                col++;
            }         

            sort(temp.begin(),temp.end());
            int iter = 0;
            row = vec[i].first;
            col = vec[i].second;
            while(row < rows && col < cols){
                mat[row][col] = temp[iter];
                iter++;
                row++;
                col++;
            }
        }
        return mat;
    }
};