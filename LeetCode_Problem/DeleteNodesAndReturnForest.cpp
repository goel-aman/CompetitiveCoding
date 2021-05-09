#include<bits/stdc++.h>
using namespace std;

// 1110. Delete Nodes And Return Forest

// Given the root of a binary tree, each node in the 
// tree has a distinct value.
// After deleting all nodes with a value in to_delete, we are left 
// with a forest (a disjoint union of trees).
// Return the roots of the trees in the remaining forest. 
// You may return the result in any order.

// Example 1:
// Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
// Output: [[1,2,null,4],[6],[7]]

// Example 2:
// Input: root = [1,2,4,null,3], to_delete = [3]
// Output: [[1,2,4]]
 
// Constraints:
// The number of nodes in the given tree is at most 1000.
// Each node has a distinct value between 1 and 1000.
// to_delete.length <= 1000
// to_delete contains distinct values between 1 and 1000.

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
    TreeNode* DeleteNodes(TreeNode* root,unordered_set<int> &toBeDeleted,vector<TreeNode*> &ans,bool isRoot){
        if(root == NULL){ return NULL; }

        bool isThere = false;
        if(toBeDeleted.count(root->val) > 0){
            isThere = true;
        } 

        if(isRoot == true && isThere == false){
            ans.push_back(root);
            root->left = DeleteNodes(root->left,toBeDeleted,ans,false);
            root->right = DeleteNodes(root->right,toBeDeleted,ans,false);
            return root;
        }

        if(isRoot == true && isThere == true){
            DeleteNodes(root->left,toBeDeleted,ans,true);
            DeleteNodes(root->right,toBeDeleted,ans,true);
            return NULL;
        }

        if(isRoot == false && isThere == true){
            root->left = DeleteNodes(root->left,toBeDeleted,ans,true);
            root->right = DeleteNodes(root->right,toBeDeleted,ans,true);
            return NULL;
        }

        if(isRoot == false && isThere == false){
            root->left = DeleteNodes(root->left,toBeDeleted,ans,false);
            root->right = DeleteNodes(root->right,toBeDeleted,ans,false);
            return root;
        }

        return NULL;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del;
        for(auto element : to_delete){
            del.insert(element);
        }
        vector<TreeNode*> ans;
        DeleteNodes(root,del,ans,true);
        return ans;
    }
};