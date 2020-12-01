#include<bits/stdc++.h>
using namespace std;

class dsu{
    public:
    vector<int> par;
    void init(int n){
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    
    // parent of x 
    int get(int x){
        if(x == par[x])
        {
            return x;
        }
        return par[x] = get(par[x]);
    }

    void unit(int x,int y){
        x = get(x);
        y = get(y);
        if(x != y){
            par[x] = max(par[x],par[y]);
            par[y] = max(par[x],par[y]);
        }
    }
};


class element{
    public:
    int left;
    int right;
    int height;
};

bool comp(element a, element b){
    if(a.height > b.height){
        return true;
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int buildsize = buildings.size();
        element arr[buildsize];
        int max_right = 0;
        for(int i=0;i<buildsize;i++){
            arr[i].left = buildings[i][0];
            arr[i].right = buildings[i][1];
            arr[i].height = buildings[i][2];
            if(arr[i].right > max_right){
                max_right = arr[i].right;
            }
        }
        sort(arr,arr + buildsize,comp);
        cout<<"array in sorted order is : "<<endl;
        for(int i=0;i<buildsize;i++){
            cout<<arr[i].left<<' '<<arr[i].right<<" "<<arr[i].height<<endl;
        }
        cout<<"value of  max_right is : "<<max_right<<endl;
        dsu g;
        int * res = new int[max_right + 1];
        for(int i=0;i<=max_right;i++){
            res[i] = 0;
        }
        // memset(res,0,sizeof(res));
        g.init(max_right + 2);
        for(int i=0;i<buildsize;i++){
            int index = g.get(arr[i].left);
            while(index <= arr[i].right){
                res[index] = arr[i].height;
                g.unit(index ,index + 1);
                index = g.get(index);
            }
        }
        cout<<"result array is : ";
        for(int i=0;i<=max_right;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        int prev = res[max_right];
        vector<vector<int>> ans;
        ans.push_back({max_right,0});
        for(int i=max_right - 1;i>=0;i--){
            if(res[i] == prev){
                continue;
            }
            if(prev < res[i]){
                ans.push_back({i,prev});
                prev = res[i];
                continue;
            }
            ans.push_back({i + 1, prev});
            prev = res[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> v;
//     for(int i=0;i<n;i++){
//         int l,r,h;
//         cin>>l>>r>>h;
//         v.push_back({l,r,h});
//     }
//     Solution ans;
//     vector<vector<int>> vv = ans.getSkyline(v);
//     for(auto s : vv)
//     {
//         cout<<s[0]<<" "<<s[1]<<endl;
//     }
//     return 0;
// }