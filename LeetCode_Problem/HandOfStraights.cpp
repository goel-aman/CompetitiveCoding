#include<bits/stdc++.h>
using namespace std;

// 846. Hand of Straights

// Alice has some number of cards and she wants to rearrange 
// the cards into groups so that each group is of size groupSize,
//  and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written
//  on the ith card and an integer groupSize, return true if she 
// can rearrange the cards, or false otherwise.

// Example 1:
// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]

// Example 2:
// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

// Constraints:
// 1 <= hand.length <= 104
// 0 <= hand[i] <= 109
// 1 <= groupSize <= hand.length
 
// Note: This question is the same as 1296: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int handLength = hand.size();
        unordered_map<int,int> um;
        for(auto var : hand){
            um[var]++;           
        }

        if(handLength%groupSize != 0){
            return false;
        }   

        sort(hand.begin(),hand.end());
        int tempSize = 0;
        for(int i=0;i<handLength;i++){
            if(um.count(hand[i]) > 0 && um[hand[i]] > 0){
                int value = hand[i];
                um[hand[i]]--;
                for(int j=1;j<groupSize;j++){
                    if(um.count(value + j) > 0 && um[value + j] > 0){
                        um[value + j]--;
                    }else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};