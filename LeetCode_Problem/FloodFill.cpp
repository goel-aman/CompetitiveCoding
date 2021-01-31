// 733. Flood Fill

// An image is represented by a 2-D array of integers, each integer representing
//  the pixel value of the image (from 0 to 65535).

// Given a coordinate (sr, sc) representing the starting pixel (row and column) 
// of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, plus any pixels
//  connected 4-directionally to the starting pixel of the same color as the
//  starting pixel, plus any pixels connected 4-directionally to those pixels
//  (also with the same color as the starting pixel), and so on. Replace the 
// color of all of the aforementioned pixels with the newColor.

// At the end, return the modified image.

// Example 1:
// Input: 
// image = [[1,1,1],[1,1,0],[1,0,1]]
// sr = 1, sc = 1, newColor = 2
// Output: [[2,2,2],[2,2,0],[2,0,1]]
// Explanation: 
// From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
// by a path of the same color as the starting pixel are colored with the new color.
// Note the bottom corner is not colored 2, because it is not 4-directionally connected
// to the starting pixel.
// Note:

// The length of image and image[0] will be in the range [1, 50].
// The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
// The value of each color in image[i][j] and newColor will be an integer in [0, 65535].


#include<bits/stdc++.h>
using namespace std;
class Solution {
    map<pair<int,int>,bool> um;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r = image.size();
        int c = image[0].size();
        int value = image[sr][sc];
        queue<pair<int,int>> q;
        pair<int,int> p(sr,sc);
        um[p] = true;
        q.push(p);
        while(!q.empty()){
            pair<int,int> pp = q.front();
            q.pop();
            image[pp.first][pp.second] = newColor;
            
            // downwards
            if(pp.first + 1 < r && pp.first + 1 >= 0){
                pair<int,int> ppp(pp.first + 1,pp.second);
                if(image[pp.first + 1][pp.second] == value && !(um.count(ppp))){
                    // pair<int,int> ppp(pp.first + 1,pp.second);
                    um[ppp] = true;
                    q.push(ppp);
                }
            }
            
            // upward
            if(pp.first - 1 < r && pp.first - 1 >= 0){
                pair<int,int> ppp(pp.first - 1,pp.second);
                if(image[pp.first - 1][pp.second] == value && !(um.count(ppp))){
                    um[ppp] = true;
                    q.push(ppp);
                }
            }
            
            if(pp.second + 1 < c && pp.second + 1 >=0 ){
                pair<int,int> ppp(pp.first,pp.second + 1);
                if(image[pp.first][pp.second + 1] == value && !(um.count(ppp))){
                    um[ppp] = true;
                    q.push(ppp);
                }
            }
            
            if(pp.second - 1 < c && pp.second - 1 >= 0){
                pair<int,int> ppp(pp.first,pp.second - 1);
                if(image[pp.first][pp.second - 1] == value && !(um.count(ppp))){
                    um[ppp] = true;
                    q.push(ppp);
                }
            }
        }
        return image;
    }
};