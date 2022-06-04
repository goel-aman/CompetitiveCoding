#include<bits/stdc++.h>
using namespace std;

// 582. Kill Process
// You have n processes forming a rooted tree structure. You are
//  given two integer arrays pid and ppid, where pid[i] is the ID 
// of the ith process and ppid[i] is the ID of the ith process's 
// parent process.

// Each process has only one parent process but may have multiple
//  children processes. Only one process has ppid[i] = 0, which means 
// this process has no parent process (the root of the tree).

// When a process is killed, all of its children processes will also
//  be killed.

// Given an integer kill representing the ID of a process you want to
//  kill, return a list of the IDs of the processes that 
// will be killed. You may return the answer in any order.

// Example 1:
// Input: pid = [1,3,10,5], ppid = [3,0,5,3], kill = 5
// Output: [5,10]
// Explanation: The processes colored in red are the processes that
//  should be killed.

// Example 2:
// Input: pid = [1], ppid = [0], kill = 1
// Output: [1]

// Constraints:
// n == pid.length
// n == ppid.length
// 1 <= n <= 5 * 104
// 1 <= pid[i] <= 5 * 104
// 0 <= ppid[i] <= 5 * 104
// Only one process has no parent.
// All the values of pid are unique.
// kill is guaranteed to be in pid.

class Solution {
    unordered_map<int,vector<int>> childrens;
public:
    void traverse(vector<int>& ans,int kill){
        ans.push_back(kill);
        for(int i=0;i<childrens[kill].size();i++){
            traverse(ans,childrens[kill][i]);
        }
        return ;
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int ppidLength = ppid.size();
        
        for(int i=0;i<ppidLength;i++){
            childrens[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> ans;
        
        traverse(ans,kill);
        return ans;
    }
};