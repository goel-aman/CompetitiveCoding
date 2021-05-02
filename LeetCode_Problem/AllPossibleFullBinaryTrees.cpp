#include<bits/stdc++.h>
using namespace std;

// Given an integer n, return a list of all possible full binary trees
//  with n nodes. Each node of each tree in the answer must have Node.val == 0.
// Each element of the answer is the root node of one possible tree.
// You may return the final list of trees in any order.
// A full binary tree is a binary tree where each node has exactly 0 or 2 children.

// Example 1:
// Input: n = 7
// Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

// Example 2:
// Input: n = 3
// Output: [[0,0,0]]
 
// Constraints:
// 1 <= n <= 20

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<int,vector<TreeNode*>> um;
public:
    
    vector<TreeNode*> allPossibleFBT(int n) {       
        vector<TreeNode*> ans;
        if(um.count(n) > 0){
            return um[n];
        }
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            vector<TreeNode*> vec;
            vec.push_back(root);
            return vec;
        }else{
            for(int i=1;i<n;i+=2){
                int right = i, left = n - 1 - right;
                for(auto x : allPossibleFBT(right)){
                    for(auto y : allPossibleFBT(left)){
                        TreeNode* root = new TreeNode(0);
                        root->right = x;
                        root->left = y;
                        ans.push_back(root);
                    }
                }
            }
        }
        return um[n] = ans;
    }
};