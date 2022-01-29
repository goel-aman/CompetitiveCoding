#include<bits/stdc++.h>
using namespace std;

// 84. Largest Rectangle in Histogram
// Given an array of integers heights representing the histogram's
//  bar height where the width of each bar is 1, return the area of
//  the largest rectangle in the histogram.

// Example 1:
// Input: heights = [2,1,5,6,2,3]
// Output: 10
// Explanation: The above is a histogram
//  where width of each bar is 1.
// The largest rectangle is shown in the 
// red area, which has an area = 10 units.

// Example 2:
// Input: heights = [2,4]
// Output: 4

// Constraints:
// 1 <= heights.length <= 105
// 0 <= heights[i] <= 104

class Solution {
    public:
    int largestRectangleArea(vector<int> heights){
        int heightsLength = heights.size();
        vector<int> left(heightsLength,-1);
        vector<int> right(heightsLength,-1);

        stack<int> st;

        for(int i=0;i<heightsLength;i++){
            
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                // cout<<" Element getting popped is ; "<<st.top()<<endl;
                st.pop();
            }

            if(st.empty()){
                // cout<<"i is : "<<i<<" and left[i] is : "<<0<<endl;
                left[i] = 0;
            }else{
                // cout<<"i is : "<<i<<" and left[i] is : "<<st.top() + 1<<endl;
                left[i] = st.top() + 1;
            }

            st.push(i);
        }

        stack<int> stackRight;
        for(int i=heightsLength - 1;i >= 0;i--){
            while(stackRight.size() > 0 && heights[stackRight.top()] >= heights[i]){
                stackRight.pop();
            }
            if(stackRight.empty()){
                right[i] = heightsLength - 1;
            }else{
                right[i] = stackRight.top() - 1;
            }
            stackRight.push(i);
        }

        int ans = INT_MIN;
        for(int i=0;i<heightsLength;i++){
            int value = (right[i] - left[i] + 1) * heights[i];
            ans = max(ans,value);
        }
        return ans;
    }
};