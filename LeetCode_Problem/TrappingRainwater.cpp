#include<bits/stdc++.h>
using namespace std;

// Given n non-negative integers representing an elevation map where the 
// width of each bar is 1, compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by 
// array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water 
// (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

// Constraints:
// n == height.length
// 0 <= n <= 3 * 104
// 0 <= height[i] <= 105
class Solution {
public:
    int trap(vector<int>& height) {
        int heightLength = height.size();
        vector<int> LeftMax(heightLength,0);
        vector<int> rightMax(heightLength,0);
        
        int heightMaxRight = INT_MIN;
        for(int i=0;i<heightLength;i++){
            if(i == 0){
                heightMaxRight = max(heightMaxRight,height[i]);
                continue;
            }
            
            rightMax[i] = heightMaxRight;
            heightMaxRight = max(heightMaxRight,height[i]);
        }
        
        int heightMaxLeft = INT_MIN;
        for(int i=heightLength - 1;i>=0;i--){
            if(i == heightLength - 1){
                heightMaxLeft = max(heightMaxLeft,height[i]);
                continue;
            }
            
            LeftMax[i] = heightMaxLeft;
            heightMaxLeft = max(heightMaxLeft,height[i]);
        }
        int answer = 0;
        for(int i=0;i<heightLength;i++){
            int val = min(LeftMax[i],rightMax[i]);
            if(val > height[i]){
                answer += val - height[i];
            }
        }
        return answer;
    }
};