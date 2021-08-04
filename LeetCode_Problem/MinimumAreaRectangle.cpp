#include<bits/stdc++.h>
using namespace std;

// 939. Minimum Area Rectangle
// You are given an array of points in the X-Y plane 
// points where points[i] = [xi, yi].

// Return the minimum area of a rectangle formed from
// these points, with sides parallel to the X and Y axes.
//  If there is not any such rectangle, return 0.

// Example 1:
// Input: points = [[1,1],[1,3],[3,1],[3,3],[2,2]]
// Output: 4

// Example 2:
// Input: points = [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
// Output: 2
 
// Constraints:
// 1 <= points.length <= 500
// points[i].length == 2
// 0 <= xi, yi <= 4 * 104
// All the given points are unique.


class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        int pointsLength = points.size();
        unordered_map<int,unordered_set<int>> um;
        vector<int> yCoordinates;
        for(int i=0;i<points.size();i++){
            um[points[i][1]].insert(points[i][0]);
        }

        for(auto var : um){
            yCoordinates.push_back(var.first);
        }

        int ans = INT_MAX;
        int yLength = yCoordinates.size();
        int minValue = INT_MAX;
        for(int i=0;i<yLength;i++){
            for(int j=i + 1;j<yLength;j++){
                unordered_map<int,int> count;
                for(auto var : um[yCoordinates[i]]){
                    count[var]++;
                }

                for(auto var : um[yCoordinates[j]]){
                    count[var]++;
                }
                
                vector<int> temp;
                for(auto var : count){
                    if(var.second >= 2){
                        temp.push_back(var.first);
                    }
                }

                sort(temp.begin(),temp.end());
                int minDiff = INT_MAX;
                int tempLength = temp.size();
                for(int i=0;i<=tempLength - 2;i++){
                    if(abs(temp[i + 1] - temp[i]) < minDiff){
                        minDiff = abs(temp[i + 1] - temp[i]);
                    }
                }
                
                if(minDiff != INT_MAX){
                    ans = min(ans,minDiff * abs(yCoordinates[i] - yCoordinates[j]));
                }
            }
        }
        return (ans == INT_MAX) ? 0 : ans;
        
    }
};