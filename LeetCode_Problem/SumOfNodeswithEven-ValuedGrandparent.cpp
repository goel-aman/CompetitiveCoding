#include<bits/stdc++.h>
using namespace std;

// 1315. Sum of Nodes with Even-Valued Grandparent

// Given a binary tree, return the sum of values of nodes with 
// even-valued grandparent.
//   (A grandparent of a node is the parent of its parent, if it exists.)
// If there are no nodes with an even-valued grandparent, return 0.

// Example 1:
// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 18
// Explanation: The red nodes are the nodes with even-value grandparent while 
// the blue nodes are the even-value grandparents.
 
// Constraints:
// The number of nodes in the tree is between 1 and 10^4.
// The value of nodes is between 1 and 100.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int anss = 0;
public:
    int levelCalculator(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        // cout<<"Value of root is : "<<root->val<<endl;
        queue<TreeNode*> que;
        que.push(root);
        int level = 0;
        while(!que.empty()){
            int siz = que.size();
            // cout<<"size is : "<<siz<<endl;
            // cout<<"Value of level is : "<<level<<endl;
            while(siz--){
                TreeNode* front = que.front();
                que.pop();

                if(front->left != NULL){
                    que.push(front->left);
                }

                if(front->right != NULL){
                    que.push(front->right);
                }
            }
            level++;
            if(level == 2){
                break;
            }
        }
        int sum = 0;
        // cout<<"elements at level 2 are : "<<endl;
        while(!que.empty()){
            TreeNode* front = que.front();
            // cout<<front->val<<" ";
            sum += front->val;
            que.pop();
        }
        // cout<<endl;
        return sum;
    }

    void sumEvenGrandparenst(TreeNode* root) {
        if(root == NULL){
            return ;
        }
        
        int ans = 0;
        if(root->val%2 == 0){
            // cout<<"root is : "<<root->val<<endl;
            int tempValue = levelCalculator(root);
            // cout<<"level Calcuated value is : "<<tempValue<<endl;
            anss += tempValue;
        }   

        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);

        return ;
    }

    int sumEvenGrandparent(TreeNode* root){
        sumEvenGrandparenst(root);
        return anss;
    }
};