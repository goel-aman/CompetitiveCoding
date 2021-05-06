// 105. Construct Binary Tree from Preorder and Inorder Traversal

// Given two integer arrays preorder and inorder where preorder is the preorder
//  traversal of a binary tree and inorder is the inorder traversal of the same 
// tree, construct and return the binary tree.

// Example 1:
// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]

// Example 2:
// Input: preorder = [-1], inorder = [-1]
// Output: [-1]
 
// Constraints:
// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder and inorder consist of unique values.
// Each value of inorder also appears in preorder.
// preorder is guaranteed to be the preorder traversal of the tree.
// inorder is guaranteed to be the inorder traversal of the tree.

#include<bits/stdc++.h>
using namespace std;

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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int preIndex1,int preIndex2,int inorderIndex1,int inorderIndex2) {
        if(preIndex1 > preIndex2 || inorderIndex1 > inorderIndex2){
            return NULL;
        }

        TreeNode* rt = new TreeNode(preorder[preIndex1]);
        for(int i=inorderIndex1;i<=inorderIndex2;i++){
            if(preorder[preIndex1] == inorder[i]){
                rt->left = buildTree(preorder,inorder,preIndex1 + 1,(i - inorderIndex1) + preIndex1,inorderIndex1,i - 1);
                rt->right = buildTree(preorder,inorder,(i - inorderIndex1) + preIndex1 + 1,preIndex2,i + 1,inorderIndex2);
            }
        }
        return rt;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder,inorder,0,preorder.size() - 1,0,inorder.size() - 1);
    }
};