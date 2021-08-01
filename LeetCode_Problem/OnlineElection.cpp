#include<bits/stdc++.h>
using namespace std;

// 911. Online Election
// In an election, the i-th vote was cast for
//  persons[i] at time times[i].
// Now, we would like to implement the following query 
// function: TopVotedCandidate.q(int t) will return the
//  number of the person that was leading the election
//  at time t.  

// Votes cast at time t will count towards our query.  
//In the case of a tie, the most recent vote (among 
// tied candidates) wins.

// Example 1:
// Input: ["TopVotedCandidate","q","q","q","q","q","q"], 
// [[[0,1,1,0,0,1,0],[0,5,10,15,20,25,30]],[3],[12],[25],[15],[24],[8]]
// Output: [null,0,1,1,0,0,1]
// Explanation: 
// At time 3, the votes are [0], and 0 is leading.
// At time 12, the votes are [0,1,1], and 1 is leading.
// At time 25, the votes are [0,1,1,0,0,1], and 1 is leading 
// (as ties go to the most recent vote.)
// This continues for 3 more queries at time 15, 24, and 8.

// Note:
// 1 <= persons.length = times.length <= 5000
// 0 <= persons[i] <= persons.length
// times is a strictly increasing array with all elements in [0, 10^9].
// TopVotedCandidate.q is called at most 10000 times per test case.
// TopVotedCandidate.q(int t) is always called with t >= times[0].


class TopVotedCandidate {
    unordered_map<int,int> um;
    int maxValue = 0;
    int maxElement = -1;
    unordered_map<int,int> corresponding;
    // winner , timestamp.
    vector<pair<int,int>> ans;
    int personsLength;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        personsLength = persons.size();
        for(int i=0;i<personsLength;i++){
            um[persons[i]]++;
            if(um[persons[i]] >= maxValue){
                maxValue = um[persons[i]];
                maxElement = persons[i];
            }
            ans.push_back({maxElement,times[i]});
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<" ";
        }
        cout<<endl;
    }
    
    int q(int t) {
        int start = 0;
        int end = ans.size() - 1;
        int anss = 0;
        while(start <= end){
            int mid = (start + end )/2;
            if(ans[mid].second <= t){
                anss = ans[mid].first;
                start = mid + 1;
                continue;
            }
            
            end = mid - 1;
        }
        return anss;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */