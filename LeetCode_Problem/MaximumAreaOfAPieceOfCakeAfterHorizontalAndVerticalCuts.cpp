#include<bits/stdc++.h>
using namespace std;

// 1465. Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
// You are given a rectangular cake of size h x w and two arrays of integers
//  horizontalCuts and verticalCuts where:

// horizontalCuts[i] is the distance from the top of the rectangular
//  cake to the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular
//  cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each 
// horizontal and vertical position provided in the arrays horizontalCuts
//  and verticalCuts. Since the answer can be a large number, return
//  this modulo 109 + 7.

// Example 1:
// Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
// Output: 4 
// Explanation: The figure above represents the given rectangular cake.
//  Red lines are the horizontal and vertical cuts. After you cut the cake,
//  the green piece of cake has the maximum area.

// Example 2:
// Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
// Output: 6
// Explanation: The figure above represents the given rectangular cake. Red 
// lines are the horizontal and vertical cuts. After you cut the cake, the 
// green and yellow pieces of cake have the maximum area.

// Example 3:
// Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
// Output: 9

// Constraints:
// 2 <= h, w <= 109
// 1 <= horizontalCuts.length <= min(h - 1, 105)
// 1 <= verticalCuts.length <= min(w - 1, 105)
// 1 <= horizontalCuts[i] < h
// 1 <= verticalCuts[i] < w
// All the elements in horizontalCuts are distinct.
// All the elements in verticalCuts are distinct.


class Solution {
    int mod = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxVertical = 0,maxHorizontal = 0;
        int verticalCutsHeight = verticalCuts.size();
        int horizontalCutsHeight = horizontalCuts.size();
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        for(int i=0;i<horizontalCutsHeight;i++){
            if(i == 0){
                maxHorizontal = max(maxHorizontal,horizontalCuts[i]);
                if(i == horizontalCutsHeight - 1){
                    maxHorizontal = max(maxHorizontal,h - horizontalCuts[i]);
                }    
                continue;
            }

            if(i == horizontalCutsHeight - 1){
                maxHorizontal = max(maxHorizontal,horizontalCuts[i] - horizontalCuts[i - 1]);
                maxHorizontal = max(maxHorizontal,h - horizontalCuts[i]);
                continue;
            }

            maxHorizontal = max(maxHorizontal,horizontalCuts[i] - horizontalCuts[i - 1]);
        }
        
        // cout<<"maxHorizontal is : "<<maxHorizontal<<endl;

        for(int i=0;i<verticalCutsHeight;i++){
            if(i == 0){
                maxVertical = max(maxVertical,verticalCuts[i]);
                if(i == verticalCutsHeight - 1){
                    maxVertical = max(maxVertical,w - verticalCuts[i]);
                }
                continue;
            }

            if(i == verticalCutsHeight - 1){
                maxVertical = max(maxVertical,w - verticalCuts[i]);
                maxVertical = max(maxVertical,verticalCuts[i] - verticalCuts[i - 1]);
                continue;
                
            }

            maxVertical = max(maxVertical,verticalCuts[i] - verticalCuts[i - 1]);
        }

        long long int value = ((long long int) maxVertical * (long long int) maxHorizontal)%mod;
        return value; 
    }
};