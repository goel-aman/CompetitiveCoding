#include<bits/stdc++.h>
using namespace std;

// 1382. Balance a Binary Search Tree
// Given a binary search tree, return a balanced binary search tree with the same node values.
// A binary search tree is balanced if and only if the depth of the two subtrees of 
// every node never differ by more than 1.
// If there is more than one answer, return any of them.

// Example 1:
// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2,null,null] is also correct.
 
// Constraints:
// The number of nodes in the tree is between 1 and 10^4.
// The tree nodes will have distinct values between 1 and 10^5.

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
    vector<int> treeValue;
    int n;
public:
    void traverse(TreeNode* root){
        if(root == NULL){
            return ;
        }

        if(root->left != NULL){
            traverse(root->left);
        }

        treeValue.push_back(root->val);

        if(root->right != NULL){
            traverse(root->right);
        }

        return ;
    }

    TreeNode* giveBalanced(int startIndex,int endIndex){
        if(startIndex == endIndex){
            TreeNode* r = new TreeNode();
            r->val = treeValue[startIndex];
            return r;
        }

        if(startIndex > endIndex){
            return NULL;
        }

        int mid = (startIndex + endIndex)/2;
        TreeNode* rt = new TreeNode();
        rt->val = treeValue[mid];
        rt->left = giveBalanced(startIndex,mid - 1);
        rt->right = giveBalanced(mid + 1,endIndex);
        return rt;
    }

    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        n = treeValue.size();
        int start = 0,end =  n - 1;
        TreeNode* ans = giveBalanced(0,end);
        return ans;
    }
};