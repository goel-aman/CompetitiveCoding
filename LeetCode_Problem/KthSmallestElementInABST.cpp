#include<bits/stdc++.h>
using namespace std;
// 230. Kth Smallest Element in a BST

// Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

// Example 1:
// Input: root = [3,1,4,null,2], k = 1
// Output: 1

// Example 2:
// Input: root = [5,3,6,2,4,null,null,1], k = 3
// Output: 3
 
// Constraints:
// The number of nodes in the tree is n.
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
 
// Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and 
// you need to find the kth smallest frequently, how would you optimize?

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int val;
    int needed;
    int ans;
public:
    void inorder(TreeNode* root){
        if(root == NULL){
            return ;
        }
        
        if(root->left != NULL){
            inorder(root->left);
        }
        
        val++;
        if(val == needed){
            ans = root->val;
        }
        
        if(root->right != NULL){
            inorder(root->right);
        }
        
        return ;
    }
    
    int kthSmallest(TreeNode* root, int k) {
        val = 0;
        needed = k;
        inorder(root);
        return ans;
    }
};