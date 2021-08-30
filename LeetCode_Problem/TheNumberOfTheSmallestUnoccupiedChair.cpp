#include<bits/stdc++.h>
using namespace std;

// 1942. The Number of the Smallest Unoccupied Chair
// There is a party where n friends numbered from 0 to n - 1 
// are attending. There is an infinite number of chairs in 
// this party that are numbered from 0 to infinity. When a 
// friend arrives at the party, they sit on the unoccupied
//  chair with the smallest number.

// For example, if chairs 0, 1, and 5 are occupied when a 
// friend comes, they will sit on chair number 2.
// When a friend leaves the party, their chair becomes 
// unoccupied at the moment they leave. If another friend 
// arrives at that same moment, they can sit in that chair.

// You are given a 0-indexed 2D integer array times where 
// times[i] = [arrivali, leavingi], indicating the arrival 
// and leaving times of the ith friend respectively, and an
//  integer targetFriend. All arrival times are distinct.

// Return the chair number that the friend numbered 
// targetFriend will sit on.

// Example 1:
// Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
// Output: 1
// Explanation: 
// - Friend 0 arrives at time 1 and sits on chair 0.
// - Friend 1 arrives at time 2 and sits on chair 1.
// - Friend 1 leaves at time 3 and chair 1 becomes empty.
// - Friend 0 leaves at time 4 and chair 0 becomes empty.
// - Friend 2 arrives at time 4 and sits on chair 0.
// Since friend 1 sat on chair 1, we return 1.

// Example 2:
// Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
// Output: 2
// Explanation: 
// - Friend 1 arrives at time 1 and sits on chair 0.
// - Friend 2 arrives at time 2 and sits on chair 1.
// - Friend 0 arrives at time 3 and sits on chair 2.
// - Friend 1 leaves at time 5 and chair 0 becomes empty.
// - Friend 2 leaves at time 6 and chair 1 becomes empty.
// - Friend 0 leaves at time 10 and chair 2 becomes empty.
// Since friend 0 sat on chair 2, we return 2.
 
// Constraints:
// n == times.length
// 2 <= n <= 104
// times[i].length == 2
// 1 <= arrivali < leavingi <= 105
// 0 <= targetFriend <= n - 1
// Each arrivali time is distinct.

class obj{
    public:
    int index;
    vector<int> vec;
};

class element{
    public:
    int time;
    int chairPosition;   
};

bool compare(obj &a,obj &b){
    if(a.vec[0] < b.vec[0]){
        return true;
    }

    if(a.vec[0] == b.vec[0]){
        if(a.vec[1] < b.vec[1]){
            return true;
        }
    }
    return false;
}

struct CompareHeight {
    bool operator()(element const& p1,element const& p2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return p1.time > p2.time;
    }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int timesLength = times.size();
        vector<obj> vec;
        for(int i=0;i<timesLength;i++){
            obj value;
            value.index = i;
            value.vec = times[i];
            vec.push_back(value);
        }
        priority_queue<int,vector<int>,greater<int>> pq;
        priority_queue<element,vector<element>,CompareHeight> pq2;
        for(int i=0;i<timesLength;i++){
            pq.push(i);
        }
        unordered_map<int,int> um;
        sort(vec.begin(),vec.end(),compare);
        for(int i=0;i<timesLength;i++){
            int start = vec[i].vec[0];
            int end = vec[i].vec[1];
            
            while(!pq2.empty() && pq2.top().time <= start){
                element front = pq2.top();
                pq2.pop();
                pq.push(front.chairPosition);
            }          

            int value = pq.top();
            pq.pop();
            pq2.push({end,value});
            um[vec[i].index] = value;
            // if(vec[i].index == targetFriend){
            //     return value;
            // } 
        }  
        return um[targetFriend];
    }
};