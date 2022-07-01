#include<bits/stdc++.h>
using namespace std;

// 2021. Brightest Position on Street
// A perfectly straight street is represented by a number line. 
// The street has street lamp(s) on it and is represented by a 2De
// integer array lights. Each lights[i] = [positioni, rangei] 
// indicates that there is a street lamp at position positioni that
// lights up the area from [positioni - rangei, positioni + rangei] 
// (inclusive).

// The brightness of a position p is defined as the number of street
// lamp that light up the position p.

// Given lights, return the brightest position on the street. If there
// are multiple brightest positions, return the smallest one.

// Example 1:
// Input: lights = [[-3,2],[1,2],[3,3]]
// Output: -1
// Explanation:
// The first street lamp lights up the area from [(-3) - 2, (-3) + 2] = [-5, -1].
// The second street lamp lights up the area from [1 - 2, 1 + 2] = [-1, 3].
// The third street lamp lights up the area from [3 - 3, 3 + 3] = [0, 6].

// Position -1 has a brightness of 2, illuminated by the first and 
// second street light.
// Positions 0, 1, 2, and 3 have a brightness of 2, illuminated by
//  the second and third street light.
// Out of all these positions, -1 is the smallest, so return it.

// Example 2:
// Input: lights = [[1,0],[0,1]]
// Output: 1
// Explanation:
// The first street lamp lights up the area from [1 - 0, 1 + 0] = [1, 1].
// The second street lamp lights up the area from [0 - 1, 0 + 1] = [-1, 1].

// Position 1 has a brightness of 2, illuminated by the first and 
// second street light.
// Return 1 because it is the brightest position on the street.

// Example 3:
// Input: lights = [[1,2]]
// Output: -1
// Explanation:
// The first street lamp lights up the area from
//  [1 - 2, 1 + 2] = [-1, 3].
// Positions -1, 0, 1, 2, and 3 have a brightness of 1,
//  illuminated by the first street light.
// Out of all these positions, -1 is the smallest, so return it.
 
// Constraints:
// 1 <= lights.length <= 105
// lights[i].length == 2
// -108 <= positioni <= 108
// 0 <= rangei <= 108

class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        int lightsLength = lights.size();
        vector<vector<int>> ranges;
        
        for(int i=0;i<lightsLength;i++){
            ranges.push_back({lights[i][0] - lights[i][1],lights[i][0] + lights[i][1]});
        }

        sort(ranges.begin(),ranges.end());
        set<int> uniqueNumbers;
        for(auto var : ranges){
            uniqueNumbers.insert(var[0]);
            uniqueNumbers.insert(var[1]);
        }
        vector<int> numbers;
        unordered_map<int,int> position;
        for(auto var : uniqueNumbers){
            numbers.push_back(var);
            position[var] = numbers.size() - 1;
        }
        
        int numbersLength = numbers.size();
        vector<int> temp(numbersLength,0);
        for(auto var : ranges){
            temp[position[var[0]]] += 1;
            if(position[var[1]] + 1 < numbersLength){
                temp[position[var[1]] + 1] -= 1;
            }
        }
        
        int ansCount = 0, ans = -1;
        int var = 0;
        for(int i=0;i<temp.size();i++){
            var += temp[i];
            temp[i] = var;
            if(temp[i] == ansCount){
                ans = min(ans,numbers[i]);
            }
            
            if(temp[i] > ansCount){
                ansCount = temp[i];
                ans = numbers[i];
            }
        }
        return ans;
    }
};