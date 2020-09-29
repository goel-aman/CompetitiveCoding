#include<bits/stdc++.h>
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1){
            return 0;
        }
        int prod = 1;
        int result = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        while(right < n){
            prod *= nums[right];
            while(prod >= k ){
                prod = prod / nums[left];
                left++;
            }       
            if(prod < k){
                result += right - left + 1;
            }
            right++;
        }
        return result;
    }
};