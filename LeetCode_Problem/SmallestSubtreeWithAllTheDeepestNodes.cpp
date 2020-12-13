// Given the root of a binary tree, the depth of each node is the shortest distance to the root.

// Return the smallest subtree such that it contains all the deepest nodes in the original tree.

// A node is called the deepest if it has the largest depth possible among any node in the entire tree.

// The subtree of a n  ode is tree consisting of that node, plus the set of all descendants of that node.

// Note: This question is the same as 1123: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation: We return the node with value 2, colored in yellow in the diagram.
// The nodes coloured in blue are the deepest nodes of the tree.
// Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.
// Example 2:

// Input: root = [1]
// Output: [1]
// Explanation: The root is the deepest node in the tree.
// Example 3:

// Input: root = [0,1,3,null,2]
// Output: [2]
// Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.
 

// Constraints:

// The number of nodes in the tree will be in the range [1, 500].
// 0 <= Node.val <= 500
// The values of the nodes in the tree are unique.


#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<TreeNode*,TreeNode*> um;
    vector<TreeNode*> v;
public:
    int Find_Max_Depth(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int ans1 = INT_MIN;
        int ans2 = INT_MIN;
        um[root->left] = root;
        um[root->right] = root;
        ans1 = Find_Max_Depth(root->left) + 1;
        ans2 = Find_Max_Depth(root->right) + 1;
        return max(ans1,ans2);
    }

    bool isOk(){
        if(v.size() == 1){
            return true;
        }
        TreeNode* temp = v[0];
        int length = v.size();
        for(int i=1;i<length;i++){
            if(temp != v[i]){
                return false;
            }
        }
        return true;
    }

    void findAllNodeAtDepth(int depth,TreeNode* root){
        if(root == NULL || depth == 0){
            // vector<TreeNode*> v;
            return ;
        }

        if(depth == 1){
            // vector<TreeNode*> v;
            v.push_back(root);
            return ;
        }

        findAllNodeAtDepth(depth - 1,root->left);
        findAllNodeAtDepth(depth - 1,root->right);
        return;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = Find_Max_Depth(root);
        if(maxDepth == 0){ 
            return root;
        }

        findAllNodeAtDepth(maxDepth,root);
        while(!isOk()){
            for(int i=0;i<v.size();i++){
                v[i] = um[v[i]];
            }
        }
        return v[0];
    }
};