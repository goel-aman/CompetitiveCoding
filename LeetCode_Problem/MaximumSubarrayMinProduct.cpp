#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        long long int numsLength = nums.size();

        vector<long long int> leftBreak(numsLength),rightBreak(numsLength),prefix;

        stack<long long int> left;
        long long int sum = 0;
        for(long long int i=0;i<numsLength;i++){
            long long int number = nums[i];
            sum += number;
            prefix.push_back(sum);
            
            while(!left.empty() && nums[left.top()] >= number){
                left.pop();
            }

            if(left.empty()){
                left.push(i);
                leftBreak[i] = -1;
                continue;
            }

            leftBreak[i] = left.top();
            left.push(i);
        }

        stack<long long int> right;
        for(long long int i=numsLength - 1;i>=0;i--){
            long long int number = nums[i];

            while(!right.empty() && nums[right.top()] >= number){
                right.pop();
            }

            if(right.empty()){
                right.push(i);
                rightBreak[i] = numsLength;
                continue;
            }

            rightBreak[i] = right.top();
            right.push(i);
        }

        long long int ans = INT_MIN;
        for(long long int i=0;i<numsLength;i++){
            long long int rightIndex = rightBreak[i] - 1;
            long long int leftIndex = leftBreak[i];
            if(leftIndex == -1){
                ans = max(ans,prefix[rightIndex] * nums[i]);
                continue;
            }
            else{
                ans = max(ans, (prefix[rightIndex] - prefix[leftIndex]) * nums[i]);
            }
        }
        return ans%1000000007;
    }
};