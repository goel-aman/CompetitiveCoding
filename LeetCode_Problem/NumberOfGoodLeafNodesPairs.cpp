#include<bits/stdc++.h>
using namespace std;

// 1530. Number of Good Leaf Nodes Pairs
// Given the root of a binary tree and an integer distance.
//  A pair of two different
//  leaf nodes of a binary tree is said to be good if the 
// length of the shortest path 
// between them is less than or equal to distance.
// Return the number of good leaf node pairs in the tree.

// Example 1:
// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the 
// length of the shortest path between them is 3. This is the 
// only good pair.

// Example 2:
// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest
//  path = 2. The pair [4,6] is not good because the length of 
// ther shortest path between them is 4.

// Example 3:
// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
// Output: 1
// Explanation: The only good pair is [2,5].

// Example 4:
// Input: root = [100], distance = 1
// Output: 0

// Example 5:
// Input: root = [1,1,1], distance = 2
// Output: 1
 
// Constraints:
// The number of nodes in the tree is in the range [1, 2^10].
// Each node's value is between [1, 100].
// 1 <= distance <= 10

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int count;
    int distance;
public:
    vector<int> solve(TreeNode* root){
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        if(root->left == NULL && root->right == NULL){
            ans.push_back(0);
            return ans;
        }
        
        vector<int> left,right;
        if(root->left != NULL){
            left = solve(root->left);
        }
        
        if(root->right != NULL){
            right = solve(root->right);
        }

        for(auto var : left){
            int newVar = var + 1;
            if(newVar <= distance){
                ans.push_back(newVar);
            }
        }
        
        for(auto var : right){
            int newVar = var + 1;
            if(newVar <= distance){
                ans.push_back(newVar);
            }
        }
        
        for(auto var1 : left){
            for(auto var2 : right){
                if(var1 + var2 + 2 <= distance){
                    count++;
                }
            }
        }
        
        return ans;
    }
    
    int countPairs(TreeNode* root, int distance) {
        count = 0;
        this->distance = distance;
        vector<int> temp;
        temp = solve(root);
        return count;
    }
};