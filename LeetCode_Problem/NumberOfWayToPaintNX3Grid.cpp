// 1411. Number of Ways to Paint N × 3 Grid
// You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one 
// of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells
//  have the same color (i.e., no two cells that share vertical or horizontal sides have
//  the same color).

// Given n the number of rows of the grid, return the number of ways you can paint this 
// grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

// Example 1:
// Input: n = 1
// Output: 12
// Explanation: There are 12 possible way to paint the grid as shown.

// Example 2:
// Input: n = 2
// Output: 54

// Example 3:
// Input: n = 3
// Output: 246

// Example 4:
// Input: n = 7
// Output: 106494

// Example 5:
// Input: n = 5000
// Output: 30228214
 
// Constraints:
// n == grid.length
// grid[i].length == 3
// 1 <= n <= 5000


#include<bits/stdc++.h>
using namespace std;

// Using Recursion.

// class Solution {
// public:
//     int numOfWayys(int row,int col,int rows,int cols,vector<vector<char>> colors){
//         cout<<"Row is : "<<row <<"Column is : "<<col<<endl;
//         set<char> s = {'R','G','B'};
//         if(row >= rows){
//             cout<<"Anwer is : "<<0<<endl;
//             return 1;
//         }
//         if(row - 1 >= 0 && row - 1 < rows){
//             s.erase(colors[row - 1][col]);
//         }

//         if(col - 1 >= 0 && col - 1 < cols){
//             s.erase(colors[row][col - 1]);
//         }

//         int ans = 0;
//         for(auto element : s)
//         {
//             colors[row][col] = element;
//             if(col + 1 < cols){
//                 ans += numOfWayys(row,col + 1,rows,cols,colors);
//             }
//             else{
//                 ans += numOfWayys(row + 1,0,rows,cols,colors);
//             }
//         }
//         cout<<"Answer is : "<<ans<<endl;
//         return ans;
//     }

//     int numOfWays(int n) {
//         vector<vector<char>> colors(n,vector<char> (3));
//         return numOfWayys(0,0,n,3,colors);
//     }
// };


// Using Dynammic Programming.
class Solution {
    int mod = 1e9 + 7;
public:
    int numOfWays(int n) {
        long int color2 = 6;
        long int color3 = 6;
        for(int i=2;i<=n;i++){
            long int temp = color2;
            color2 = (3 * color2 + 2 * color3) % mod;
            color3 = (2 * temp + 2 * color3) % mod;
        }
        return ((color2 + color3)%mod);
    }
};