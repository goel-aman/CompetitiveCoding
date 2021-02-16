#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class TreeNode{
    public:
    int node;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        node = 0;
        left = NULL;
        right = NULL;
    }
};

TreeNode* FromTree(ll * a,ll start,ll end){
    if(start > end){
        return NULL;
    }


    if(start == end){
        TreeNode* val = new TreeNode();
        val->node = a[start];
        val->left = NULL;
        val->right = NULL;
        return val;
    }

    ll maxValue = INT_MIN;
    ll index;
    for(ll i=start;i<=end;i++){
        if(a[i] > maxValue){
            maxValue = a[i];
            index = i; 
        } 
    }

    TreeNode* rt = new TreeNode();
    rt->node = a[index];
    rt->left = FromTree(a,start, index - 1);
    rt->right = FromTree(a,index + 1,end);
    return rt;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        TreeNode* root = FromTree(a,0,n - 1);
        queue<TreeNode*> q;
        q.push(root);
        vector<int> visited(n + 1,-1);
        visited[root->node] = 0;
        ll level = 0;
        while(!q.empty()){
            level++;
            ll len = q.size();
            while(len--){
                TreeNode* front = q.front();
                q.pop();
                
                if(front->left != NULL && visited[front->left->node] == -1){
                    visited[front->left->node] = level;
                    q.push(front->left);
                }

                if(front->right != NULL && visited[front->right->node] == -1){
                    visited[front->right->node] = level;
                    q.push(front->right);
                }
            }
        }

        for(ll i=0;i<n;i++){
            cout<<visited[a[i]]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}