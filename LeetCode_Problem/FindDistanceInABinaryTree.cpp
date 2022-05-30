#include<bits/stdc++.h>
using namespace std;

// 1740. Find Distance in a Binary Tree
// Given the root of a binary tree and two integers p and q, return 
// the distance between the nodes of value p and value q in the tree.
// The distance between two nodes is the number of edges on the path
// from one to the other.

// Example 1:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 0
// Output: 3
// Explanation: There are 3 edges between 5 and 0: 5-3-1-0.

// Example 2:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 7
// Output: 2
// Explanation: There are 2 edges between 5 and 7: 5-2-7.

// Example 3:
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 5
// Output: 0
// Explanation: The distance between a node and itself is 0.
 
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// 0 <= Node.val <= 109
// All Node.val are unique.
// p and q are values in the tree.

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
    TreeNode* findLca(TreeNode* root,int p,int q){
        if(root == NULL || root->val == p || root->val == q){
            return root;
        }
        
        TreeNode* left = findLca(root->left,p,q);
        TreeNode* right = findLca(root->right,p,q);
        
        if(left != NULL && right != NULL){
            return root;
        }
        
        return (left == NULL) ? right : left;
    }
    
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* lca = findLca(root,p,q);
        
        queue<TreeNode*> que;
        que.push(lca);
        cout<<" value of lca node is: "<<lca->val<<endl;
        int distanceOfP = -1,distanceOfQ = -1;
        int level = 0;
        while(!que.empty() && !(distanceOfP >= 0 && distanceOfQ >= 0)){
            int size = que.size();
            
            while(size--){
                TreeNode* front = que.front();
                que.pop();
                if(front->val == p){
                    distanceOfP = level;
                }
                
                if(front->val == q){
                    distanceOfQ = level;
                }
                
                if(front->left != NULL){
                    que.push(front->left);
                }
                
                if(front->right != NULL){
                    que.push(front->right);
                }
            }
            level++;
        }
        cout<<"distanceOfP is : "<<distanceOfP<<" and distance of Q is : "<<distanceOfQ<<endl;
        return (distanceOfP + distanceOfQ);
    }
};""