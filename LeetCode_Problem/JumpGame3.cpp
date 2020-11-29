#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool answer(vector<int>& arr,int index,bool visited[],int &arr_length){
        if(arr[index] == 0){
            return true;
        }

        if(index >= arr_length || index < 0){
            return false;
        }

        visited[index] = true;
        if(index + arr[index] < arr_length && !visited[index + arr[index]]){
            bool anss = answer(arr,index + arr[index],visited,arr_length);
            if(anss){
                return true;
            }
        }

        if(index - arr[index] >= 0 && !visited[index - arr[index]]){
            bool anss = answer(arr,index - arr[index],visited,arr_length);
            if(anss){
                return true;
            }
        }
        return false;
    }

    bool canReach(vector<int>& arr, int start) {
        int arr_length = arr.size();
        bool visited[arr_length];
        memset(visited,0,sizeof(visited));
        bool ans = answer(arr,start,visited,arr_length);
        return ans;
    }
};