#include<bits/stdc++.h>
using namespace std;

// 37. Sudoku Solver
// Write a program to solve a Sudoku puzzle
//  by filling the empty cells.
// A sudoku solution must satisfy all of 
// the following rules:

// Each of the digits 1-9 must occur exactly
//  once in each row.
// Each of the digits 1-9 must occur exactly
//  once in each column.
// Each of the digits 1-9 must occur exactly 
// once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

// Example 1:
// Input: board = [["5","3",".",".","7",".",".",".","."],
// ["6",".",".","1","9","5",".",".","."],
// [".","9","8",".",".",".",".","6","."],
// ["8",".",".",".","6",".",".",".","3"],
// ["4",".",".","8",".","3",".",".","1"],
// ["7",".",".",".","2",".",".",".","6"],
// [".","6",".",".",".",".","2","8","."],
// [".",".",".","4","1","9",".",".","5"],
// [".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],
// ["6","7","2","1","9","5","3","4","8"],
// ["1","9","8","3","4","2","5","6","7"],
// ["8","5","9","7","6","1","4","2","3"],
// ["4","2","6","8","5","3","7","9","1"],
// ["7","1","3","9","2","4","8","5","6"],
// ["9","6","1","5","3","7","2","8","4"],
// ["2","8","7","4","1","9","6","3","5"],
// ["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown 
// above and the only valid solution is shown below:

// Constraints:
// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board
//  has only one solution.


class Solution {
    int rows;
    int cols;
public:
    bool check(int i,int j,vector<vector<char>>& board,char c){
        int r = i - i%3;
        int co = j - j%3;

        bool ans = true;

        for(int ii=0;ii<9;ii++){
            if(board[ii][j] == c){
                return false;
            }

            if(board[i][ii] == c){
                return false;
            }
        }

        for(int x=0;x < 3;x++){
            for(int y=0;y<3;y++){
                if(board[r + x][y + co] == c){
                    return false;
                }
            }
        }
        return ans;
    }

    bool solve(int i,int j,vector<vector<char>>& board){
        if(i >= 9) { return true;}
        if(j == 9) {
            return solve(i + 1,0,board);
        }

        if(board[i][j] != '.') {
            return solve(i,j + 1,board);
        }
        for(char c = '1';c <= '9';c++){
            if(check(i,j,board,c)){
                board[i][j] = c;
                bool value = solve(i,j + 1,board);
                if(value){
                    return true;
                }
                board[i][j] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        rows = board.size();
        cols = board.size();
        solve(0,0,board);
        return ;
    }
};