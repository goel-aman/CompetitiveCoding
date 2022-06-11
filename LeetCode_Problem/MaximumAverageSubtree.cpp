#include<bits/stdc++.h>
using namespace std;

// 1120. Maximum Average Subtree
// Given the root of a binary tree, return the maximum 
// average value of a subtree of that tree. Answers within 
// 10-5 of the actual answer will be accepted.

// A subtree of a tree is any node of that tree plus all 
// its descendants.

// The average value of a tree is the sum of its values,
//  divided by the number of nodes.

// Example 1:
// Input: root = [5,6,1]
// Output: 6.00000
// Explanation: 
// For the node with value = 5 we have an average of (5 + 6 + 1) / 3 = 4.
// For the node with value = 6 we have an average of 6 / 1 = 6.
// For the node with value = 1 we have an average of 1 / 1 = 1.
// So the answer is 6 which is the maximum.

// Example 2:
// Input: root = [0,null,1]
// Output: 1.00000
 
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 105

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
    int numberOfNodes = 0;
    int sum = 0;
};

class Solution {
    double ans = 0;
public:
    element traverse(TreeNode *root){
        if(root == NULL){
            element temp;
            return temp;
        }
        
        element left,right;
        if(root->left != NULL){
            left = traverse(root->left);
        }
        
        if(root->right != NULL){
            right = traverse(root->right);
        }
        
        element ret;
        ret.sum = left.sum + right.sum + root->val;
        ret.numberOfNodes = left.numberOfNodes + right.numberOfNodes + 1;
        
        double temp = (double) ret.sum / double(ret.numberOfNodes);
        ans = max(ans,temp);
        return ret;
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        traverse(root);
        return ans;
    }
};