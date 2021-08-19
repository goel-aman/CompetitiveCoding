#include<bits/stdc++.h>
using namespace std;

// 1339. Maximum Product of Splitted Binary Tree
// Given the root of a binary tree, split the binary tree
//  into two subtrees by removing one edge such that the 
// product of the sums of the subtrees is maximized.

// Return the maximum product of the sums of the two subtrees.
//  Since the answer may be too large, return it modulo 109 + 7.

// Note that you need to maximize the answer before taking the
//  mod and not after taking it.

// Example 1:
// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with
//  sum 11 and 10. Their product is 110 (11*10)

// Example 2:
// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with
//  sum 15 and 6.Their product is 90 (15*6)

// Example 3:
// Input: root = [2,3,9,10,7,8,6,5,4,11,1]
// Output: 1025

// Example 4:
// Input: root = [1,1]
// Output: 1
 
// Constraints:
// The number of nodes in the tree is in the range [2, 5 * 104].
// 1 <= Node.val <= 104

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    long long int mod = 1e9 + 7;
    unordered_map<TreeNode*,int> um;
    long long int ans = 0;
public:
    int findAllSum(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        long long int sum = 0;
        if(root->left != NULL){
            sum += findAllSum(root->left);
        }

        if(root->right != NULL){
            sum += findAllSum(root->right);
        }

        sum += root->val;
        um[root] = sum;
        return sum;
    }

    void solve(TreeNode* root,long long int previousSum){
        if(previousSum == -1){
            long long  int leftSum = 0, rightSum = 0;
            if(root->left != NULL){
                leftSum = um[root->left];
            }
            if(root->right != NULL){
                rightSum = um[root->right];
            }

            long long int first = ((long long int) root->val + rightSum) * leftSum;
            long long int second = (root->val + leftSum) * rightSum;
            ans = max({ans,first,second});
            
            // calling left tree it it exist
            if(root->left != NULL){
                solve(root->left,root->val + rightSum);       
            }

            if(root->right != NULL){
                solve(root->right,root->val + leftSum);
            }
            return ;
        }


        long long int currentSum = previousSum + root->val;
        long long int leftSum = 0, rightSum = 0;
        if(root->left != NULL){
            leftSum = um[root->left];
        }

        if(root->right != NULL){
            rightSum = um[root->right];
        }

        long long int first = leftSum * (currentSum + rightSum);
        long long int second = rightSum * (currentSum + leftSum);
        ans = max({ans,first,second});
        if(root->left != NULL){
            solve(root->left,currentSum + rightSum);
        }
        if(root->right != NULL){
            solve(root->right,currentSum + leftSum); 
        }
        return ;
    }

  
    int maxProduct(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int val = findAllSum(root);
        solve(root,-1);
        return ans%mod;
    }
};