#include<bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<int>> mem;
    bool anss(vector<int> &nums,int sum,int index,int siz){
        if(sum == 0){
            return true;
        }
        
        if(sum < 0){
            return false;
        }
        
        if(index == siz){
            if(sum == 0){
                return true;
            }
            return false;
        }
        
        if(mem[sum][index] != -1){
            return mem[sum][index];
        }
        

        bool ans1 = anss(nums,sum - nums[index],index + 1,siz);
        bool ans2 = anss(nums,sum,index + 1,siz);

        if(ans1 || ans2)
        {
            mem[sum][index] = 1;
            return true;
        }
        mem[sum][index] = 0;
        return false;
    }
public:
    

    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(auto k : nums){
            totalsum += k;
        }
        
        int siz = nums.size();
        
        if(totalsum%2 != 0){
            return false;
        }
        int ans = totalsum / 2;
        mem.clear();
        mem.resize(ans+ 1, vector<int>(siz, -1));
        if(anss(nums,ans,0,siz)){
            return true;
        }
        return false;
    }
};