// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.


// Example 1:

// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = []
// Output: 0
// Example 3:

// Input: matrix = [["0"]]
// Output: 0
// Example 4:

// Input: matrix = [["1"]]
// Output: 1
// Example 5:

// Input: matrix = [["0","0"]]
// Output: 0
 

// Constraints:

// rows == matrix.length
// cols == matrix.length
// 0 <= row, cols <= 200
// matrix[i][j] is '0' or '1'.

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

 
int maximumAreaHistogram(vector<int> v){
    int length = v.size();
    int max_area = 0;
    int rb[length];
    rb[length - 1] = length;
    stack<int> s;
    s.push(length - 1);
    for(int i=length - 2;i>=0;i--){
        while(!s.empty() && v[i] <= v[s.top()]){
            s.pop();
        }
        if(s.empty()){
            rb[i] = length;
        }
        else{
            rb[i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }
    
    int lb[length];
    lb[0] = -1;
    s.push(0);
    for(int i =1;i<length;i++){
        while(!s.empty() && v[i] <= v[s.top()]){
            s.pop();
        }
        if(s.empty()){
            lb[i] = -1;
        }
        else{
            lb[i] = s.top();
        }
        s.push(i);
    }


    for(int i=0;i<length;i++){
        int area_temp = v[i] * (rb[i] - lb[i] - 1);
        if(area_temp > max_area){
            max_area = area_temp;
        }
    }
    return max_area;
}
  

    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        vector<int> v;
        int max_area = 0;
        v.resize(matrix[0].size(),0);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j] += 1;
                }
            }
            int val = maximumAreaHistogram(v);
            if(val > max_area){
                max_area = val;
            }
        }
        return max_area;
    }
};