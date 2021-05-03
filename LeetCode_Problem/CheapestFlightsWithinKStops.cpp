#include<bits/stdc++.h>
using namespace std;

// 787. Cheapest Flights Within K Stops
// There are n cities connected by m flights. Each flight starts
//  from city u and arrives at v with a price w.
// Now given all the cities and flights, together with starting 
// city src and the destination dst, your task is to find the 
// cheapest price from src to dst with up to k stops. If there 
// is no such route, output -1.

// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:
// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.

// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:

// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 
// Constraints:
// The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// The size of flights will be in range [0, n * (n - 1) / 2].
// The format of each flight will be (src, dst, price).
// The price of each flight will be in the range [1, 10000].
// k is in the range of [0, n - 1].
// There will not be any duplicated flights or self cycles.

class elem{
    public:
    int src;
    int costFromsrc;
    int distanceFromsrc;
};

class elem2{
    public:
    int node;
    int cost;
};

class compare{
    public:
    bool operator()(elem const &a,elem const &b){
        return a.costFromsrc > b.costFromsrc;
    }
};

class Solution {
    unordered_map<int,vector<elem2>> um;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        priority_queue<elem,vector<elem>,compare> pq;
        for(auto element : flights){
            um[element[0]].push_back({element[1],element[2]});
        }
        int answer = INT_MAX;
        pq.push({src,0,0});
        while(!pq.empty()){
            elem front = pq.top();
            pq.pop();
            
            if(front.distanceFromsrc > K + 1){
                continue;
            }

            if(front.src == dst){
                answer = min(answer,front.costFromsrc);
                return answer;
                // continue;
            }

            for(auto var : um[front.src]){
                pq.push({var.node,front.costFromsrc + var.cost,front.distanceFromsrc + 1});
            }
        }
        
        return -1;
    }
};