#include<bits/stdc++.h>
using namespace std;


// 652. Find Duplicate Subtrees
// Given the root of a binary tree, return all duplicate subtrees.
// For each kind of duplicate subtrees, you only need to return the
//  root node of any one of them.
// Two trees are duplicate if they have the same structure with the
//  same node values.

// Example 1:
// Input: root = [1,2,3,4,null,2,4,null,null,4]
// Output: [[2,4],[4]]

// Example 2:
// Input: root = [2,1,1]
// Output: [[1]]

// Example 3:
// Input: root = [2,2,2,3,null,3,null]
// Output: [[2,3],[3]]
 
// Constraints:
// The number of the nodes in the tree will be in the
//  range [1, 10^4]
// -200 <= Node.val <= 200

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<string,int> um;
    vector<TreeNode*> ans;
public:

    string solve(TreeNode* root){
        if(root == NULL){
            return "x";
        }

        string left = solve(root->left);
        string right = solve(root->right);
        string cur = to_string(root->val) + ";" + left + right;
        um[cur]++;
        if(um[cur] == 2){
            cout<<cur<<endl;
            ans.push_back(root);
        }
        return cur;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == NULL){
            return ans;    
        }
        string val = solve(root);
        return ans;
    }
};