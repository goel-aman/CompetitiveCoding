#include<bits/stdc++.h>
using namespace std;

// 655. Print Binary Tree

// Given the root of a binary tree, construct a 0-indexed m x n 
// string matrix res that represents a formatted layout of the 
// tree. The formatted layout matrix should be constructed using
//  the following rules:

// The height of the tree is height and the number of rows m 
// should be equal to height + 1.
// The number of columns n should be equal to 2height+1 - 1.
// Place the root node in the middle of the top row (more 
// formally, at location res[0][(n-1)/2]).
// For each node that has been placed in the matrix at position
//  res[r][c], place its left child at res[r+1][c-2height-r-1] 
// and its right child at res[r+1][c+2height-r-1].
// Continue this process until all the nodes in the tree have 
// been placed.
// Any empty cells should contain the empty string "".
// Return the constructed matrix res.

// Example 1:
// Input: root = [1,2]
// Output: 
// [["","1",""],
//  ["2","",""]]

// Example 2:
// Input: root = [1,2,3,null,4]
// Output: 
// [["","","","1","","",""],
//  ["","2","","","","3",""],
//  ["","","4","","","",""]]

// Constraints:
// The number of nodes in the tree is in the range [1, 210].
// -99 <= Node.val <= 99
// The depth of the tree will be in the range [1, 10].


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

    int findHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        if(root->left == NULL && root->right == NULL){
            return 1;
        }

        int value = findHeight(root->left);
        int value2 = findHeight(root->right);

        return 1 + max(value,value2);
    }

    void computeAnswer(vector<vector<string>>& ans,TreeNode* root,int r,int c,int height){
        if(root == NULL){
            return ;
        }
        
        ans[r][c] = to_string(root->val);
        int leftCol = c - (int) pow(2,height-r-1);
        int rightCol = c + (int) pow(2,height-r-1);
        if(root->left != NULL){
            computeAnswer(ans,root->left,r + 1,leftCol,height);
        }
        if(root->right != NULL){
            computeAnswer(ans,root->right,r + 1,rightCol,height);
        }
        return ;
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int height = findHeight(root) - 1;
        int rows = height + 1;
        int cols = pow(2,rows) - 1;
        vector<vector<string>> ans(rows,vector<string>(cols,""));
        computeAnswer(ans,root,0,(cols - 1)/2,height);
        return ans;
    }
};