#include<bits/stdc++.h>
using namespace std;


// 436. Find Right Interval

// You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
// The right interval for an interval i is an interval j such that startj >= endi and startj is minimized.
// Return an array of right interval indices for each interval i. If no right interval exists for interval
//  i, then put -1 at index i.

// Example 1:
// Input: intervals = [[1,2]]
// Output: [-1]
// Explanation: There is only one interval in the collection, so it outputs -1.

// Example 2:
// Input: intervals = [[3,4],[2,3],[1,2]]
// Output: [-1,0,1]
// Explanation: There is no right interval for [3,4].
// The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
// The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.

// Example 3:
// Input: intervals = [[1,4],[2,3],[3,4]]
// Output: [-1,2,-1]
// Explanation: There is no right interval for [1,4] and [3,4].
// The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.
 
// Constraints:
// 1 <= intervals.length <= 2 * 104
// intervals[i].length == 2
// -106 <= starti <= endi <= 106
// The start point of each interval is unique.

class answerFinder{
    public:
    int start;
    int end;
    int index;
};

bool compare(answerFinder a,answerFinder b){
    if(a.start <= b.start){
        return true;
    }
    return false;
}

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int intervalsLength = intervals.size();
        vector<int> ans(intervalsLength);
        answerFinder arr[intervalsLength];

        for(int i=0;i<intervalsLength;i++){
            arr[i].start = intervals[i][0];
            arr[i].end = intervals[i][1];
            arr[i].index = i;          
        }

        sort(arr,arr + intervalsLength,compare);

        for(int i=0;i<intervalsLength;i++){
            int endI = arr[i].end;
            int indexNot = arr[i].index;
            int answer = INT_MAX,answerIndex = -1;
            int start = 0 , end = intervalsLength - 1;
            while(start <= end){
                int mid = (start + end) / 2;
                // if(arr[mid].index == indexNot){
                //     start = mid + 1;
                //     continue;
                // }

                if(arr[mid].start >= endI){
                    if(arr[mid].start < answer){
                        answer = arr[mid].start;
                        answerIndex = arr[mid].index;
                        end = mid - 1;
                        continue;
                    }
                }
                
                if(arr[mid].start < endI){
                    start = mid + 1;
                    continue;
                }
            }
            ans[indexNot] = answerIndex; 
        }
        return ans;
    }
};