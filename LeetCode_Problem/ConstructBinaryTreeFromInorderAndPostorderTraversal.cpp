#include<bits/stdc++.h>
using namespace std;

// 106. Construct Binary Tree from Inorder and Postorder Traversal

// Given two integer arrays inorder and postorder where inorder is the inorder
//  traversal of a binary tree and postorder is the postorder traversal of the 
// same tree, construct and return the binary tree.

// Example 1:
// Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: inorder = [-1], postorder = [-1]
// Output: [-1]

// Constraints:
// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder and postorder consist of unique values.
// Each value of postorder also appears in inorder.
// inorder is guaranteed to be the inorder traversal of the tree.
// postorder is guaranteed to be the postorder traversal of the tree.


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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder,int inorderIndex1,int inorderIndex2,int postIndex1,int postIndex2) {
        if(inorderIndex1 > inorderIndex2 || postIndex1 > postIndex2){
            return NULL;
        }
        if(postIndex1 == postIndex2 && inorderIndex1 == inorderIndex2){
            TreeNode *rt = new TreeNode(postorder[postIndex2]);
            return rt;
        }
        TreeNode* rt = new TreeNode(postorder[postIndex2]);
        for(int i=inorderIndex1;i<=inorderIndex2;i++){
            if(postorder[postIndex2] == inorder[i]){
                rt->left = buildTree(inorder,postorder,inorderIndex1,i - 1,postIndex1,postIndex1 + i - inorderIndex1 - 1);
                rt->right = buildTree(inorder,postorder,i + 1, inorderIndex2,postIndex2-(inorderIndex2 - i) ,postIndex2 - 1);
            }
        }
        return rt;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,postorder,0,inorder.size() - 1,0,postorder.size() - 1);
    }
};