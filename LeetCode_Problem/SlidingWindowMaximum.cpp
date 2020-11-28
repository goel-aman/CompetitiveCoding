class element{
    public:
    int value;
    int index;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k == 1){
            return nums;
        }
        deque<element> dq;
        int i;
        for(i=0;i<k;i++){
            element a;
            a.value = nums[i];
            a.index = i;
            if(dq.empty()){
                dq.push_back(a);    
            }
            else{
                while( !dq.empty() && a.value >= dq.back().value){
                    dq.pop_back();
                }
                dq.push_back(a);
            }
            
        }
        vector<int> ans;
        for(;i<nums.size();i++){
            ans.push_back(dq.front().value);
            while(dq.front().index <= i - k){
                dq.pop_front();
            }
            element a;
            a.value = nums[i];
            a.index = i;
            while(!dq.empty() &&  a.value >= dq.back().value){
                dq.pop_back();
            }
            dq.push_back(a);
        }
        ans.push_back(dq.front().value);
        return ans;
    }
};