#include<bits/stdc++.h>
using namespace std;

// 272. Closest Binary Search Tree Value II
// Given the root of a binary search tree, a target value,
// and an integer k, return the k values in the BST that 
// are closest to the target. You may return the answer in
//  any order.
// You are guaranteed to have only one unique set of k values
//  in the BST that are closest to the target.

// Example 1:
// Input: root = [4,2,5,1,3], target = 3.714286, k = 2
// Output: [4,3]

// Example 2:
// Input: root = [1], target = 0.000000, k = 1
// Output: [1]
 
// Constraints:
// The number of nodes in the tree is n.
// 1 <= k <= n <= 104.
// 0 <= Node.val <= 109
// -109 <= target <= 109
 
// Follow up: Assume that the BST is balanced. Could you solve it in 
// less than O(n) runtime (where n = total nodes)?

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */



class Solution {
    vector<int> numbers;
public:
    void traverse(TreeNode* root){
        if(root == NULL){
            return ;
        }

        if(root->left != NULL){
            traverse(root->left);
        }

        numbers.push_back(root->val);

        if(root->right != NULL){
            traverse(root->right);
        }

        return ;
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        int value = (int) target;

        traverse(root);
        int numbersLength = numbers.size();
        int secondIndex = lower_bound(numbers.begin(),numbers.end(),value + 1) - numbers.begin();
        int firstIndex = secondIndex - 1;
        
        vector<int> ans;
        if(secondIndex == numbersLength){
            while(k > 0){
                ans.push_back(numbers[firstIndex]);
                firstIndex--;
                k--;
            }
            return ans;
        }

        if(firstIndex == -1){
            while(k > 0){
                ans.push_back(numbers[secondIndex]);
                secondIndex++;
                k--;
            }
            return ans;
        }

        while(k > 0){
            double firstValue = (double) INT_MAX;
            double secondValue = (double) INT_MAX;

            if(firstIndex >= 0 && firstIndex < numbersLength){
                firstValue = abs(target - numbers[firstIndex]);
            }

            if(secondIndex >= 0 && secondIndex < numbersLength){
                secondValue = abs(target - numbers[secondIndex]);
            }

            if(firstValue < secondValue){
                ans.push_back(numbers[firstIndex]);
                firstIndex--;
            }else{
                ans.push_back(numbers[secondIndex]);
                secondIndex++;
            }
            k--;
        }
        return ans;
    }

};