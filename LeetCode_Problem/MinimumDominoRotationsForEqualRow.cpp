#include<bits/stdc++.h>
using namespace std;

// 1007. Minimum Domino Rotations For Equal Row
// In a row of dominoes, tops[i] and bottoms[i] represent
//  the top and bottom halves of the ith domino. (A domino
//  is a tile with two numbers from 1 to 6 - one on each 
// half of the tile.)

// We may rotate the ith domino, so that tops[i] and
//  bottoms[i] swap values.

// Return the minimum number of rotations so that all the
// values in tops are the same, or all the values in bottoms 
// are the same.

// If it cannot be done, return -1.

// Example 1:
// Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// Output: 2
// Explanation: 
// The first figure represents the dominoes as given by tops
//  and bottoms: before we do any rotations.
// If we rotate the second and fourth dominoes, we can make 
// every value in the top row equal to 2, as indicated by the
//  second figure.

// Example 2:
// Input: tops = [3,5,1,2,3], bottoms = [3,6,3,3,4]
// Output: -1
// Explanation: 
// In this case, it is not possible to rotate the dominoes to
//  make one row of values equal.
 
// Constraints:
// 2 <= tops.length <= 2 * 104
// bottoms.length == tops.length
// 1 <= tops[i], bottoms[i] <= 6


class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> um;
        int topsLength = tops.size();
        
        int maxfrequency = 0;
        int maxElement = 0;

        for(int i=0;i<topsLength;i++){
            um[tops[i]]++;
            um[bottoms[i]]++;

            if(um[tops[i]] > maxfrequency){
                maxfrequency = um[tops[i]];
                maxElement = tops[i];
            }

            if(um[bottoms[i]] > maxfrequency){
                maxfrequency = um[bottoms[i]];
                maxElement = bottoms[i];
            }
        }

        if(maxfrequency < topsLength){
            return -1;
        }

        // vector<bool> visited(topsLength,false);
        int countTop = 0, countBottom = 0;
        for(int i=0;i<topsLength;i++){
            if(tops[i] == maxElement || bottoms[i] == maxElement)
            {
                if(tops[i] != maxElement){
                    countTop++;
                }
                
                if(bottoms[i] != maxElement){
                    countBottom++;
                }
                continue;
            }else{
                return -1;
            }
        }

        return min(countTop,countBottom);
    }
};