#include<bits/stdc++.h>
using namespace std;

// 1691. Maximum Height by Stacking Cuboids

// Given n cuboids where the dimensions of the ith cuboid is
//  cuboids[i] = [widthi, lengthi, heighti] (0-indexed). Choose
//  a subset of cuboids and place them on each other.

// You can place cuboid i on cuboid j if widthi <= widthj and lengthi <= lengthj 
// and heighti <= heightj. You can rearrange any cuboid's dimensions by rotating
//  it to put it on another cuboid.

// Return the maximum height of the stacked cuboids.

// Example 1:
// Input: cuboids = [[50,45,20],[95,37,53],[45,23,12]]
// Output: 190
// Explanation:
// Cuboid 1 is placed on the bottom with the 53x37 side facing down with height 95.
// Cuboid 0 is placed next with the 45x20 side facing down with height 50.
// Cuboid 2 is placed next with the 23x12 side facing down with height 45.
// The total height is 95 + 50 + 45 = 190.

// Example 2:
// Input: cuboids = [[38,25,45],[76,35,3]]
// Output: 76
// Explanation:
// You can't place any of the cuboids on the other.
// We choose cuboid 1 and rotate it so that the 35x3 side is facing down and its height is 76.

// Example 3:
// Input: cuboids = [[7,11,17],[7,17,11],[11,7,17],[11,17,7],[17,7,11],[17,11,7]]
// Output: 102
// Explanation:
// After rearranging the cuboids, you can see that all cuboids have the same dimension.
// You can place the 11x7 side down on all cuboids so their heights are 17.
// The maximum height of stacked cuboids is 6 * 17 = 102.
 
// Constraints:
// n == cuboids.length
// 1 <= n <= 100
// 1 <= widthi, lengthi, heighti <= 100
bool compare(vector<int> &a,vector<int> &b){
    if(a[0] < b[0]){
        return true;;
    }
    
    if(a[0] == b[0]){
        if(a[1] < b[1]){
            return true;
        }
        if(a[1] == b[1]){
            if(a[2] < b[2]){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
    
    return false;
}
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int cuboidsLength = cuboids.size();
        for(int i=0;i<cuboidsLength;i++){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end(),compare);
        int answer = INT_MIN;
        int dp[cuboidsLength];
       
        for(int i=cuboidsLength - 1;i>=0;i--){
            // cout<<"height of cuboid i : "<<i<<" is : "<<cuboids[i][2]<<endl;
            dp[i] = cuboids[i][2];
            answer = max(dp[i],answer);
            for(int j=i+1;j<cuboidsLength;j++){
                if(cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]){
                    dp[i] = max(dp[i],dp[j] + cuboids[i][2]);
                    answer = max(dp[i],answer);
                }
                
            }
        }
        return answer;
    }
};