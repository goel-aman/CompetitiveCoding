// 1478. Allocate Mailboxes

// Given the array houses and an integer k. where houses[i] is the location of the ith 
// house along a street, your task is to allocate k mailboxes in the street.
// Return the minimum total distance between each house and its nearest mailbox.
// The answer is guaranteed to fit in a 32-bit signed integer.

// Example 1:
// Input: houses = [1,4,8,10,20], k = 3
// Output: 5
// Explanation: Allocate mailboxes in position 3, 9 and 20.
// Minimum total distance from each houses to nearest mailboxes is |3-1| + |4-3| + |9-8| + |10-9| + |20-20| = 5 

// Example 2:
// Input: houses = [2,3,5,12,18], k = 2
// Output: 9
// Explanation: Allocate mailboxes in position 3 and 14.
// Minimum total distance from each houses to nearest mailboxes is |2-3| + |3-3| + |5-3| + |12-14| + |18-14| = 9.

// Example 3:
// Input: houses = [7,4,6,1], k = 1
// Output: 8

// Example 4:
// Input: houses = [3,6,14,10], k = 4
// Output: 0
 
// Constraints:
// n == houses.length
// 1 <= n <= 100
// 1 <= houses[i] <= 10^4
// 1 <= k <= n
// Array houses contain unique integers.

#include<bits/stdc++.h>
using namespace std;
class Solution {
    long int ** cost;
    long int ** dp;
public:
    int findAnswer(vector<int>& houses,int start,int k){
        int n = houses.size();
        if(start == n && k == 0 ){
            return 0;
        }

        if(start >= n || k <= 0)
        {
            return 100000;
        }
        
        if(dp[start][k] != -1){
            return dp[start][k];
        }
        long int costt = 100000;
        for(int i=start;i<n;i++){
            costt = min(costt,cost[start][i] + (long int) findAnswer(houses,i + 1, k - 1));
        }
        return dp[start][k] = (int) costt;
    }


    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        int housesLength = houses.size();
        cost = new long int*[housesLength];
        for(int i=0;i<housesLength;i++){
            cost[i] = new long int[housesLength];
            for(int j=0;j<housesLength;j++){
                cost[i][j] = 0;
            }
        }

        for(int i=0;i<housesLength;i++){
            for(int j=i;j<housesLength;j++){
                for(int x = i; x <= j;x++){
                    cost[i][j] += abs(houses[(i + j)/2] - houses[x]);
                }
            }
        }
        dp = new long int*[housesLength];
        for(int i=0;i<housesLength;i++){
            dp[i] = new long int[k + 1];
            for(int j = 0;j<=k;j++){
                dp[i][j] = -1;
            }
        }
        return findAnswer(houses,0,k);
    }
};