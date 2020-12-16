// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Example 1:


// Input: root = [2,1,3]
// Output: true
// Example 2:


// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
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
    int min_element;
    int max_element;
    bool isBst;
};

class Solution {
public:

    element isValid(TreeNode* root){
        if(root == NULL){
            element ele;
            ele.isBst = true;
            ele.max_element = INT_MIN;
            ele.min_element = INT_MAX;
            return ele;
        }

        if(root->left == NULL && root->right == NULL){
            element ele;
            ele.isBst = true;
            ele.max_element = root->val;
            ele.min_element = root->val;
            return ele;
        }
        
        if(root->left == NULL && root->right != NULL){
            element ele;
            element elem = isValid(root->right);
            if(root->val < elem.min_element && elem.isBst) {
                ele.isBst = true;
                ele.max_element = max(root->val,elem.max_element);
                ele.min_element = min(root->val,elem.min_element);
                return ele;
            }else{
                ele.isBst = false;
                ele.max_element = INT_MIN;
                ele.min_element = INT_MAX;
                return ele;
            }
        }
        
        if(root->left != NULL && root->right == NULL){
            element ele;
            element elem = isValid(root->left);
            if(root->val > elem.max_element && elem.isBst){
                ele.isBst = true;
                ele.max_element = max(root->val,elem.max_element);
                ele.min_element = min(root->val,elem.min_element);
                return ele;
            }else{
                ele.isBst = false;
                ele.max_element = INT_MIN;
                ele.min_element = INT_MAX;
                return ele;
            }
        }

        element right = isValid(root->right);
        element left = isValid(root->left);
        if(right.isBst && left.isBst){
            if(root->val > left.max_element && root->val < right.min_element){
                element ret;
                ret.max_element = max(root->val,max(left.max_element,right.max_element));
                ret.min_element = min(root->val,min(right.min_element,left.min_element));
                ret.isBst = true;
                return ret;
            }
        }

        element ret;
        ret.isBst = false;
        ret.max_element = INT_MIN;
        ret.min_element = INT_MAX ;
        return ret;
    }

    bool isValidBST(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }

        element elem = isValid(root);
        if(elem.isBst)
        {
            return true;
        }
        return false;
    }
};