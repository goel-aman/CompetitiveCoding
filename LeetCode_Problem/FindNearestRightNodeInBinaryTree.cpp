#include<bits/stdc++.h>
using namespace std;

// 1602. Find Nearest Right Node in Binary Tree
// Given the root of a binary tree and a node u in the
//  tree, return the nearest node on the same level that
//  is to the right of u, or return null if u is the 
// rightmost node in its level.

// Example 1:
// Input: root = [1,2,3,null,4,5,6], u = 4
// Output: 5
// Explanation: The nearest node on the same level to the right of node 4 is node 5.

// Example 2:
// Input: root = [3,null,4,2], u = 2
// Output: null
// Explanation: There are no nodes to the right of 2.

// Constraints:
// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 105
// All values in the tree are distinct.
// u is a node in the binary tree rooted at root.


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) 
{}};
 
class Solution {
    queue<TreeNode*> que;
    TreeNode* ans = NULL;
public:
    void traverse(TreeNode* root,TreeNode* u){
        if(root == NULL){
            return;
        }
        
        int next = 0;
        que.push(root);
        que.push(NULL);
        while(que.size() > 0){
            TreeNode* front = que.front();
            que.pop();
            if(next == 1){
                ans =  front;
                break;
            }
            
            if(front == u){
                next = 1;
            }
            
            if(front == NULL && que.size() == 0){
                break;
            }
            
            if(front == NULL){
                que.push(NULL);
                continue;
            }
            
            if(front->left != NULL){
                que.push(front->left);
            }
            
            if(front->right != NULL){
                que.push(front->right);
            }
        }
    }
    
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        traverse(root,u);
        return ans;
    }
};