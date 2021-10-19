#include<bits/stdc++.h>
using namespace std;



class Solution {
    vector<int> ans;
    unordered_map<int,vector<int>> tree;
    string label;
public:
    void traverse(int root,vector<int> &um,int parent){
        if(tree[root].size() == 0){
            ans[root]++;
            um[label[root] - 'a']++;
            return ;
        }
        
        vector<int> globalUm(26,0);

        for(auto var : tree[root]){
            if(var != parent){
                vector<int> newum(26,0);
                traverse(var,newum,root);
                for(int i=0;i<26;i++){
                    globalUm[i] += newum[i];
                }
            }
        }

        ans[root] = globalUm[label[root] - 'a'] + 1;
        globalUm[label[root] - 'a']++;
        for(int var= 0;var<26;var++){
            um[var] += globalUm[var];
        }
        
        return ;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        label = labels;
        
        for(auto &var : edges){
            int parent = var[0];
            int child = var[1];
            tree[parent].push_back(child);
            tree[child].push_back(parent);
        }
        
        vector<int> um(26,0);
        traverse(0,um,-1);
        return ans;      
    }
};