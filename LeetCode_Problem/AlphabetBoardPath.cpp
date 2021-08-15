#include<bits/stdc++.h>
using namespace std;

// 1138. Alphabet Board Path
// On an alphabet board, we start at position (0, 0),
//  corresponding to character board[0][0].

// Here, board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"], 
// as shown in the diagram below.

// We may make the following moves:
// 'U' moves our position up one row, if the position 
// exists on the board;
// 'D' moves our position down one row, if the 
// position exists on the board;
// 'L' moves our position left one column, if the 
// position exists on the board;
// 'R' moves our position right one column, if the 
// position exists on the board;
// '!' adds the character board[r][c] at our current 
// position (r, c) to the answer.
// (Here, the only positions that exist on the board are
//  positions with letters on them.)

// Return a sequence of moves that makes our answer equal to
//  target in the minimum number of moves.  You may return 
// any path that does so.

// Example 1:
// Input: target = "leet"
// Output: "DDR!UURRR!!DDD!"

// Example 2:
// Input: target = "code"
// Output: "RR!DDRR!UUL!R!"

// Constraints:
// 1 <= target.length <= 100
// target consists only of English 
// lowercase letters.

class Solution {
public:
    pair<int,int> fetchPosition(char val){
        int value = val - 'a';
        int row = value / 5;
        int col = value % 5;
        return {row,col};
    }

    string alphabetBoardPath(string target) {
        pair<int,int> current = {0,0};
        int targetLength = target.size();
        string ans = "";
        for(int i=0;i<targetLength;i++){
            char alphabet = target[i];
            pair<int,int> pos = fetchPosition(alphabet);
            int differenceX = pos.first - current.first;
            int differenceY = pos.second - current.second;
            
            if(pos.first == 5 && pos.second == 0){
                if(differenceY >= 0 ){
                    for(int j=0;j<differenceY;j++){
                        ans += "R";
                    }
                }else{
                    for(int j=0;j<abs(differenceY);j++){
                        ans += "L";
                    }
                }    

                if(differenceX >= 0){
                    for(int j=0;j<differenceX;j++){
                        ans += "D";
                    }
                }
                
                if(differenceX < 0) {
                    for(int j=0;j<abs(differenceX);j++){
                        ans += "U";
                    }
                }

            }

            else{

                if(differenceX >= 0){
                    for(int j=0;j<differenceX;j++){
                        ans += "D";
                    }
                }
                
                if(differenceX < 0) {
                    for(int j=0;j<abs(differenceX);j++){
                        ans += "U";
                    }
                }

                
                if(differenceY >= 0 ){
                    for(int j=0;j<differenceY;j++){
                        ans += "R";
                    }
                }else{
                    for(int j=0;j<abs(differenceY);j++){
                        ans += "L";
                    }
                }
            }
            ans += "!";
            current.first = pos.first;
            current.second = pos.second;
        }
        return ans;
    }
};