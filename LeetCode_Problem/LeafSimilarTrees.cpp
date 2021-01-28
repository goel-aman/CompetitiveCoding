// 872. Leaf-Similar Trees

// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.



// For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

// Two binary trees are considered leaf-similar if their leaf value sequence is the same.

// Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

// Example 1:


// Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
// Output: true
// Example 2:

// Input: root1 = [1], root2 = [1]
// Output: true
// Example 3:

// Input: root1 = [1], root2 = [2]
// Output: false
// Example 4:

// Input: root1 = [1,2], root2 = [2,2]
// Output: true
// Example 5:


// Input: root1 = [1,2,3], root2 = [1,3,2]
// Output: false
 

// Constraints:

// The number of nodes in each tree will be in the range [1, 200].
// Both of the given trees will have values in the range [0, 200].

#include<bits/stdc++.h>
using namespace std;
// * Definition for a binary tree node.
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
    void leafSimilar(TreeNode* root,vector<int> & v){
        if(root == NULL){
            return;
        }

        if(root->left == NULL && root->right == NULL){
            v.push_back(root->val);
        }

        if(root->left != NULL){
            leafSimilar(root->left,v);
        }

        if(root->right != NULL){
            leafSimilar(root->right,v);
        }
        return ;
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if( (root1 == NULL) && (root2 == NULL)){
            return true;
        }
        vector<int> firstTree;
        vector<int> secondTree;

        leafSimilar(root1,firstTree);
        leafSimilar(root2,secondTree);
        if(firstTree.size() != secondTree.size()){
            return false;
        }

        bool ans = true;
        for(int i=0;i<firstTree.size();i++){
            if(firstTree[i] != secondTree[i]){
                return false;
            }
        }
        return ans;
    }
};