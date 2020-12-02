#include<bits/stdc++.h>
using namespace std;
//3 3 5 0 0 3 1 4 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        int arr[length];
        int arr2[length];
        arr[0] = 0;
        int min_value = prices[0];
        for(int i=1;i<length;i++){
            if(prices[i] >= min_value){
                arr[i] = max(arr[i - 1],(prices[i] - min_value));
            }
            else{
                arr[i] = max(arr[i - 1],(prices[i] - min_value));
                min_value = prices[i];
            }
        }
        cout<<"Forward array is : "<<endl;
        for(int i=0;i<length;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        int max_value = prices[length - 1];
        arr2[length - 1] = 0;
        for(int i=length-2;i>=0;i--){
            if(prices[i] > max_value){
                arr2[i] = max(arr2[i + 1],max_value - prices[i]);
                max_value = prices[i];
            }
            else{
                // cout<<"Value of prices i is : "<<prices[i]<<endl;
                arr2[i] = max(arr2[i + 1],(max_value - prices[i]));
                // cout<<"Value of max_value - prices[i] is : "<<max_value - prices[i]<<endl;
                // cout<<"Value of max_value is : "<<max_value<<endl;
                // return 0;
            }
        }
        cout<<"Backward array is : "<<endl;
        for(int i=0;i<length;i++){
            cout<<arr2[i]<<" ";
        }
        cout<<endl;
        
        int ans = 0;
        for(int i=0;i<length - 2;i++){
            ans = max(ans,arr[i] + arr2[i + 1]);
        }
        ans = max(ans,arr[length - 1]);
        ans = max(ans,arr[0]);
        return ans;
    }
};