// 210. Course Schedule II

// There are a total of n courses you have to take labelled from 0 to n - 1.

// Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi]
// this means you must take the course bi before the course ai.

// Given the total number of courses numCourses and a list of the prerequisite
// pairs, return the ordering of courses you should take to finish all courses.

// If there are many valid answers, return any of them. If it is impossible
//  to finish all courses, return an empty array.


// Example 1:
// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].


// Example 2:
// Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
// So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

// Example 3:
// Input: numCourses = 1, prerequisites = []
// Output: [0]
 
// Constraints:
// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// All the pairs [ai, bi] are distinct.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<int>> um;
public:
    void isPossible(vector<int> &visited,int source,stack<int> &Stack){
        visited[source] = 1;
        for(auto x : um[source]){
            if(!visited[x]){
                isPossible(visited,x,Stack);
            }
        }
        Stack.push(source);
    }

    bool detectCycle(vector<int> &visited,int source){
        visited[source] = 1;
        for(auto x : um[source]){
            if(visited[x] == 0){
                bool cycledetect = detectCycle(visited,x);
                if(cycledetect == true){
                    return true;
                }
                continue;
            }
            
            if(visited[x] == 2){
                continue;
            }

            if(visited[x] == 1){
                return true;
            }
        }
        visited[source] = 2;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto var : prerequisites){
            um[var[1]].push_back(var[0]);
        }

        int n = numCourses;
        vector<int> visited(n ,0);
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                bool ans = detectCycle(visited,i);
                if(ans == true){
                    vector<int> answer;
                    return answer;
                }
            }
        }
        for(int i=0;i<n;i++){
            visited[i] = 0;
        }
        stack<int> Stack;
        for(int i=0;i<n;i++){
            if(visited[i] == 0){
                isPossible(visited,i,Stack);
            }
        }
        vector<int> anss;
        while(!Stack.empty()){
            int val = Stack.top();
            Stack.pop();
            anss.push_back(val);
        }
        return anss;
    }
};