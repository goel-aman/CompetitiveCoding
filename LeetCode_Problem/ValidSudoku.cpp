#include<bits/stdc++.h>
using namespace std;

// 36. Valid Sudoku

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 
// Example 1:

// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // unordered_map<char,bool> um;
        for(int i=0;i<9;i++){
            unordered_map<char,bool> row;
            unordered_map<char,bool> col;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }

                if(row.count(board[i][j]) > 0){
                    // cout<<"Answer is is false;"<<endl;
                    return false;
                }
                else{
                    row[board[i][j]] = true;
                }
            }

            for(int j=0;j<9;j++){
                if(board[j][i] == '.'){
                    continue;
                }

                if(col.count(board[j][i]) > 0){
                    return false;
                }
                else{
                    col[board[j][i]] = true;
                }    
            }

        }

        vector<vector<int>> vec = {{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
        for(int i=0;i<9;i++){
            int startI = 3 * vec[i][0];
            int startJ = 3 * vec[i][1];
            unordered_map<char,bool> umm;
            for(int ii=startI;ii<startI + 3;ii++){
                for(int j=startJ;j<startJ + 3;j++){
                    if(board[ii][j] == '.'){
                        continue;
                    }

                    if(umm.count(board[ii][j]) > 0){
                        return false;
                    }

                    umm[board[ii][j]] = true;
                }
            }         
        }
        return true;
    }
};