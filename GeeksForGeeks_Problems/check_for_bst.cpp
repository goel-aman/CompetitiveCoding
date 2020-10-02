/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */

bool isbstutil(Node* root,int min,int max ){
    if(root == NULL){
        return 1;
    }
    if(root->data < min || root->data> max){
        return false;
    }
    return isbstutil(root->left,min,root->data-1)&& isbstutil(root->right,root->data+1,max);
}

bool isBST(Node* root) {
    // Your code here
    
    return isbstutil(root , INT_MIN,INT_MAX);
    }