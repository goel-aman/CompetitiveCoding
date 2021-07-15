#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int numsLength = nums.size();
        for(int i=0;i<=numsLength - 3;i++){
            int end = numsLength - 1;
            while(end > i + 1){
                int s = i + 1;
                int e = end - 1;
                int value = 0;
                while(s <= e)
                {
                    int mid = (s + e)/2;
                    if(nums[i] + nums[mid] > nums[end]){
                        int temp = end - mid;
                        value = temp;
                        e = mid - 1;
                    }
                    else{
                        s = mid + 1;
                    }
                }
                ans += value;
                end--;
            }
        }
        return ans;
    }
};