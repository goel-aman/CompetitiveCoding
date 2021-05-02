#include<bits/stdc++.h>
using namespace std;

// 1305. All Elements in Two Binary Search Trees
// Given two binary search trees root1 and root2.
// Return a list containing all the integers from both
//  trees sorted in ascending order.

// Example 1:
// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]

// Example 2:
// Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
// Output: [-10,0,0,1,2,5,7,10]

// Example 3:
// Input: root1 = [], root2 = [5,1,7,0,2]
// Output: [0,1,2,5,7]

// Example 4:
// Input: root1 = [0,-10,10], root2 = []
// Output: [-10,0,10]

// Example 5:
// Input: root1 = [1,null,8], root2 = [8,1]
// Output: [1,1,8,8]
 
// Constraints:
// Each tree has at most 5000 nodes.
// Each node's value is between [-10^5, 10^5].

// /**
//  * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//  */

class Solution {
    vector<int> firstInorder;
    vector<int> secondInorder;
public:
    void getInorder(TreeNode* root,int array){
        if(root == NULL){
            return;
        }

        if(root->left != NULL){
            getInorder(root->left,array);
        }

        if(array == 1){
            firstInorder.push_back(root->val);       
        }

        if(array == 2){
            secondInorder.push_back(root->val);
        }

        if(root->right != NULL){
            getInorder(root->right,array);
        }
        return ;
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        getInorder(root1,1);
        getInorder(root2,2);
        int firstLength = firstInorder.size();
        int secondLength = secondInorder.size();
        int start = 0;
        int secondStart = 0;
        vector<int> ans;
        while(start < firstLength && secondStart < secondLength){
            if(firstInorder[start] <= secondInorder[secondStart]){
                ans.push_back(firstInorder[start]);
                start++;
                continue;
            }
            else{
                ans.push_back(secondInorder[secondStart]);
                secondStart++;
                continue;
            }
        }

        while(start < firstLength){
            ans.push_back(firstInorder[start]);
            start++;
        }

        while(secondStart < secondLength){
            ans.push_back(secondInorder[secondStart]);
            secondStart++;
        }
        return ans;
    }
};