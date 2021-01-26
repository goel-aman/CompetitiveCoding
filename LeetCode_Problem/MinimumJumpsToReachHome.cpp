// 1654. Minimum Jumps to Reach Home

// A certain bug's home is on the x-axis at position x. Help them get there from position 0.

// The bug jumps according to the following rules:

// It can jump exactly a positions forward (to the right).
// It can jump exactly b positions backward (to the left).
// It cannot jump backward twice in a row.
// It cannot jump to any forbidden positions.
// The bug may jump forward beyond its home, but it cannot jump to positions numbered with negative integers.

// Given an array of integers forbidden, where forbidden[i] means that the bug cannot jump to the position forbidden[i], and integers a, b, and x, return the minimum number of jumps needed for the bug to reach its home. If there is no possible sequence of jumps that lands the bug on position x, return -1.

 

// Example 1:

// Input: forbidden = [14,4,18,1,15], a = 3, b = 15, x = 9
// Output: 3
// Explanation: 3 jumps forward (0 -> 3 -> 6 -> 9) will get the bug home.
// Example 2:

// Input: forbidden = [8,3,16,6,12,20], a = 15, b = 13, x = 11
// Output: -1
// Example 3:

// Input: forbidden = [1,6,2,14,5,17,4], a = 16, b = 9, x = 7
// Output: 2
// Explanation: One jump forward (0 -> 16) then one jump backward (16 -> 7) will get the bug home.
 

// Constraints:

// 1 <= forbidden.length <= 1000
// 1 <= a, b, forbidden[i] <= 2000
// 0 <= x <= 2000
// All the elements in forbidden are distinct.
// Position x is not forbidden.


// Solution
#include<bits/stdc++.h>
using namespace std;

class elem{
    public:
    bool prevback;
    int value;
    int stepTaken;
};

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int,bool> um;
        for(auto element : forbidden){
            um[element] = true;
        }
        // prevback, value
        int count = 0;
        map<pair<int,int>,bool> visited;
        queue<elem> q;
        elem first;
        first.prevback = false;
        first.value = 0;
        first.stepTaken = 0;
        pair<int,int> pp;
        pp.first = first.prevback;
        pp.second = first.value;
        visited[pp] = true;
        q.push(first);
        while(!q.empty()){
            elem front = q.front();
            q.pop();
            
            if(front.value == x){
                return front.stepTaken;
            }
            
            if(front.prevback == false){
                elem newElem;
                newElem.prevback = false;
                newElem.value = a + front.value;
                newElem.stepTaken = front.stepTaken + 1;
                pair<int,int> ppp;
                ppp.first = newElem.prevback;
                ppp.second = newElem.value;
                if( !(visited.count(ppp)) && !(um.count(ppp.second)) && (ppp.second < 6000)){
                    visited[ppp] = true;
                    q.push(newElem);
                }
                
                
                if(front.value - b > 0){
                    elem newElem2;
                    newElem2.prevback = true;
                    newElem2.value = front.value - b;
                    newElem2.stepTaken = front.stepTaken + 1;
                    pair<int,int> pppp(newElem2.prevback,newElem2.value);
                    if(!(visited.count(pppp)) && !(um.count(newElem2.value)) && (pppp.second < 6000) ){
                        visited[pppp] = true;
                        q.push(newElem2);    
                    }
                    
                }
            }
            
            else{
                elem newElem;
                newElem.prevback = false;
                newElem.value = a + front.value;
                newElem.stepTaken = front.stepTaken + 1;
                pair<int,int> pppp(newElem.prevback,newElem.value);
                if(!(visited.count(pppp) > 0) && !(um.count(newElem.value) > 0) && (pppp.second < 6000) ){
                    visited[pppp] = true;
                    q.push(newElem);    
                }
            }
        }
        return -1;
    }
};