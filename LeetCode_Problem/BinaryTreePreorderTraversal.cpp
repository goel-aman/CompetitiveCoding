#include<bits/stdc++.h>
using namespace std;

// 144. Binary Tree Preorder Traversal

// Given the root of a binary tree, return the 
// preorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,2,3]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]

// Example 4:
// Input: root = [1,2]
// Output: [1,2]

// Example 5:
// Input: root = [1,null,2]
// Output: [1,2]
 
// Constraints:
// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 
// Follow up: Recursive solution is trivial, could you do it iteratively?

// /**
//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//  */
class Solution {
    vector<int> ans;
public:
    void traverse(TreeNode* root){
        if(root == NULL){
            return ;
        }

        ans.push_back(root->val);
        if(root->left != NULL){
            traverse(root->left);
        }

        if(root->right != NULL){
            traverse(root->right);
        }

        return ;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);
        return ans;
    }
};