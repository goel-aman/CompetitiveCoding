#include<bits/stdc++.h>
using namespace std;

// 662. Maximum Width of Binary Tree
// Given the root of a binary tree, return the 
// maximum width of the given tree.
// The maximum width of a tree is the maximum
//  width among all levels.

// The width of one level is defined as the length
//  between the end-nodes (the leftmost and rightmost
//  non-null nodes), where the null nodes between the
//  end-nodes are also counted into the length calculation.
// It is guaranteed that the answer will in the range of
//  32-bit signed integer.

// Example 1:
// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width existing in the third 
// level with the length 4 (5,3,null,9).

// Example 2:
// Input: root = [1,3,null,5,3]
// Output: 2
// Explanation: The maximum width existing in the third
//  level with the length 2 (5,3).

// Example 3:
// Input: root = [1,3,2,5]
// Output: 2
// Explanation: The maximum width existing in the second 
// level with the length 2 (3,2).

// Example 4:
// Input: root = [1,3,2,5,null,null,9,6,null,null,7]
// Output: 8
// Explanation: The maximum width existing in the fourth 
// level with the length 8 (6,null,null,null,null,null,null,7).
 
// Constraints:
// The number of nodes in the tree is in the range [1, 3000].
// -100 <= Node.val <= 100

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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        queue<pair<TreeNode*,int>> que;
        que.push({root,0});
        int result = 1;
        while(!que.empty()){
            int startValue = que.front().second;
            int endValue = que.back().second;
            result = max(result,endValue - startValue + 1);
            int siz = que.size();
            while(siz--){
                pair<TreeNode*,int> front = que.front();
                if(front.first->left != NULL){
                    que.push({front.first->left,(front.second*2) - startValue});
                }

                if(front.first->right != NULL)
                {
                    que.push({front.first->right,(front.second*2) + 1 - startValue});
                }
            }          
        }
        return result;
    }
};