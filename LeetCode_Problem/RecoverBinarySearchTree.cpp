#include<bits/stdc++.h>
using namespace std;

// 99. Recover Binary Search Tree


// You are given the root of a binary search tree (BST), where exactly
//  two nodes of the tree were swapped by mistake. Recover the tree without
//  changing its structure.

// Follow up: A solution using O(n) space is pretty straight forward.
//  Could you devise a constant space solution?

// Example 1:
// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. 
// Swapping 1 and 3 makes the BST valid.

// Example 2:
// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3.
//  Swapping 2 and 3 makes the BST valid.
 

// Constraints:
// The number of nodes in the tree is in the range [2, 1000].
// -231 <= Node.val <= 231 - 1


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int i = 0;
    vector<int> sorted;
public:
    void inorder(TreeNode* root){
        if(root == NULL){
            return ;
        }

        if(root->left != NULL){
            inorder(root->left);
        }

        sorted.push_back(root->val);

        if(root->right != NULL){
            inorder(root->right);
        }
        return ;
    }

    void inorderFill(TreeNode* root){
        if(root == NULL){
            return ;
        }

        if(root->left != NULL){
            inorderFill(root->left);
        }

        root->val = sorted[i];
        i++;

        if(root->right != NULL){
            inorderFill(root->right);
        }
        return ;
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(sorted.begin(),sorted.end());
        inorderFill(root);      
        return ;
    }
};