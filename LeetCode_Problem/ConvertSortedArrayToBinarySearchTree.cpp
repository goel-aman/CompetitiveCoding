// 108. Convert Sorted Array to Binary Search Tree
// 

// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth 
// of the two subtrees of every node never differ by more than 1.

// Example:

// Given the sorted array: [-10,-3,0,5,9],

// One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

//       0
//      / \
//    -3   9
//    /   /
//  -10  5
//  Definition for a binary tree node.
#include<bits/stdc++.h>
using namespace std;


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
    
    TreeNode* sortedArrayToBST(vector<int>& nums,int start,int end){
        int length = end - start + 1;
        if(length <= 0){
            return NULL;
        }
        
        if(length == 1){
            TreeNode* temp = new TreeNode();
            temp->val = nums[start];
            return temp;
        }
        
        int mid = (start + end) / 2;
        TreeNode* temp = new TreeNode();
        temp->val = nums[mid];
        temp->left = sortedArrayToBST(nums,start,mid - 1);
        temp->right = sortedArrayToBST(nums,mid + 1,end);
        return temp;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
        if(length == 0){
            return NULL;
        }
        
        return sortedArrayToBST(nums,0,length - 1);
    }
};