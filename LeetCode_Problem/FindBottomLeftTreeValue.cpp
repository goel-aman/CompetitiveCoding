#include<bits/stdc++.h>
using namespace std;

// 513. Find Bottom Left Tree Value
// Given the root of a binary tree, return the leftmost
//  value in the last row of the tree.

// Example 1:
// Input: root = [2,1,3]
// Output: 1

// Example 2:
// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7
 
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

// /**
//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//  */

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        // vector<vector<int>> levelOrder;
        int ans = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int siz = que.size();
            vector<int> level;
            while(siz--){
                TreeNode* front = que.front();
                que.pop();
                level.push_back(front->val);
                if(front->left != NULL){
                    que.push(front->left);
                }                
                
                if(front->right != NULL){
                    que.push(front->right);
                }
            }
            if(que.size() == 0){
                ans = level[0];
            }
            // levelOrder.push_back(level);
        }
        return ans;
    }
};