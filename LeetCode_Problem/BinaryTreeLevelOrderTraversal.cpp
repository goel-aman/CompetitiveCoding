// 102. Binary Tree Level Order Traversal


// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]


// Solution
#include<bits/stdc++.h>
using namespace std;


//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL){
            vector<vector<int>> v;
            return v;
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int length = q.size();
            vector<int> v;
            while(length--){
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left != NULL){
                    q.push(root->left);
                }
                if(temp->right != NULL){
                    q.push(root->right);
                }
            }
            ans.push_back(v);
        } 
        return ans;
    }
};