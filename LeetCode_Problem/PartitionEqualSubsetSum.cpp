#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ans(vector<int> &nums,int current_value,int index,int &ans){
        if(current_value == ans){
            return true;
        }

        bool ans1 = ans(nums,current_value + nums[index],index + 1,ans);
        bool ans2 = ans(nums,current_value,index + 1, ans);

        if(ans1 && ans2)
        {
            return true;
        }
        return false;
    }

    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        for(auto k : nums){
            totalsum += k;
        }
        if(totalsum%2 != 0){
            return false;
        }
        int ans = totalsum / 2;
        int index = 0;
        if(ans(nums,0,index,ans)){
            return true;
        }
        return false;
    }
};