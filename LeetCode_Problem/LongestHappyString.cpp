#include<bits/stdc++.h>
using namespace std;

// 1405. Longest Happy String
// A string is called happy if it does not have any
// of the strings 'aaa', 'bbb' or 'ccc' as a substring.

// Given three integers a, b and c, return any string s,
//  which satisfies following conditions:

// s is happy and longest possible.
// s contains at most a occurrences of the letter 'a', 
// at most b occurrences of the letter 'b' and at most
//  c occurrences of the letter 'c'.
// s will only contain 'a', 'b' and 'c' letters.
// If there is no such string s return the empty string "".

// Example 1:
// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.

// Example 2:
// Input: a = 2, b = 2, c = 1
// Output: "aabbc"

// Example 3:
// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It's the only correct answer in this case.
 
// Constraints:
// 0 <= a, b, c <= 100
// a + b + c > 0


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,int>> pq;
        if(a > 0){
            pq.push({a,'a'});
        }

        if(b > 0){
            pq.push({b,'b'});
        }

        if(c > 0){
            pq.push({c,'c'});
        }
        string ans = "";
        while(pq.size() > 1){
            pair<int,int> first = pq.top();
            pq.pop();
            pair<int,int> second = pq.top();
            pq.pop();

            if(first.first > 1){
                ans += first.second;
                ans += first.second;
                first.first -= 2; 
            }else{
                ans += first.second;
                first.first -= 1;
            }

            if(second.first > 1 && second.first >= first.first){
                ans += second.second;
                ans += second.second;
                second.first -= 2;
            }else{
                ans += second.second;
                second.first -= 1;
            }
            if(first.first > 0){
                pq.push(first);
            }

            if(second.first > 0){
                pq.push(second);
            }
        }

        if(pq.size() > 0){
            pair<int,int> top = pq.top();
            if(top.first > 1){
                ans += top.second;
                ans += top.second;
            }else{
                ans += top.second;
            }
        }
        return ans;
    }
};