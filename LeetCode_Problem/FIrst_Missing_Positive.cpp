class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        long long int length = nums.size();
        long long int value= length + 1;
        for(long long int i =0;i<length;i++){
            if(nums[i] < 1 || nums[i] > length){
                nums[i] = value;
            }
        } 

        for(long long int i = 0;i<length;i++){
            long long int val = abs(nums[i]) - 1;
            if (val >= 0 && val < length){
                nums[val] = (nums[val] > 0) ? (-nums[val]) :(nums[val]);
            }
        }

        long long int ans = INT_MIN;
        for(long long int i =0;i<length;i++){
            if(nums[i] > 0){
                ans = i + 1;
                break;
            }
        }
        if(ans != INT_MIN){
            return ans;
        }
        return value;
    }
};