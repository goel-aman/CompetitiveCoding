#include<bits/stdc++.h>
using namespace std;

// 79. Word Search
// Given an m x n grid of characters board and 
// a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent 
// cells, where adjacent cells are horizontally or vertically 
// neighboring. The same letter cell may not be used more than once.

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// , word = "ABCCED"
// Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// , word = "SEE"
// Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
// , word = "ABCB"
// Output: false
 
// Constraints:
// m == board.length
// n = board[i].length
// 1 <= m, n <= 6
// 1 <= word.length <= 15
// board and word consists of only lowercase 
// and uppercase English letters.
 

// Follow up: Could you use search pruning to make your
//  solution faster with a larger board?


class Solution {
    int wordLength;
    int rows;
    int cols;
public:
    bool exists(vector<vector<char>>& board,string &word,int index,int row,int col,vector<vector<int>>& visited){
        if(index >= wordLength){
            return true;
        }

        if(col + 1 < cols && board[row][col + 1] == word[index] && visited[row][col + 1] == -1){
            visited[row][col + 1] = true;
            bool ans = exists(board,word,index + 1,row,col + 1,visited);
            if(ans){ return true; }
            visited[row][col + 1] = -1;
        }

        if(col - 1 >= 0 && board[row][col - 1] == word[index] && visited[row][col - 1] == -1){
            visited[row][col - 1] = true;
            bool ans = exists(board,word,index + 1,row,col - 1,visited);
            if(ans){ return true; }
            visited[row][col - 1] = -1;
        }

        if(row + 1 < rows && board[row + 1][col] == word[index] && visited[row + 1][col] == -1){
            visited[row + 1][col] = true;
            bool ans = exists(board,word,index + 1,row + 1,col,visited);
            if(ans){ return true; }
            visited[row + 1][col] = -1;
        }

        if(row - 1 >= 0 && board[row - 1][col] == word[index] && visited[row - 1][col] == -1){
            visited[row - 1][col] = true;
            bool ans = exists(board,word,index +1,row -1,col,visited);
            if(ans){ return true; }
            visited[row - 1][col] = -1;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        wordLength = word.length();
        rows = board.size();
        cols = board[0].size();
        vector<vector<int>> seedPages;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == word[0]){
                    seedPages.push_back({i,j});  
                }
            }
        }
        vector<vector<int>> visited(rows,vector<int>(cols,-1));
        int seedPagesLength = seedPages.size();
        
        for(int i=0;i<seedPagesLength;i++){
            visited[seedPages[i][0]][seedPages[i][1]] = true;
            bool ans = exists(board,word,1,seedPages[i][0],seedPages[i][1],visited);
            visited[seedPages[i][0]][seedPages[i][1]] = -1;
            if(ans){
                return true;
            }
        }
        return false;   
    }
};