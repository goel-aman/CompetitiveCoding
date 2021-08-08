#include<bits/stdc++.h>
using namespace std;

// 986. Interval List Intersections
// You are given two lists of closed intervals, firstList and 
// secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj].
//  Each list of intervals is pairwise disjoint and in sorted order.
// Return the intersection of these two interval lists.

// A closed interval [a, b] (with a < b) denotes the set of real
//  numbers x with a <= x <= b.

// The intersection of two closed intervals is a set of real numbers that
//  are either empty or represented as a closed interval. For example, the
//  intersection of [1, 3] and [2, 4] is [2, 3].

// Example 1:
// Input: firstList = [[0,2],[5,10],[13,23],[24,25]],
//  secondList = [[1,5],[8,12],[15,24],[25,26]]
// Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]

// Example 2:
// Input: firstList = [[1,3],[5,9]], secondList = []
// Output: []

// Example 3:
// Input: firstList = [], secondList = [[4,8],[10,12]]
// Output: []

// Example 4:
// Input: firstList = [[1,7]], secondList = [[3,10]]
// Output: [[3,7]]
 
// Constraints:
// 0 <= firstList.length, secondList.length <= 1000
// firstList.length + secondList.length >= 1
// 0 <= starti < endi <= 109
// endi < starti+1
// 0 <= startj < endj <= 109
// endj < startj+1



class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int firstLength = firstList.size();
        int secondLength = secondList.size();
        vector<vector<int>> ans;
        int lastVisited = 1;
        for(int i=0;i<firstLength;i++){
            int start = firstList[i][0] , second = firstList[i][1];

            for(int j=lastVisited - 1;j<secondLength;j++){
                if(secondList[j][1] < start){
                    continue;
                }

                if(second < secondList[j][0]){
                    break;
                }        

                if(start >= secondList[j][0]){
                    int nextStart = max(start,secondList[j][0]);
                    int minValue = min(secondList[j][1],second);
                    ans.push_back({nextStart,minValue});
                    lastVisited = j + 1;
                    continue;
                }

                if(start < secondList[j][0]){
                    int minValue = max(start,secondList[j][0]);
                    int maxValue = min(second,secondList[j][1]);
                    ans.push_back({minValue,maxValue});
                    lastVisited = j + 1;
                    continue;
                    // break;
                }
            }
        }        
        return ans;
    }
};
