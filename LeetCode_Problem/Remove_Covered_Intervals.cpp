#include<bits/stdc++.h>
#include<vector>
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        for(int i=0;i<intervals.size();i++){
            int part = 0;
            for(int j = 0;j<intervals.size();j++){
                if(i == j){
                    continue;
                }
                int a = intervals[i][0];
                int b = intervals[i][1];
                int c = intervals[j][0];
                int d = intervals[j][1];
                if(c <= a && d >= b){
                    part = 1;
                    break;
                }
            }
            if(part == 0){
                count++;
            }
        }
        return count;
    }
};