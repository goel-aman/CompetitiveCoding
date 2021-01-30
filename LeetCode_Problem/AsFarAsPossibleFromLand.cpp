// 1162. As Far from Land as Possible

// Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, 
// find a water cell such that its distance to the nearest land cell is maximized, and return the 
// distance. If no land or water exists in the grid, return -1.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0)
//  and (x1, y1) is |x0 - x1| + |y0 - y1|.

 
// Example 1:
// Input: grid = [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: The cell (1, 1) is as far as possible from all the land with distance 2.

// Example 2:
// Input: grid = [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: The cell (2, 2) is as far as possible from all the land with distance 4.
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1

#include<bits/stdc++.h>
using namespace std;

class Solution {
    map<pair<int,int>,bool> m;
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int,int>> q;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    pair<int,int> p;
                    p.first = i;
                    p.second = j;
                    m[p] = true;
                    q.push(p);
                }
            }
        }
        int val = q.size();
        if(val == 0 || val == (rows * cols)){
            return -1;
        }
        int ans = 0;
        while(!q.empty()){
            int length = q.size();
            while(length--){
                pair<int,int> a = q.front();
                q.pop();
                int newx = a.first;
                int newy = a.second;
                pair<int,int> p1(newx + 1,newy);
                pair<int,int> p2(newx - 1,newy);
                pair<int,int> p3(newx,newy - 1);
                pair<int,int> p4(newx,newy + 1);
                if(newx + 1 < rows && newx + 1 >= 0 && !(m.count(p1))){
                    q.push(p1);
                    m[p1] = true;
                }

                if(newx - 1 < rows && newx - 1 >=0 && !(m.count(p2))){
                    q.push(p2);
                    m[p2] = true;
                }

                if(newy - 1 < cols && newy - 1 >= 0 && !(m.count(p3))){
                    q.push(p3);
                    m[p3] = true;
                }

                if(newy + 1 < cols && newy + 1 >= 0 && !(m.count(p4))){
                    q.push(p4);
                    m[p4]= true;
                }
            }
            ans++;
        }
        return ans - 1;
    }
};