#include<bits/stdc++.h>
using namespace std;

// 1197. Minimum Knight Moves
// In an infinite chess board with coordinates 
// from -infinity to +infinity, you have a knight
// at square [0, 0].

// A knight has 8 possible moves it can make, as 
// illustrated below. Each move is two squares in
// a cardinal direction, then one square in an 
// orthogonal direction.

// Return the minimum number of steps needed to 
// move the knight to the square [x, y]. It is 
// guaranteed the answer exists.

// Example 1:
// Input: x = 2, y = 1
// Output: 1
// Explanation: [0, 0] → [2, 1]

// Example 2:
// Input: x = 5, y = 5
// Output: 4
// Explanation: [0, 0] → [2, 1] → [4, 2] → [3, 4] → [5, 5]
 
// Constraints:
// -300 <= x, y <= 300
// 0 <= |x| + |y| <= 300




class Solution {
    vector<pair<int,int>> moves = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
public:
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        queue<pair<int,int>> que;
        que.push({0,0});
        unordered_set<int> visited;
        visited.insert(0);
        int level = 0;
        while(!que.empty()){
            int length = que.size();
            while(length--){
                pair<int,int> front = que.front();
                que.pop();
                if(front.first == x && front.second == y){
                    return level;
                }

                for(auto var : moves){
                    int newX = front.first + var.first;
                    int newY = front.second + var.second;
                    int check = 3000 * newX + newY;
                    if(!visited.count(check) && newX >= -1 && newY >= -1){
                        visited.insert(check);
                        que.push({newX,newY});
                    }
                }
            }
            level++;
        }
        return 0;
    }
};