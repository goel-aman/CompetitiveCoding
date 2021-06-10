#include<bits/stdc++.h>
using namespace std;

// Find Elements in a Contaminated Binary Tree

// Given a binary tree with the following rules:

// // root.val == 0
// If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
// If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
// Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

// Implement the FindElements class:

// FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
// bool find(int target) Returns true if the target value exists in the recovered binary tree.
 

// Example 1:


// Input
// ["FindElements","find","find"]
// [[[-1,null,-1]],[1],[2]]
// Output
// [null,false,true]
// Explanation
// FindElements findElements = new FindElements([-1,null,-1]); 
// findElements.find(1); // return False 
// findElements.find(2); // return True 
// Example 2:


// Input
// ["FindElements","find","find","find"]
// [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
// Output
// [null,true,true,false]
// Explanation
// FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
// findElements.find(1); // return True
// findElements.find(3); // return True
// findElements.find(5); // return False
// Example 3:


// Input
// ["FindElements","find","find","find","find"]
// [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
// Output
// [null,true,false,false,true]
// Explanation
// FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
// findElements.find(2); // return True
// findElements.find(3); // return False
// findElements.find(4); // return False
// findElements.find(5); // return True
 

// Constraints:

// TreeNode.val == -1
// The height of the binary tree is less than or equal to 20
// The total number of nodes is between [1, 104]
// Total calls of find() is between [1, 104]
// 0 <= target <= 106


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class FindElements {
    TreeNode* start;
    unordered_map<int,bool> um;
public:
    FindElements(TreeNode* root) {
        if(root == NULL){
            start = root;
            return ;
        }  
        root->val = 0;
        um[root->val] = true;
        start = correctIt(root);
        return ;
    }
    
    TreeNode* correctIt(TreeNode* root){
        if(root == NULL){
            return root;
        }

        int x = root->val;
        if(root->left != NULL){
            root->left->val = (2 * x + 1);
            // cout<<root->left->val<<endl;
            um[root->left->val] = true;
            root->left = correctIt(root->left);
        }

        if(root->right != NULL)
        {
            root->right->val = (2 * x + 2);
            // cout<<root->right->val<<endl;
            um[root->right->val] = true;
            root->right = correctIt(root->right);
        }
        return root;
    }

    bool find(int target) {
        if(um[target] == true){
            return true;
        }
        return false;
    }
};
