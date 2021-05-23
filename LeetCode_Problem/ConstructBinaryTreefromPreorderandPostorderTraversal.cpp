#include<bits/stdc++.h>
using namespace std;

// 889. Construct Binary Tree from Preorder and Postorder Traversal
// Return any binary tree that matches the given 
// preorder and postorder traversals.
// Values in the traversals pre and post are distinct
//  positive integers.

// Example 1:
// Input: pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
// Output: [1,2,3,4,5,6,7]
 
// Note:
// 1 <= pre.length == post.length <= 30
// pre[] and post[] are both permutations of 1, 2, ..., pre.length.
// It is guaranteed an answer exists. If there exists multiple answers,
//  you can return any of them.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int length;
public:
    TreeNode* construct(vector<int>& pre,int preStart,int preEnd,vector<int>& post,int postStart,int postEnd){
        if(preStart > preEnd || postStart > postEnd){
            return NULL;
        }
        
        if(preStart == preEnd){
            TreeNode* newNode = new TreeNode(pre[preStart]);
            return newNode;
        }

        TreeNode* newNode = new TreeNode(pre[preStart]);
        int value = pre[preStart + 1];
        int index;
        for(int i=postStart;i<length;i++){
            if(value == post[i]){
                index = i;
            }
        }

        newNode->left = construct(pre,preStart + 1,preStart + 1 + (index - postStart),post,postStart,index);
        newNode->right = construct(pre,preStart + 1 + (index - postStart) + 1,preEnd,post,index + 1,postEnd);
        return newNode;
    }
    
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        length = pre.size();
        return construct(pre,0,length - 1,post,0,length -1);
    }
};