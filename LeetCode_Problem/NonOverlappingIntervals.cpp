#include<bits/stdc++.h>
using namespace std;

// Non-overlapping Intervals
// Given an array of intervals intervals where intervals[i] = [starti, endi],
//  return the minimum number of intervals you need to remove to make the rest
//  of the intervals non-overlapping.

// Example 1:
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals 
// are non-overlapping.

// Example 2:
// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the
//  intervals non-overlapping.

// Example 3:
// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals  
// since they're already non-overlapping.
 
// Constraints:
// 1 <= intervals.length <= 2 * 104
// intervals[i].length == 2
// -2 * 104 <= starti < endi <= 2 * 104

bool compare(vector<int>&a , vector<int>& b){
    if(a[1] < b[1]){
        return true;
    }

    if(a[1] == b[1]){
        if(a[0] < b[0]){
            return true;
        }
    }
    return false;
}

class Solution {
    int intervalsLength;
    int dp[20001];
public:
    int minOverlapRemove(vector<vector<int>>& intervals,int index){
        if(index == intervalsLength){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        // lets take it first
        int nextIndex = intervalsLength;
        for(int i = index + 1;i<intervalsLength;i++){
            if(intervals[i][0] >= intervals[index][1]){
                nextIndex = i;
                break;
            }    
        }
        int case1 = 1 + minOverlapRemove(intervals,nextIndex);

        // now lets skip it
        int case2 = minOverlapRemove(intervals,index + 1);
        return dp[index] = max(case1,case2);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        intervalsLength = intervals.size();
        memset(dp,-1,sizeof(dp));
        return (intervalsLength - minOverlapRemove(intervals,0));
    }
};