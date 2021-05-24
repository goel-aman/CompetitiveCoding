#include<bits/stdc++.h>
using namespace std;

// Given an integer n, return all the structurally unique BST's (binary search trees), 
// which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

// Example 1:
// Input: n = 3
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]

// Example 2:
// Input: n = 1
// Output: [[1]]
 
// Constraints:
// 1 <= n <= 8


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
    
    vector<TreeNode*> generateTree(int start,int end){
        vector<TreeNode*> ans;
        if(start > end){
            ans.push_back(NULL);
            return ans;
        }

        if(start == end){
            TreeNode* newNode = new TreeNode(start);
            ans.push_back(newNode);
            return ans;
        }

        for(int i=start;i<=end;i++){
            vector<TreeNode*> left = generateTree(start,i - 1);
            vector<TreeNode*> right = generateTree(i + 1,end);
            for(int j=0;j<left.size();j++){
                for(int k = 0;k<right.size();k++){
                    TreeNode* newNode = new TreeNode(i);
                    newNode->left = left[j];
                    newNode->right = right[k];
                    ans.push_back(newNode);
                }
            }
        }
        return ans;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        return generateTree(1,n);      
    }
};