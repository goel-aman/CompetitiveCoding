// 1361. Validate Binary Tree Nodes

// You have n binary tree nodes numbered from 0 to n - 1 where node i has two children
//  leftChild[i] and rightChild[i], return true if and only if all the given nodes 
// form exactly one valid binary tree.

// If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

// Note that the nodes have no values and that we only use the node numbers in this problem.


// Example 1:
// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
// Output: true

// Example 2:
// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
// Output: false

// Example 3:
// Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
// Output: false

// Example 4:
// Input: n = 6, leftChild = [1,-1,-1,4,-1,-1], rightChild = [2,-1,-1,5,-1,-1]
// Output: false
 
// Constraints:
// 1 <= n <= 10^4
// leftChild.length == rightChild.length == n
// -1 <= leftChild[i], rightChild[i] <= n - 1


#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,vector<int>> um;
    unordered_map<int,bool> present;
public:
    bool checkCycle(vector<int> &visited,int source){
        visited[source] = 1;
        queue<int> q;
        q.push(source);
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(auto x : um[front]){
                if(visited[x] == 1){
                    return true;
                }
                else{
                    visited[x] = 1;
                    bool ans = checkCycle(visited,x);
                    if(ans == true){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(n == 1){
            return true;
        }
        vector<int> visited(n,0);
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i] != -1){
                um[i].push_back(leftChild[i]);
                present[leftChild[i]] = true;
            }
        }

        for(int i=0;i<rightChild.size();i++){
            if(rightChild[i] != -1){
                um[i].push_back(rightChild[i]);
                present[rightChild[i]] = true;
            }
        }

        int source = -1;
        
        for(auto var : um){
            if(!present.count(var.first)){
                source = var.first;
            }
        }
        if(source == -1){
            return false;
        }
        
        bool ans = checkCycle(visited,source);
        if(ans == true){
            return false;
        }

        for(int i=0;i<n;i++){
            if(visited[i] != 1){
                return false;
            }
        }
        return true;
    }
};