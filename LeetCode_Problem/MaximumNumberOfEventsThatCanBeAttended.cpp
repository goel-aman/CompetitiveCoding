#include<bits/stdc++.h>
using namespace std;

// 1353. Maximum Number of Events That Can Be Attended
// Given an array of events where events[i] = [startDayi, endDayi].
//  Every event i starts at startDayi and ends at endDayi.
// You can attend an event i at any day d where 
// startTimei <= d <= endTimei. Notice that you can only 
// attend one event at any time d.
// Return the maximum number of events you can attend.

// Example 1:
// Input: events = [[1,2],[2,3],[3,4]]
// Output: 3
// Explanation: You can attend all the three events.
// One way to attend them all is as shown.
// Attend the first event on day 1.
// Attend the second event on day 2.
// Attend the third event on day 3.

// Example 2:
// Input: events= [[1,2],[2,3],[3,4],[1,2]]
// Output: 4

// Example 3:
// Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
// Output: 4

// Example 4:
// Input: events = [[1,100000]]
// Output: 1

// Example 5:
// Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
// Output: 7
 
// Constraints:
// 1 <= events.length <= 105
// events[i].length == 2
// 1 <= startDayi <= endDayi <= 105

bool compare(vector<int>& a,vector<int> &b){  
    if(a[0] < b[0]){
        return true;
    }
    return false;
}   

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int eventsLength = events.size();
        sort(events.begin(),events.end(),compare);
        priority_queue<int,vector<int>,greater<int>> pq;
        int ans = 0;
        int j = 0;
        for(int i=0;i<=100000;i++){
            while(!pq.empty() && pq.top() < i){
                pq.pop();
            }

            while(j < eventsLength && events[j][0] == i){
                pq.push(events[j][1]);
            }

            if(!pq.empty()){
                ans++;
                pq.pop();
            }
        }
        return ans;
    }
};