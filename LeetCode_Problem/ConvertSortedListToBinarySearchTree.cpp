#include<bits/stdc++.h>
using namespace std;

// 109. Convert Sorted List to Binary Search Tree

// Given the head of a singly linked list where elements are sorted
//  in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary
//  tree in which the depth of the two subtrees of every node never 
// differ by more than 1.

// Example 1:
// Input: head = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: One possible answer is [0,-3,9,-10,null,5], which 
// represents the shown height balanced BST.

// Example 2:
// Input: head = []
// Output: []

// Example 3:
// Input: head = [0]
// Output: [0]

// Example 4:
// Input: head = [1,3]
// Output: [3,1]
 
// Constraints:
// The number of nodes in head is in the range [0, 2 * 104].
// -105 <= Node.val <= 105

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    TreeNode* formTree(vector<int>& vec,int start,int end){
        if(start > end){
            return NULL;
        }

        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = formTree(vec,start,mid - 1);
        root->right = formTree(vec,mid + 1,end);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL){
            return NULL;
        }      

        ListNode* temp = head;
        vector<int> vec;
        while(temp != NULL){
            vec.push_back(temp->val);
            temp = temp->next;
        }

        int start = 0;
        int end = vec.size() - 1;
        return formTree(vec,start,end);
    }
};