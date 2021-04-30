#include<bits/stdc++.h>
using namespace std;

// 863. All Nodes Distance K in Binary Tree


// We are given a binary tree (with root node root), a target node, and an integer value K.

// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

// Output: [7,4,1]

// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.



// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.
 

// Note:

// The given tree is non-empty.
// Each node in the tree has unique values 0 <= node.val <= 500.
// The target node is a node in the tree.
// 0 <= K <= 1000.



//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
    unordered_map<TreeNode*,unordered_set<TreeNode*>> um;
public:
    void iterateTree(TreeNode* root){
        if(root == NULL){
            return ;
        }

        if(root->left != NULL){
            um[root].insert(root->left);
            um[root->left].insert(root);
            iterateTree(root->left);
        }

        if(root->right != NULL){
            um[root].insert(root->right);
            um[root->right].insert(root);
            iterateTree(root->right);
        }
        return;
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if(K == 0){
            vector<int> ans;
            ans.push_back(target->val);
            return ans;
        }
        unordered_map<TreeNode*,bool> visited;
        vector<int> ans;
        iterateTree(root);
        visited[target] = true;
        queue<TreeNode*> q;
        q.push(target);
        int level = 0;
        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                TreeNode* front = q.front();
                q.pop();
                for(TreeNode* x : um[front]){
                    if(!visited.count(x)){
                        visited[x] = true;
                        q.push(x);
                    }
                }
            }
            level++;
            if(level == K){
                break;
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }

};