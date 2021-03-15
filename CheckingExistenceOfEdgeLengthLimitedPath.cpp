#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a ,vector<int> &b){
    if(a[2] < b[2]){
        return true;
    }
    return false;
}


class Solution {
    int * parent;

    int findParent(int inp){
        if(parent[inp] == inp){
            return inp;
        }

        return parent[inp] = findParent(parent[inp]);
    }

    void merge(int first,int second){
        int firstParent = findParent(first);
        int secondParent = findParent(second);
        if(firstParent != secondParent){
            parent[firstParent] = secondParent;
        }
        return;
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        parent = new int[n];
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),compare);
        sort(edgeList.begin(),edgeList.end(),compare);
        
        vector<bool> ret(queries.size());
        int i = 0;
        for(int j=0;j<queries.size();j++){
            for(;i<edgeList.size() && edgeList[i][2] < queries[j][2];i++){
                merge(edgeList[i][0],edgeList[i][1]);
            }
            if( findParent(queries[j][0]) == findParent(queries[j][1]) ){
                 ret[queries[j][3]] = true;;
            }else{
                ret[queries[j][3]] = false;
            }
        }
        return ret;
    }
};