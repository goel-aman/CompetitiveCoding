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
    int level(vector<vector<int>> &res,TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int currentLevel = max(level(res,root->left),level(res,root->right)) + 1;
        if(res.size() < currentLevel){
            vector<int> temp;
            res.push_back(temp);
        }
        
        res[currentLevel - 1].push_back(root->val);
        return currentLevel;
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        
        level(res,root);
        
        return res;
    }
};