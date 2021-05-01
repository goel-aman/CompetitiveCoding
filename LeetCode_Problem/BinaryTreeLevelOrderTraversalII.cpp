#include<bits/stdc++.h>
using namespace std;


// Given the root of a binary tree, return the bottom-up level order
//  traversal of its nodes' values. (i.e., from left to right, level
//  by level from leaf to root).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []
 
// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000


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
 

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(root == NULL){
            vector<vector<int>> ve;
            return ve;
        }
        stack<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int siz = q.size();
            vector<int> vec;
            while(siz > 0){
                TreeNode* front = q.front();
                q.pop();
                vec.push_back(front->val);
                if(root->left != NULL){
                    q.push(root->left);
                }

                if(root->right != NULL){
                    q.push(root->right);
                }
                siz--;
            }
            ans.push(vec);
        }
        vector<vector<int>> anss;
        while(!ans.empty()){
            anss.push_back(ans.top());
            ans.pop();
        }
        return anss;
    }
};