#include<bits/stdc++.h>
using namespace std;

// 759. Employee Free Time
// We are given a list schedule of employees, which 
// represents the working time for each employee.
// Each employee has a list of non-overlapping Intervals,
//  and these intervals are in sorted order.
// Return the list of finite intervals representing common,
//  positive-length free time for all employees, also in 
// sorted order.
// (Even though we are representing Intervals in the form 
// [x, y], the objects inside are Intervals, not lists or 
// arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2,
//  and schedule[0][0][0] is not defined).  Also, we wouldn't include 
// intervals like [5, 5] in our answer, as they have zero length.

// Example 1:
// Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
// Output: [[3,4]]
// Explanation: There are a total of three employees, and all common
// free time intervals would be [-inf, 1], [3, 4], [10, inf].
// We discard any intervals that contain inf as they aren't finite.

// Example 2:
// Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
// Output: [[5,6],[7,9]]
 
// Constraints:
// 1 <= schedule.length , schedule[i].length <= 50
// 0 <= schedule[i].start < schedule[i].end <= 10^8

class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> ret;
        vector<vector<int>> temp;
        int scheduleLength = schedule.size();


        for(int i=0;i<scheduleLength;i++){
            for(int j=0;j<schedule[i].size();j++){
                temp.push_back({schedule[i][j].start,schedule[i][j].end});              
            }
        }
        vector<vector<int>> finalIntervals;

        int tempLength = temp.size();
        sort(temp.begin(),temp.end());
        int lastOperator = 0;
        int iter1 = 0, iter2 = 1;
        while((iter1 < tempLength && iter2 < tempLength)){
            if(temp[iter2][0] >= temp[iter1][0] && temp[iter2][0] <= temp[iter1][1]){
                temp[iter1][0] = min(temp[iter1][0],temp[iter2][0]);
                temp[iter2][1] = max(temp[iter1][1],temp[iter2][1]);
                iter2++;
                lastOperator = 0;
                continue;
            }
            else{
                finalIntervals.push_back({temp[iter1][0],temp[iter2][0]});
                iter1 = iter2;
                iter2++;
                lastOperator = 1;
            }
        }

        if(lastOperator){
            finalIntervals.push_back({temp[iter1][0],temp[iter1][1]});
        }

        for(int i=0;i<finalIntervals.size() - 1;i++){
            Interval inter;
            inter.start = finalIntervals[i][1];
            inter.end = finalIntervals[i + 1][0];
            ret.push_back(inter);       
        }
        return ret;
    }
};