/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Codec {
public:

    // Encodes a tree to a single string.
    
    string preorder(TreeNode* root){
        if(root == NULL)
        {
            string r = "";
            return r;
        }
        
        string r = to_string(root->val);
        string left = preorder(root->left);
        if(left == ";"){
            left = "";
        }
        string right = preorder(root->right);
        if(right == ";")
        {
            right = "";
        }
        return (r + ";" + left + ";" + right);        
    }
    
    string serialize(TreeNode* root) {
        string ans = preorder(root);
        return ans;
    }
    
    TreeNode* getBST(vector<int> v,int start , int end){
        if(end - start < 0){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(v[start]);
        int index;
        for(int i = start + 1 ; i<= end ;i++){
            if(v[i] > v[start]){
                index = i - 1;
                break;
                
            }
            index = i;
        }
        root->left = getBST(v,start + 1, index);
        root->right = getBST(v,index + 1, end);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return NULL;
        }
        
        vector<int> v;
        string k="";
        string emp = "";
        string empty = ";";
        for(int i=0;i<data.length();i++){
            if(string(1,data[i]) == empty){
                if(k != empty && k != emp) {v.push_back(stoi(k)); } 
                k = "";
                continue;
            }
            k.push_back(data[i]);
        }
        TreeNode* ans = getBST(v,0,v.size() - 1);
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;