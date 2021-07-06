#include<bits/stdc++.h>
using namespace std;

// 437. Path Sum III
// Given the root of a binary tree and an integer targetSum,
//  return the number of paths where the sum of the values 
// along the path equals targetSum.
// The path does not need to start or end at the root or a 
// leaf, but it must go downwards (i.e., traveling only from 
// parent nodes to child nodes).

// Example 1:
// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.

// Example 2:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: 3

// Constraints:
// The number of nodes in the tree is in the range [0, 1000].
// -109 <= Node.val <= 109
// -1000 <= targetSum <= 1000

// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
    int target;
    unordered_map<TreeNode*,int> um;
public:
    
    int pathSumm(TreeNode* root, int targetSum,bool intermediate) {
        if(root == NULL){
            if(targetSum == 0){
                return 0;
            }
            return 0;
        }

        if(targetSum == target && um.count(root) > 0 && intermediate == false){
            return 0;
        }
        
        bool isPossible = false;
        if(targetSum == target && intermediate == false){
            isPossible = true;
        }

        int left = 0, right = 0;
        // first possibility that i am included in the answer
        int res = 0;
        if(targetSum - root->val == 0){
            res++;
        }

        left = pathSumm(root->left,targetSum - root->val,true);
        right = pathSumm(root->right,targetSum - root->val,true);  

        
        

        int leftt = 0, rightt = 0;
        // if i am not included
        leftt = pathSumm(root->left,target,false);
        rightt = pathSumm(root->right,target,false);
        if(isPossible == true){
            um[root] = res + left + leftt + right + rightt;
        }
        return left + res + leftt + right + rightt;
    }

    int pathSum(TreeNode* root,int targetSum){
        target = targetSum;
        return pathSumm(root,targetSum,false);
    }

};