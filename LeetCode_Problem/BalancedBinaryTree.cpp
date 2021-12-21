#include<bits/stdc++.h>
using namespace std;

// 110. Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is 
// defined as:

// a binary tree in which the left and right subtrees of 
// every node differ in height by no more than 1.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true
 
// Constraints:
// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class element{
    public:
    element(){
        height = 0;
        isBalanced = true;
    }
    int height;
    bool isBalanced;
};


class Solution {
public:
    element isBalance(TreeNode* root){
        if(root == NULL){
            element ret;
            ret.height = 0;
            ret.isBalanced = true;
            return ret;
        }
        element ret;
        
        element right = isBalance(root->right);
        if(right.isBalanced == false){
            ret.isBalanced = false;
            return ret;
        }
        element left = isBalance(root->left);
        if(left.isBalanced == false){
            ret.isBalanced = false;
            return ret;
        }
        
        if(abs(right.height - left.height) <= 1){
            ret.isBalanced = true;
            ret.height = (left.height >= right.height) ? (left.height + 1) : (right.height + 1);
            return ret;
        }
        ret.isBalanced = false;
        return ret;
    }
    
    bool isBalanced(TreeNode* root) {
        element ans = isBalance(root);
        if(ans.isBalanced == true){
            return true;
        }
        return false;
    }        
};