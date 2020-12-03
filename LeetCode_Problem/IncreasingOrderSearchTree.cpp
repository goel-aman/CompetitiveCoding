#include<bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    void inorder(TreeNode* root,vector<int> &v){
        if(root == NULL){
            return ;
        }

        if(root->left != NULL){
            inorder(root->left,v);
        }

        v.push_back(root->val);

        if(root->right != NULL)
        {
            inorder(root->right,v);
        }
        return ;
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        if(v.size() == 0)
        {
            return NULL;
        }
        TreeNode* head = new TreeNode(v[0]);
        TreeNode* temp = head;
        for(int i=1;i<v.size();i++){
            temp->right = new TreeNode(v[i]);
            temp = temp->right;
        }
        return head;
    }
    
};