#include<bits/stdc++.h>
using namespace std;

// Two Sum BSTs
// Given the roots of two binary search trees, root1 and root2, 
// return true if and only if there is a node in the first tree 
// and a node in the second tree whose values sum up to a given
//  integer target.

// Example 1:
// Input: root1 = [2,1,4], root2 = [1,0,3], target = 5
// Output: true
// Explanation: 2 and 3 sum up to 5.

// Example 2:
// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2], target = 18
// Output: false
 
// Constraints:
// The number of nodes in each tree is in the range [1, 5000].
// -109 <= Node.val, target <= 109

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void traverse(TreeNode* root,unordered_set<int> &isThere){
        if(root == NULL){
            return ;
        }
        
        isThere.insert(root->val);
        if(root->left != NULL){
            traverse(root->left,isThere);
        }
        
        if(root->right != NULL){
            traverse(root->right,isThere);
        }
        
        return ;
    }
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        unordered_set<int> first;
        unordered_set<int> second;
        
        traverse(root1,first);
        traverse(root2,second);
        
        for(auto var : first){
            int value = target - var;
            if(second.count(value)){
                return true;
            }
        }
        return false;
    }
};