#include<bits/stdc++.h>
using namespace std;

// 124. Binary Tree Maximum Path Sum
// A path in a binary tree is a sequence of nodes where each
// pair of adjacent nodes in the sequence has an edge connecting 
// them. A node can only appear in the sequence at most once. Note 
// that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the
// path.

// Given the root of a binary tree, return the maximum path sum of
// any non-empty path.

// Example 1:
// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum 
// of 2 + 1 + 3 = 6.

// Example 2:
// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum
//  of 15 + 20 + 7 = 42.
 
// Constraints:
// The number of nodes in the tree is in the range [1, 3 * 104].
// -1000 <= Node.val <= 1000

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
    int ans = INT_MIN;
public:
    int maxPath(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int leftValue = maxPath(root->left);
        int rightValue = maxPath(root->right);
        
        ans = max(ans,leftValue + rightValue + root->val);
        
        int tempValue = max(root->val + leftValue,root->val + rightValue);
        tempValue = max(tempValue,root->val);
        ans = max(ans,tempValue);
        return tempValue;
    }
    
    int maxPathSum(TreeNode* root) {
        int value = maxPath(root);
        ans = max(ans,value);
        return ans;
    }
};