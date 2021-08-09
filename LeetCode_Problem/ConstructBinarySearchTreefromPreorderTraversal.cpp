#include<bits/stdc++.h>
using namespace std;


// Construct Binary Search Tree from Preorder Traversal
// Given an array of integers preorder, which represents the 
// preorder traversal of a BST (i.e., binary search tree), 
// construct the tree and return its root.

// It is guaranteed that there is always possible to find a 
// binary search tree with the given requirements for the 
// given test cases.

// A binary search tree is a binary tree where for every node,
// any descendant of Node.left has a value strictly less than p
// Node.val, and any descendant of Node.right has a value strictly
//  greater than Node.val.

// A preorder traversal of a binary tree displays the value of
//  the node first, then traverses Node.left, then traverses
//  Node.right.

// Example 1:
// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]

// Example 2:
// Input: preorder = [1,3]
// Output: [1,null,3]
 
// Constraints:
// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 108
// All the values of preorder are unique.


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
    TreeNode* formBst(vector<int>& preorder,int startIndex,int endIndex){
        if(startIndex > endIndex){
            return NULL;
        }

        if(startIndex == endIndex){
            TreeNode* root = new TreeNode(preorder[startIndex]); 
            return root;
        }

        TreeNode* root = new TreeNode(preorder[startIndex]);
        

        int i = startIndex + 1;
        for(;i<=endIndex;i++){
            if(preorder[i] > preorder[startIndex]){
                break;
            }
        }

        root->right = formBst(preorder,i,endIndex);
        root->left = formBst(preorder,startIndex + 1,i - 1);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preorderLength = preorder.size();
        return formBst(preorder,0,preorderLength - 1);
    }
};