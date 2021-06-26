#include<bits/stdc++.h>
using namespace std;

// 57. Insert Interval

// Given a set of non-overlapping intervals, insert a new 
// interval into the intervals (merge if necessary).
// You may assume that the intervals were initially sorted
//  according to their start times.

// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

// Example 3:
// Input: intervals = [], newInterval = [5,7]
// Output: [[5,7]]

// Example 4:
// Input: intervals = [[1,5]], newInterval = [2,3]
// Output: [[1,5]]

// Example 5:
// Input: intervals = [[1,5]], newInterval = [2,7]
// Output: [[1,7]]
 
// Constraints:
// 0 <= intervals.length <= 104
// intervals[i].length == 2
// 0 <= intervals[i][0] <= intervals[i][1] <= 105
// intervals is sorted by intervals[i][0] in ascending order.
// newInterval.length == 2
// 0 <= newInterval[0] <= newInterval[1] <= 105


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int start = newInterval[0],end = newInterval[1];
        int intervalsLength = intervals.size();
        bool pending = true;
        for(int i=0;i<intervalsLength;i++){
            if(intervals[i][1] < start || end < intervals[i][0]){
                ret.push_back(intervals[i]);
                continue;
            }

            if(start >= intervals[i][0] && start <= intervals[i][1]){
                start = min(intervals[i][0],start);
                end = max(intervals[i][1],end);
                continue;
            }   

            if(intervals[i][0] >= start && intervals[i][0] <= end){
                start = min(intervals[i][0],start);
                end = max(intervals[i][1],end);
                continue;
            }

            if(end >= intervals[i][0]){
                start = min(intervals[i][0],start);
                end = max(intervals[i][1],end);
                continue;
            }

            if(intervals[i][0] > end){
                if(pending){
                    pending = false;
                    ret.push_back({start,end});                  
                }
            }
        }
        if(pending){
            ret.push_back({start,end});
        }
        sort(ret.begin(),ret.end());
        return ret;
    }
};