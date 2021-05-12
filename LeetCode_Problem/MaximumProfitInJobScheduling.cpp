#include<bits/stdc++.h>
using namespace std;

// Maximum Profit in Job Scheduling

// We have n jobs, where every job is scheduled to be done from 
// startTime[i] to endTime[i], obtaining a profit of profit[i].

// You're given the startTime, endTime and profit arrays, return
//  the maximum profit you can take such that there are no two jobs
//  in the subset with overlapping time range.

// If you choose a job that ends at time X you will be able to
//  start another job that starts at time X.

// Example 1:
// Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
// Output: 120
// Explanation: The subset chosen is the first and fourth job. 
// Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

// Example 2:
// Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
// Output: 150
// Explanation: The subset chosen is the first, fourth and fifth job. 
// Profit obtained 150 = 20 + 70 + 60.

// Example 3:
// Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
// Output: 6

// Constraints:
// 1 <= startTime.length == endTime.length == profit.length <= 5 * 104
// 1 <= startTime[i] < endTime[i] <= 109
// 1 <= profit[i] <= 104

class element{
    public:
    int startTime;
    int endTime;
    int profit;
};

bool compare(element &a,element &b){
    if(a.endTime < b.endTime){
        return true;
    }

    return false;
}


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int siz = profit.size();
        int length = startTime.size();
        vector<element> vec;
        for(int i=0;i<length;i++){
            vec.push_back({startTime[i],endTime[i],profit[i]});
        }
        int finalAns = INT_MIN;
        sort(vec.begin(),vec.end(),compare);
        vector<int> dp(length,0);
        for(int i=0;i<length;i++){
            if(i == 0){
                dp[i] = vec[i].profit;
                continue;
            }

            int prevResult = 0;
            for(int j=i-1;j>=0;j--){
                if(vec[i].startTime >= vec[j].endTime){
                    prevResult = dp[j];
                    break;
                }
            }

            dp[i] = max(dp[i - 1],prevResult  + vec[i].profit);
        }
        return dp[length - 1];
    }
};