#include<bits/stdc++.h>
using namespace std;

// 621. Task Scheduler
// Given a characters array tasks, representing the tasks a CPU 
// needs to do, where each letter represents a different task. Tasks
//  could be done in any order. Each task is done in one unit of time.
//  For each unit of time, the CPU could complete either one task or 
// just be idle.
// However, there is a non-negative integer n that represents the cooldown
//  period between two same tasks (the same letter in the array), that is
//  that there must be at least n units of time between any two same tasks.
// Return the least number of units of times that the CPU will take to 
// finish all the given tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: 
// A -> B -> idle -> A -> B -> idle -> A -> B
// There is at least 2 units of time between any two same tasks.

// Example 2:
// Input: tasks = ["A","A","A","B","B","B"], n = 0
// Output: 6
// Explanation: On this case any permutation of size 6 would work since n = 0.
// ["A","A","A","B","B","B"]
// ["A","B","A","B","A","B"]
// ["B","B","B","A","A","A"]
// ...
// And so on.

// Example 3:
// Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
// Output: 16
// Explanation: 
// One possible solution is
// A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 
// Constraints:
// 1 <= task.length <= 104
// tasks[i] is upper-case English letter.
// The integer n is in the range [0, 100].

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int length = tasks.size();
        unordered_map<char,int> um;
        for(auto var : tasks){
            um[var]++;
        }
        
        // first is frequency and second is number
        priority_queue<pair<int,string>> pq;

        for(auto var : um){
            string a = "";
            a += var.first;
            pq.push({var.second,a});
        }

        if(pq.size() < n + 1){
            int difference = (n + 1 - pq.size());
            for(int i=0;i<difference;i++){
                string b = "";
                b += to_string(i);
                pq.push({0,b});              
            }
        }

        int currentTime = 0;
        while(true){
            vector<pair<int,string>> vec;
            bool isBreak = false;
            int count = 0;
            bool ifAllOne = true;
            for(int i=0;i<n+1;i++){
                if(i == 0){
                    pair<int,string> top = pq.top();
                    if(top.first == 0){
                        isBreak = true;
                        break;
                    } 
                }
                pair<int,string> front = pq.top();
                if(front.first > 1){
                    ifAllOne = false;
                }
                if(front.first == 1){
                    count++;
                }
                pq.pop();
                vec.push_back(front);
            }
            if(isBreak){
                break;
            }

            if(ifAllOne == false){
                currentTime += (n + 1);
            }else{
                currentTime += count;
            }

            for(int i=0;i<n+1;i++){
                pq.push({vec[i].first - 1,vec[i].second});
            }
        }
        return currentTime;
    }
};