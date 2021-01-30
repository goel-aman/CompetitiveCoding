// 841. Keys and Rooms

// There are N rooms and you start in room 0.  Each room has a distinct number
//  in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 

// Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is 
// an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.

// Initially, all the rooms start locked (except for room 0). 

// You can walk back and forth between rooms freely.

// Return true if and only if you can enter every room.

// Example 1:

// Input: [[1],[2],[3],[]]
// Output: true
// Explanation:  
// We start in room 0, and pick up key 1.
// We then go to room 1, and pick up key 2.
// We then go to room 2, and pick up key 3.
// We then go to room 3.  Since we were able to go to every room, we return true.
// Example 2:

// Input: [[1,3],[3,0,1],[2],[0]]
// Output: false
// Explanation: We can't enter the room with number 2.
// Note:

// 1 <= rooms.length <= 1000
// 0 <= rooms[i].length <= 1000
// The number of keys in all rooms combined is at most 3000.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        bool * visited = new bool[n];
        visited[0] = true;
        for(int i = 1;i<n;i++){
            visited[i] = false;
        }
        queue<int> q;
        q.push(0);
        while(!q.empty())
        {
            int val = q.front();
            q.pop();
            for(int i=0;i<rooms[val].size();i++){
                if(visited[rooms[val][i]] != true){
                    visited[rooms[val][i]] = true;
                    q.push(rooms[val][i]);
                }
            }
        }
        bool ans = true;
        for(int i=0;i<n;i++){
            if(visited[i] == false){
                return false;
            }
        }
        return ans;
    }
};