// 200. Number of Islands

// Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or
//  vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:
// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,string> um;
    int ans;
    public:

    string findParent(string x){
        if(!um.count(x)){
            um[x] = x;
            ans++;
            return x;
        }

        if(um[x] == x){
            return x;
        }

        return um[x] = findParent(um[x]);
    }
    
    void merge(string x,string y){
        string xPar = findParent(x);
        string yPar = findParent(y);

        if(xPar != yPar){
            um[xPar] = yPar;
            ans--;

        }
        return ;
    }
    int numIslands(vector<vector<char>>& grid) {
        ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    string val = to_string(i) + ";" + to_string(j);
                    string value = findParent(val);
                    if(i - 1 >= 0 && i - 1 < rows && grid[i - 1][j] == '1'){
                        string val1 = to_string(i - 1) + ";" + to_string(j);
                        if(grid[i - 1][j] == '1'){
                            merge(val,val1);
                        }
                    }

                    if(i + 1 >= 0 && i + 1 < rows && grid[i + 1][j] == '1'){
                        string val1 = to_string(i + 1) + ";" + to_string(j);
                        if(grid[i + 1][j] == '1'){
                            merge(val,val1);
                        }
                    }

                    if( j - 1 >= 0 && j - 1 < cols && grid[i][j - 1] == '1'){
                        string val1 = to_string(i) + ";" + to_string(j - 1);
                        if(grid[i][j - 1] == '1'){
                            merge(val,val1);
                        }
                    }

                    if(j + 1 >= 0 && j + 1 < cols && grid[i][j + 1] == '1'){
                        string val1 = to_string(i) + ";" + to_string( j + 1);
                        if(grid[i][j + 1] == '1'){
                            merge(val,val1);
                        }
                    }
                }
            }
        }
        return ans;
    }
};