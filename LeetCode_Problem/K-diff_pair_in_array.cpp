#include<bits/stdc++.h>

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size()
        int count = 0;
        set<string> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j] - nums[i] > k ){
                    break;
                }
                if(nums[j] - nums[i] == k){
                    string a;
                    a.push_back(to_string(nums[i]));
                    a.push_back(';')
                    a.push_back(to_string(nums[j]));
                    s.insert(a);
                }
            }
        }
        return s.size();
    }
};