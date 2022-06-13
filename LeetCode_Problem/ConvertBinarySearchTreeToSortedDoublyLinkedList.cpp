#include<bits/stdc++.h>
using namespace std;

// 426. Convert Binary Search Tree to Sorted Doubly Linked List
// Convert a Binary Search Tree to a sorted Circular Doubly-Linked 
// List in place.

// You can think of the left and right pointers as synonymous to the
//  predecessor and successor pointers in a doubly-linked list. For a
//  circular doubly linked list, the predecessor of the first element 
// is the last element, and the successor of the last element is the
//  first element.

// We want to do the transformation in place. After the transformation,
//  the left pointer of the tree node should point to its predecessor,
// and the right pointer should point to its successor. You should return
//  the pointer to the smallest element of the linked list.

// Example 1:
// Input: root = [4,2,5,1,3]
// Output: [1,2,3,4,5]

// Explanation: The figure below shows the transformed BST. The solid line 
// indicates the successor relationship, while the dashed line means the 
// predecessor relationship.

// Example 2:
// Input: root = [2,1,3]
// Output: [1,2,3]
 
// Constraints:
// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000
// All the values of the tree are unique.

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    vector<Node*> array;
public:
    void traverse(Node* root){
        if(root == NULL){
            return ;
        }

        if(root->left != NULL){
            traverse(root->left);
        }

        array.push_back(root);

        if(root->right != NULL){
            traverse(root->right);
        }
    }

    Node* treeToDoublyList(Node* root) {      
        if(root == NULL){
            return NULL;
        }

        array.clear();
        traverse(root);
        int arrayLength = array.size();
        
        if(arrayLength == 1){
            array[0]->left = array[0];
            array[0]->right = array[0];
            return array[0];
        }

        for(int i=0;i<arrayLength;i++){
            if(i == 0){
                array[i]->left = array[arrayLength - 1];
                array[i]->right = array[i + 1];
                continue;
            }
            else if(i == arrayLength - 1){
                array[i]->right = array[0];
                array[i]->left = array[i - 1];
                continue;
            }else{
                array[i]->right = array[i + 1];
                array[i]->left = array[i - 1];
            }
        }
        return array[0];
    }
};