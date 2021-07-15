#include<bits/stdc++.h>
using namespace std;

// 508. Most Frequent Subtree Sum
// Given the root of a binary tree, return the most frequent subtree sum.
//  If there is a tie, return all the values with the highest frequency 
// in any order.
// The subtree sum of a node is defined as the sum of all the node values 
// formed by the subtree rooted at that node (including the node itself).

// Example 1:
// Input: root = [5,2,-3]
// Output: [2,-3,4]

// Example 2:
// Input: root = [5,2,-5]
// Output: [2]
 
// Constraints:
// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<int,int> um;
    int freq = 0;
public:
    int findSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = 0,right = 0;
        if(root->left != NULL){
            left = findSum(root->left);
        } 

        if(root->right != NULL)
        {
            right = findSum(root->right);
        }

        int current = left + right + root->val;
        um[current]++;
        freq = max(um[current],freq);
        return current;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        int value = findSum(root);
        vector<int> vec;
        for(auto var : um){
            if(var.second == freq){
                vec.push_back(var.first);
            }
        }
        return vec;
    }
};