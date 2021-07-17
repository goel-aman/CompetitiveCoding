#include<bits/stdc++.h>
using namespace std;

// 539. Minimum Time Difference
// Given a list of 24-hour clock time points in "HH:MM" format, 
// return the minimum minutes difference between any two 
// time-points in the list.

// Example 1:
// Input: timePoints = ["23:59","00:00"]
// Output: 1

// Example 2:
// Input: timePoints = ["00:00","23:59","00:00"]
// Output: 0
 
// Constraints:
// 2 <= timePoints <= 2 * 104
// timePoints[i] is in the format "HH:MM".

class Solution {
public:
    int calculateDifference(string s1,string s2){
        int h1 = stoi(s1.substr(0,2));
        int h2 = stoi(s2.substr(0,2));
        int m1 = stoi(s1.substr(3));
        int m2 = stoi(s2.substr(3));
        return (h2 - h1) * 60 + (m2 - m1);
    }

    int findMinDifference(vector<string>& timePoints) {
        int timePointsLength = timePoints.size();
        sort(timePoints.begin(),timePoints.end());
        int ans = INT_MAX;
        for(int i=0;i<timePointsLength;i++){
            int value = abs(calculateDifference(timePoints[(i - 1 + timePointsLength)%timePointsLength],timePoints[i]));
            ans = min(value,ans);
            ans = min(ans,abs(1440 - value));
        }
        return ans;
    }
};