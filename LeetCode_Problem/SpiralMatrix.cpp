#include<bits/stdc++.h>
using namespace std;

// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100
class Solution {
public:
    vector<int> spiralOrderr(vector<vector<int>>& matrix,int rowStart,int rowEnd,int colStart,int colEnd){
        vector<int> ans;
        
        if(rowStart > rowEnd || colStart > colEnd){
            return ans;
        }
        
        for(int i=colStart;i<=colEnd;i++){
            ans.push_back(matrix[rowStart][i]);
        }
        
        if(rowStart == rowEnd){
            return ans;
        }

        for(int i=rowStart + 1;i<=rowEnd;i++){
            ans.push_back(matrix[i][colEnd]);
        }
        
        if(colEnd == colStart){
            return ans;
        }
        
        for(int i=colEnd - 1;i>=colStart;i--){
            ans.push_back(matrix[rowEnd][i]);
        }
        
        for(int i= (rowEnd - 1);i>=(rowStart + 1);i--){
            ans.push_back(matrix[i][colStart]);
        }
        
        vector<int> temp =  spiralOrderr(matrix,rowStart+1,rowEnd - 1,colStart + 1,colEnd - 1);
        for(auto var : temp){
            ans.push_back(var);
        }

        return ans;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        return spiralOrderr(matrix,0,matrix.size() - 1,0,matrix[0].size() - 1);
    }
};