#include<bits/stdc++.h>
using namespace std;

// 988. Smallest String Starting From Leaf

// Given the root of a binary tree, each node has a value from
//  0 to 25 representing the letters 'a' to 'z': a value of 0 
// represents 'a', a value of 1 represents 'b', and so on.
// Find the lexicographically smallest string that starts at
//  a leaf of this tree and ends at the root.
// (As a reminder, any shorter prefix of a string is lexicographically
//  smaller: for example, "ab" is lexicographically smaller than "aba". 
//  A leaf of a node is a node that has no children.)

// Example 1:
// Input: [0,1,2,3,4,3,4]
// Output: "dba"

// Example 2:
// Input: [25,1,3,1,3,0,2]
// Output: "adz"

// Example 3:
// Input: [2,2,1,null,1,0,null,0]
// Output: "abc"
 
// Note:
// The number of nodes in the given tree will be between 1 and 8500.
// Each node in the tree will have a value between 0 and 25.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    string ans = "aman";
public:
    void fromLeaf(TreeNode* root,string tillNow){
        if(root == NULL){
            return ;
        }

        if(root->left == NULL && root->right == NULL){
            char c = 'a' + root->val;
            tillNow = tillNow + c;
            reverse(tillNow.begin(),tillNow.end());
            if(ans == "aman"){
                ans = tillNow;
            }
            else{
                ans = min(ans,tillNow);
            }
            return ;
        }

        if(root->left != NULL){
            string temp = tillNow;
            char c = ('a' + root->val);
            temp = temp + c;
            fromLeaf(root->left,temp);
        }

        if(root->right != NULL){
            string temp = tillNow;
            char c = ('a' + root->val);
            temp = temp + c;
            fromLeaf(root->right,temp);
        }
        return ;
    }

    string smallestFromLeaf(TreeNode* root) {
        fromLeaf(root,"");
        return ans;
    }
};