#include<bits/stdc++.h>
using namespace std;

// Given an m x n matrix board containing 'X' and 'O', capture all regions surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

 // Example 1:
// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation: Surrounded regions should not be on the border, which means that any 'O' 
// on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and 
// it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected
//  if they are adjacent cells connected horizontally or vertically.

// Example 2:
// Input: board = [["X"]]
// Output: [["X"]]
 
// Constraints:
// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.
class Solution {
    unordered_map<int,int> um;
    
    void merge(int first,int second){
        int firstParent = findParent(first);
        int secondParent = findParent(second);

        if(firstParent != secondParent){
            um[firstParent] = secondParent;
        }

        return ;
    }
    
    int findParent(int input){
        if(!um.count(input)){
            um[input] = input;
        }

        if(um[input] == input){
            return input;
        }

        return um[input] = findParent(um[input]);
    }
public:
    void solve(vector<vector<char>>& board) {
        // cout<<"hello"<<endl;
        int rows = board.size();
        int cols = board[0].size();
        unordered_map<int,bool> isThere;
        vector<int> present;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                // cout<<"i is : "<<i<<"j value is : "<<j<<endl;
                if(board[i][j] == 'O' && (i == 0 || i == rows - 1 || j == cols - 1 || j == 0)){
                    // cout<<"i is : "<<i<<" j is : "<<j<<" "<<endl;
                    int vall = findParent(i + (j * 1000));
                    present.push_back(vall);
                }
                if(board[i][j] == 'O'){
                    int val = findParent(i + (j * 1000));
                    if(i - 1 >= 0 && i - 1 < rows && board[i - 1][j] == 'O'){
                        merge(i + (j * 1000) , i - 1 + (j * 1000));
                    }

                    if(i + 1 >= 0 && i + 1 < rows && board[i + 1][j] == 'O'){
                        merge(i + (j * 1000), i + 1 + (j * 1000));
                    }

                    if(j + 1 >= 0 && j + 1 < cols && board[i][j + 1] == 'O'){
                        merge(i + (j* 1000),i + ((j + 1)* 1000 ));
                    }

                    if(j - 1 >= 0 && j - 1 < cols && board[i][j -1 ] == 'O'){
                        merge(i + (j* 1000),i + ((j - 1)* 1000));
                    }
                }
            }
        }
        for(auto val : present){
            isThere[findParent(val)] = true;
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j] == 'O'){
                    if(isThere.count( findParent( i + (j* 1000) ) ) > 0){
                        continue;
                    }else{
                        board[i][j] = 'X';
                    }
                    board[i][j] = 'X';
                }
            }
        }
        return ;
    }
};