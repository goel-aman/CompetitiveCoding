#include<bits/stdc++.h>
using namespace std;

// 1861. Rotating the Box
// You are given an m x n matrix of characters box representing a 
// side-view of a box. Each cell of the box is one of the following:
// A stone '#'
// A stationary obstacle '*'
// Empty '.'
// The box is rotated 90 degrees clockwise, causing some of the stones
//  to fall due to gravity. Each stone falls down until it lands on an 
// obstacle, another stone, or the bottom of the box. Gravity does not
//  affect the obstacles' positions, and the inertia from the box's 
// rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in box rests on an obstacle, another
//  stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation 
// described above.

// Example 1:
// Input: box = [["#",".","#"]]
// Output: [["."],
//          ["#"],
//          ["#"]]

// Example 2:
// Input: box = [["#",".","*","."],
//               ["#","#","*","."]]
// Output: [["#","."],
//          ["#","#"],
//          ["*","*"],
//          [".","."]]

// Example 3:
// Input: box = [["#","#","*",".","*","."],
//               ["#","#","#","*",".","."],
//               ["#","#","#",".","#","."]]
// Output: [[".","#","#"],
//          [".","#","#"],
//          ["#","#","*"],
//          ["#","*","."],
//          ["#",".","*"],
//          ["#",".","."]]
 
// Constraints:
// m == box.length
// n == box[i].length
// 1 <= m, n <= 500
// box[i][j] is either '#', '*', or '.'.


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
        int cols = box[0].size();

        vector<vector<char>> invertedBox(cols,vector<char>(rows));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int newRow = j, newCol = rows - i - 1;
                invertedBox[newRow][newCol] = box[i][j];
            }
        }

        int invertedRow = cols,invertedCol = rows;
        for(int i=0;i<invertedCol;i++){
            queue<int> que;
            for(int j = invertedRow - 1;j>=0;j--){
                if(invertedBox[j][i] == '*'){
                    while(!que.empty()){
                        que.pop();
                    }
                }

                if(invertedBox[j][i] == '.'){
                    que.push(j);
                }

                if(invertedBox[j][i] == '#'){
                    if(que.empty()){
                        continue;
                    }else{
                        invertedBox[j][i] = '.';
                        invertedBox[que.front()][i] = '#';
                        que.pop();
                        que.push(j);
                    }
                }
            }
        }
        return invertedBox;
    }
};