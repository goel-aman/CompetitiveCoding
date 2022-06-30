#include<bits/stdc++.h>
using namespace std;

// 818. Race Car
// Your car starts at position 0 and speed +1 on an infinite
// number line. Your car can go into negative positions. Your 
// car drives automatically according to a sequence of instructions
// 'A' (accelerate) and 'R' (reverse):

// When you get an instruction 'A', your car does the following:
// position += speed
// speed *= 2
// When you get an instruction 'R', your car does the following:
// If your speed is positive then speed = -1
// otherwise speed = 1
// Your position stays the same.
// For example, after commands "AAR", your car goes to positions 
// 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.

// Given a target position target, return the length of the shortest
// sequence of instructions to get there.

// Example 1:
// Input: target = 3
// Output: 2
// Explanation: 
// The shortest instruction sequence is "AA".
// Your position goes from 0 --> 1 --> 3.

// Example 2:
// Input: target = 6
// Output: 5
// Explanation: 
// The shortest instruction sequence is "AAARA".
// Your position goes from 0 --> 1 --> 3 --> 7 --> 7 --> 6.
 
// Constraints:
// 1 <= target <= 104

class Solution {
public:
    int racecar(int target) {
       int ans = -1;

       queue<pair<int,int>> que;
       que.push({0,1});

       unordered_set<string> findElement;
       findElement.insert("0;1");
        int level = 0;
        while(!que.empty()){
            int size = que.size();
            while(size--){
                pair<int,int> front = que.front();
                que.pop();
                if(front.first == target){
                    return level;
                }

                pair<int,int> nextElement = {front.first + front.second, front.second * 2};
                string temp = to_string(nextElement.first) + ";" + to_string(nextElement.second);

                if(nextElement.first < (target << 1) && nextElement.first > 0 && !findElement.count(temp)){
                    findElement.insert(temp);
                    que.push(nextElement);
                }

                nextElement = {front.first,(front.second > 0) ? -1 : 1};
                temp = to_string(nextElement.first) + ";" + to_string(nextElement.second);

                if(nextElement.first < (target << 1) && nextElement.first > 0 && !findElement.count(temp)){
                    findElement.insert(temp);
                    que.push(nextElement);
                }
            }

            level++;
        }
        return -1;
    }
};