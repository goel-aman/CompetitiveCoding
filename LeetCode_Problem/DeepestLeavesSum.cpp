#include<bits/stdc++.h>
using namespace std;

// Given the root of a binary tree, return the sum of values
//  of its deepest leaves.
 
// Example 1:
// Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// Output: 15

// Example 2:
// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 19
 
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 100

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int,int> um;
    int maxValue;
public:
    void deepestLeaves(TreeNode* root,int level){
        if(root == NULL){
            return ;
        }
        
        um[level] += root->val;
        maxValue = max(maxValue,level);
        if(root->left != NULL){
            deepestLeaves(root->left,level + 1);
        }
        
        if(root->right != NULL){
            deepestLeaves(root->right,level + 1);
        }
        
        return ;
    }
    
    int deepestLeavesSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        deepestLeaves(root,0);
        
        return um[maxValue];
    }
};