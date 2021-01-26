// Path With Minimum Effort

// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns,
//  where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell,
//   (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can 
//   move up, down, left, or right, and you wish to find a route that requires the minimum effort.

// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

 

// Example 1:



// Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
// Output: 2
// Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
// This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
// Example 2:



// Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
// Output: 1
// Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
// Example 3:


// Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
// Output: 0
// Explanation: This route does not require any effort.
 

// Constraints:

// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106
//    Hide Hint #1  
// Consider the grid as a graph, where adjacent cells have an edge with cost of the difference between the cells.
//    Hide Hint #2  
// If you are given threshold k, check if it is possible to go from (0, 0) to (n-1, m-1) using only edges of ≤ k cost.
//    Hide Hint #3  
// Binary search the k value.


// Solution
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int visited[101][101];
public:
    // n is row , m is column 
    bool isPossible(int currentI,int currentJ,int n,int m,vector<vector<int>> &heights,int k){
        if(currentI == n - 1 && currentJ == m - 1){
            return true;
        }
        visited[currentI][currentJ] = 1;
        bool ans = false;

        if(currentI - 1 >= 0 && currentI - 1 < n && !(visited[currentI - 1][currentJ]) && abs(heights[currentI - 1][currentJ] - heights[currentI][currentJ]) <= k ){
            ans = (ans || isPossible(currentI - 1,currentJ,n,m,heights,k));
        }

        if(currentI + 1 >= 0 && currentI + 1 < n && !(visited[currentI + 1][currentJ]) && abs(heights[currentI + 1][currentJ] - heights[currentI][currentJ]) <= k ){
            ans = (ans || isPossible(currentI + 1,currentJ,n,m,heights,k)); 
        }

        if(currentJ + 1 < m && currentJ + 1 >= 0 && !(visited[currentI][currentJ + 1]) && abs(heights[currentI][currentJ + 1] - heights[currentI][currentJ]) <= k ){
            ans = (ans || isPossible(currentI,currentJ + 1,n,m,heights,k));
        }

        if(currentJ - 1 < m && currentJ - 1 >= 0 && !(visited[currentI][currentJ - 1]) && abs(heights[currentI][currentJ - 1] - heights[currentI][currentJ]) <= k){
            ans = (ans || isPossible(currentI,currentJ - 1,n,m,heights,k));
        }
        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int s = 0;
        int e = INT_MAX;
        int mid;
        int ans = INT_MAX;
        while(s <= e){
            mid = s + ((e - s) / 2);
            memset(visited,0,sizeof(visited));
            if(isPossible(0,0,n,m,heights,mid)){
                e = mid - 1;
                ans = min(mid,ans);
            }else{
                s = mid + 1;
            }
        }
        return ans;
    }
};