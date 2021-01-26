// 938. Range Sum of BST

// Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].

// Example 1:

// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Example 2:


// Input: root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// Output: 23
 

// Constraints:

// The number of nodes in the tree is in the range [1, 2 * 104].
// 1 <= Node.val <= 105
// 1 <= low <= high <= 105
// All Node.val are unique.

// Solution

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        queue<TreeNode*> q;
        if(root != NULL){
            q.push(root);
        }
        int ans = 0;
        while(!q.empty()){
            TreeNode* temp = q.front();
            if(temp == NULL){
                q.pop();
                continue;
            }
            q.pop();
            if(temp->val >= low && temp->val <= high){
                ans += temp->val;
                q.push(temp->left);
                q.push(temp->right);
                continue;
            }
            
            if(temp->val < low){
                q.push(temp->right);
                continue;
            }
            
            if(temp->val > high){
                q.push(temp->left);
                continue;
            }
        }
        return ans;
    }
};