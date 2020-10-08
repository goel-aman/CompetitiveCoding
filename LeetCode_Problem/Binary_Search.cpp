class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(),nums.end(),target);
        if(*it != target){
            return -1;
        }
        auto it2 = nums.begin();
        return (it - it2);
    }
};