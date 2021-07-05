#include<bits/stdc++.h>
using namespace std;

// 419. Battleships in a Board
// Given an m x n matrix board where each cell is a
//  battleship 'X' or empty '.', return the number 
// of the battleships on board.
// Battleships can only be placed horizontally or 
// vertically on board. In other words, they can only 
// be made of the shape 1 x k (1 row, k columns) or k x 1 
// (k rows, 1 column), where k can be of any size. At least
//  one horizontal or vertical cell separates between two 
// battleships (i.e., there are no adjacent battleships).

// Example 1:
// Input: board = [["X",".",".","X"],[".",".",".","X"]
// ,[".",".",".","X"]]
// Output: 2

// Example 2:
// Input: board = [["."]]
// Output: 0
 
// Constraints:
// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is either '.' or 'X'.
 
// Follow up: Could you do it in one-pass, using only O(1) extra
//  memory and without modifying the values board?

class Solution {
    int rows;
    int cols;
public:
    void traverse(int i,int j,vector<vector<char>>& board,vector<vector<int>> &visited){
        visited[i][j] = 1;

        if(i + 1 < rows && visited[i + 1][j] == -1 && board[i + 1][j] == 'X' ){
            traverse(i + 1,j,board,visited);          
        }

        if(i - 1 >= 0 && visited[i - 1][j] == -1 && board[i - 1][j] == 'X'){
            traverse(i - 1,j,board,visited);
        }

        if(j + 1 < cols && visited[i][j+1] == -1 && board[i][j + 1] == 'X'){
            traverse(i,j+1,board,visited);
        }

        if(j - 1 >= 0 && visited[i][j - 1] == -1 && board[i][j - 1] == 'X'){
            traverse(i,j - 1,board,visited);
        }

        return ;
    }

    int countBattleships(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        int ans = 0;
        vector<vector<int>> visited(rows,vector<int> (cols,-1));
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'X' && visited[i][j] == -1){
                    traverse(i,j,board,visited);
                    ans++;
                    // cout<<"hello"<<endl;
                }
            }
        }
        return ans;
    }
};