#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int getMaxLen(vector<int>& nums,int s,int e){
        if(s < e){
            return 0;
        }
        if(s == e){
            if(nums[s] > 0){
                return 1;
            }
        }
        int flag = 1;
        for(int i=s;i<=e;i++){
            if(nums[i] <= 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            return (e - s + 1);
        }
        int flag2 = 1;
        int maxx = 0;
        for(int i=s;i<=e;i++){
            if(nums[i] == 0){
                flag2 = 0;
                int x = getMaxLen(nums,s,i - 1);
                int y = getMaxLen(nums,i+1,e);
                maxx = max(x,y);
                break;
            }
        }
        if(flag2 == 0){
            return maxx;
        }
        int negative_count = 0;
        for(int i=s;i<=e;i++){
            if(nums[i] < 0){
                negative_count++;
            }
        }
        if(negative_count%2 == 0)
        {
            return (e - s + 1);
        }
        int i = s;
        for(i=s;i<=e;i++){
            if(nums[i] < 0){
                i+1;
                break;
            }
        }
        int a = (e - i + 1);
        int i=e;
        for(i = e;i>=s;i--){
            if(nums[i] < 0){
                i - 1;
                break;
            }
        }
        int b = (i - s + 1);
        return max(b,a);

    }

    int getMaxLen(vector<int>& nums) {
        return getMaxLen(nums,0,nums.size() - 1);
    }

    
};