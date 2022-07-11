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
    map<int,vector<int>> traversal;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        queue<pair<TreeNode*,int>> que;
        que.push({root,0});
        while(!que.empty()){
            pair<TreeNode*,int> front = que.front();
            que.pop();
            // cout<<"node value is: "<<front.first->val;
            traversal[front.second].push_back(front.first->val);

            if(front.first->left != NULL){
                que.push({front.first->left,front.second - 1});
            }

            if(front.first->right != NULL){
                que.push({front.first->right,front.second + 1});
            }
        }

        for(auto var : traversal){
            ans.push_back(var.second);
        }
        return ans;
    }
};