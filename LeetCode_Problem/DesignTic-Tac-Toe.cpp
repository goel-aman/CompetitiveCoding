#include<bits/stdc++.h>
using namespace std;

// 348. Design Tic-Tac-Toe
// Assume the following rules are for the tic-tac-toe 
// game on an n x n board between two players:

// A move is guaranteed to be valid and is placed on an
//  empty block.
// Once a winning condition is reached, no more moves 
// are allowed.
// A player who succeeds in placing n of their marks in a
//  horizontal, vertical, or diagonal row wins the game.
// Implement the TicTacToe class:

// TicTacToe(int n) Initializes the object the size of the
//  board n.
// int move(int row, int col, int player) Indicates that the 
// player with id player plays at the cell (row, col) of the 
// board. The move is guaranteed to be a valid move.
 
// Example 1:
// Input
// ["TicTacToe", "move", "move", "move", "move", "move", "move", "move"]
// [[3], [0, 0, 1], [0, 2, 2], [2, 2, 1], [1, 1, 2], [2, 0, 1], [1, 0, 2], [2, 1, 1]]
// Output
// [null, 0, 0, 0, 0, 0, 0, 1]

// Explanation
// TicTacToe ticTacToe = new TicTacToe(3);
// Assume that player 1 is "X" and player 2 is "O" in the board.
// ticTacToe.move(0, 0, 1); // return 0 (no one wins)
// |X| | |
// | | | |    // Player 1 makes a move at (0, 0).
// | | | |

// ticTacToe.move(0, 2, 2); // return 0 (no one wins)
// |X| |O|
// | | | |    // Player 2 makes a move at (0, 2).
// | | | |

// ticTacToe.move(2, 2, 1); // return 0 (no one wins)
// |X| |O|
// | | | |    // Player 1 makes a move at (2, 2).
// | | |X|

// ticTacToe.move(1, 1, 2); // return 0 (no one wins)
// |X| |O|
// | |O| |    // Player 2 makes a move at (1, 1).
// | | |X|

// ticTacToe.move(2, 0, 1); // return 0 (no one wins)
// |X| |O|
// | |O| |    // Player 1 makes a move at (2, 0).
// |X| |X|

// ticTacToe.move(1, 0, 2); // return 0 (no one wins)
// |X| |O|
// |O|O| |    // Player 2 makes a move at (1, 0).
// |X| |X|

// ticTacToe.move(2, 1, 1); // return 1 (player 1 wins)
// |X| |O|
// |O|O| |    // Player 1 makes a move at (2, 1).
// |X|X|X|

// Constraints:
// 2 <= n <= 100
// player is 1 or 2.
// 0 <= row, col < n
// (row, col) are unique for each different call to move.
// At most n2 calls will be made to move.
 
// Follow-up: Could you do better than O(n2) per move() operation?

class TicTacToe {
    unordered_map<int,int> rowCount;
    unordered_map<int,int> rowValue;
    unordered_map<int,int> columnCount;
    unordered_map<int,int> columnValue;
    int firstDiagonalCount = 0;
    unordered_map<int,int> firstDiagonalValue;
    unordered_map<int,int> secondDiagonalValue;
    int secondDiagonalCount = 0;
    int gotAnswer = 0;
    int size;
    int win = 0;
    
public:
    TicTacToe(int n) {
        size = n;
    }
    
    int move(int row, int col, int player) {
        if(win == 1){
            return 1;
        }
        rowCount[row]++;
        columnCount[col]++;
        if(player == 1){
            rowValue[row]++;
            columnValue[col]++;
        }

        if(rowCount[row] == size){
            if(rowValue[row] == 0 || rowValue[row] == size){
                gotAnswer = 1;
                win = 1;
                return gotAnswer;
            }
        }

        if(columnCount[col] == size){
            if(columnValue[col] == 0 || columnValue[col] == size){
                gotAnswer = 1;
                return gotAnswer;
            }
        }

        if(row == col){
            firstDiagonalCount         
        }
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */