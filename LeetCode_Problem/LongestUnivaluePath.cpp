#include<bits/stdc++.h>
using namespace std;

// 687. Longest Univalue Path
// Given the root of a binary tree, return the length of the
//  longest path, where each node in the path has the same 
// value. This path may or may not pass through the root.
// The length of the path between two nodes is represented by
//  the number of edges between them.

// Example 1:
// Input: root = [5,4,5,1,1,5]
// Output: 2

// Example 2:
// Input: root = [1,4,5,4,4,5]
// Output: 2
 
// Constraints:
// The number of nodes in the tree is in the range [0, 104].
// -1000 <= Node.val <= 1000
// The depth of the tree will not exceed 1000.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans = 0;
public:

    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = solve(root->left);
        int right = solve(root->right);
        int leftTree = 0, rightTree = 0;
        if(root->left != NULL && root->left->val == root->val){
            left += 1;
        }

        if(root->right != NULL && root->right->val == root->val){
            right += 1;
        }

        ans = max(ans,left+ right);
        return max(left,right);
    }

    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        int val = solve(root);
        return ans;
    }
};

