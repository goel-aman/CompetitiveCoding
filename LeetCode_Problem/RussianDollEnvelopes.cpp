#include<bits/stdc++.h>
using namespace std;

class element{
    public:
    int width;
    int height;
};


bool comp(element a,element b){
    if(a.width < b.width ){
        return true;
    }
    return false;
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int length = envelopes.size();
        element* arr = new element[length];
        // element arr[length];
        for(int i=0;i<length;i++){
            arr[i].width = envelopes[i][0];
            arr[i].height = envelopes[i][1];
        }
        sort(arr,arr + length,comp);
        for(int i=0;i<length;i++)
        {
            cout<<arr[i].width<<" "<<arr[i].height<<endl;
        }
        int * ans = new int[length];
        for(int i=0;i<length;i++){
            ans[i] = 1;
        }
        for(int i = 1;i<length;i++){
            int maxx = 0;
            for(int j=i - 1;j>=0;j--){
                if(arr[i].width > arr[j].width && arr[i].height > arr[j].height){
                    maxx = max(maxx,ans[j]);
                }
            }
            ans[i] += maxx;
        }
        cout<<"Answer array is : "<<endl;
        for(int i=0;i<length;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        int final_ans = 0;
        for(int i=0;i<length;i++){
            final_ans = max(ans[i],final_ans);
        }
        return final_ans;
    }
};