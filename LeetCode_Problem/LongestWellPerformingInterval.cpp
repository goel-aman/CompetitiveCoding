#include<bits/stdc++.h>
using namespace std;

// 1124. Longest Well-Performing Interval
// We are given hours, a list of the number of 
// hours worked per day for a given employee.

// A day is considered to be a tiring day if and 
// only if the number of hours worked is 
// (strictly) greater than 8.

// A well-performing interval is an interval of 
// days for which the number of tiring days is strictly
//  larger than the number of non-tiring days.

// Return the length of the longest well-performing interval.

// Example 1:
// Input: hours = [9,9,6,0,6,6,9]
// Output: 3
// Explanation: The longest well-performing interval is [9,9,6].

// Example 2:
// Input: hours = [6,6,6]
// Output: 0
 
// Constraints:
// 1 <= hours.length <= 104
// 0 <= hours[i] <= 16




class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int hoursLength = hours.size();

        vector<int> prefix(hoursLength,0);
        // prefix.push_
        int sum = 0;
        for(int i=0;i<hoursLength;i++){
            if(hours[i] > 8){
                sum += 1;
            }
            else{
                sum -= 1;
            }
            prefix[i] = sum;
        }
        unordered_map<int,int> um;
        int ans = 0;
        for(int i=0;i<hoursLength;i++){
            if(prefix[i] >= 1){
                ans = max(ans,i + 1);
                continue;
            }
            
            if(!um.count(prefix[i])){
                um[prefix[i]] = i;
            }
            if(um.count(prefix[i] - 1)){
                ans = max(ans,i - um[prefix[i] - 1]);
            }
            
        }
        return ans;
    }
};