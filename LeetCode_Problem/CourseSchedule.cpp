// 207. Course Schedule

// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1.
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must
// take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

 // Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0. So it is possible.

// Example 2:
// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
// To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

// Constraints:
// 1 <= numCourses <= 105
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// All the pairs prerequisites[i] are unique.


#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<int,vector<int>> um;
public:
    bool detectCycle(vector<int> & visited,int source){
        visited[source] = 2;
        for(auto x : um[source])
        {
            if(visited[x] == 2){
                return true;
            }
            if(visited[x] == 1){
                continue;
            }

            bool ans = detectCycle(visited,x);
            if(ans == true){
                return true;
            } 
        }
        visited[source] = 1;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> visited(n ,0);
        for(auto var : prerequisites){
            um[var[0]].push_back(var[1]);
        }

        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                bool ans = detectCycle(visited,i);
                if(ans){
                    return false;
                }
            }
        }
        return true;
    }
};