// 778. Swim in Rising Water

// On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

// Now rain starts to fall. At time t, the depth of the water everywhere is t. You can 
// swim from a square to another 4-directionally adjacent square if and only if the 
// elevation of both squares individually are at most t. You can swim infinite distance
//  in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// You start at the top left square (0, 0). What is the least time until you can reach the
//  bottom right square (N-1, N-1)?

// Example 1:
// Input: [[0,2],[1,3]]
// Output: 3
// Explanation:
// At time 0, you are in grid location (0, 0).
// You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

// You cannot reach point (1, 1) until time 3.
// When the depth of water is 3, we can swim anywhere inside the grid.

// Example 2:
// Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
// Output: 16
// Explanation:
//  0  1  2  3  4
// 24 23 22 21  5
// 12 13 14 15 16
// 11 17 18 19 20
// 10  9  8  7  6

// The final route is marked in bold.
// We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
// Note:

// 2 <= N <= 50.
// grid[i][j] is a permutation of [0, ..., N*N - 1].


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int gridLength = grid.size();
        int start = 0;
        int end = gridLength * gridLength;
        int mid;
        string target = to_string(gridLength - 1)+ ";" + to_string(gridLength - 1);
        int finalAns = INT_MAX;
        while(start <= end){
            mid = (start + end) / 2;
            // x coordinate , y coordinate
            queue<pair<int,int>> q;
            int gotIt = 0;
            q.push({0,0});
            unordered_map<string,bool> um;
            um["00"] = true;
            while(!q.empty()){
                pair<int,int> front = q.front();
                q.pop();



                if(front.first == gridLength - 1 && front.second == gridLength - 1){
                    gotIt = 1;
                    break;
                }

                if(front.first + 1 < gridLength && front.first + 1 >= 0 && grid[front.first + 1][front.second] <= mid)
                {
                    string s = to_string(front.first + 1) + ";" + to_string(front.second);
                    if(s == target){
                        gotIt = 1;
                        break;
                    }
                    if(!um.count(s)){
                        um[s] = true;
                        q.push({front.first + 1,front.second});
                    }
                }

                if(front.first - 1 >= 0 && front.first - 1 < gridLength && grid[front.first - 1][front.second] >= mid){
                    string s = to_string(front.first - 1) + ";" + to_string(front.second);
                    if(s == target){
                        gotIt = 1;
                        break;
                    }
                    if(!um.count(s)){
                        um[s] = true;
                        q.push({front.first - 1,front.second});
                    }
                }

                if(front.second - 1 >= 0 && front.second - 1 < gridLength && grid[front.first][front.second - 1] >= mid){
                    string s = to_string(front.first) + ";" + to_string(front.second - 1);
                    if(s == target){
                        gotIt = 1;
                        break;
                    }
                    if(!um.count(s)){
                        um[s] = true;
                        q.push({front.first,front.second - 1});
                    }
                }

                if(front.second + 1 < gridLength && front.second + 1 >= 0 && grid[front.first][front.second + 1] >= mid)
                {
                    string s = to_string(front.first) + ";" + to_string(front.second + 1);
                    if(s == target){
                        gotIt = 1;
                        break;
                    }
                    if(!um.count(s)){
                        um[s] = true;
                        q.push({front.first,front.second + 1});
                    }
                }
            }
            if(gotIt){
                finalAns = min(finalAns,mid);
                end = mid - 1;
                continue;
            }

            else{
                start = mid + 1;
                continue;
            }
        }
        return finalAns;
    }
};