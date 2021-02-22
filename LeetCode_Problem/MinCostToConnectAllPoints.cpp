// 1584. Min Cost to Connect All Points

// You are given an array points representing integer coordinates of some points
//  on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance
//  between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if 
// there is exactly one simple path between any two points.

// Example 1:
// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation:
// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.

// Example 2:
// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18

// Example 3:
// Input: points = [[0,0],[1,1],[1,0],[-1,1]]
// Output: 4

// Example 4:
// Input: points = [[-1000000,-1000000],[1000000,1000000]]
// Output: 4000000

// Example 5:
// Input: points = [[0,0]]
// Output: 0
 
// Constraints:
// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// All pairs (xi, yi) are distinct.


#include<bits/stdc++.h>
using namespace std;

class elem{
    public:
    int value;
    int index1;
    int index2;
};

class compare{
    public:
    bool operator()(elem const& a,elem const& b) const{
        return a.value > b.value;
    }
};

class Solution {
    int * parent;
public:

    int findParent(int x){
        if(x == parent[x]){
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void merge(int x,int y){
        int xPar = findParent(x);
        int yPar = findParent(y);
        if(xPar != yPar){
            parent[xPar] = yPar;
        }
        return ;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int pointsLength = points.size();
        parent = new int[pointsLength];
        for(int i=0;i<pointsLength;i++){
            parent[i] = i;
        }

        priority_queue<elem,vector<elem>,compare> pq;

        for(int i=0;i<pointsLength;i++){
            for(int j=i + 1;j<pointsLength;j++){
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                elem ab;
                ab.value = distance;
                ab.index1 = i;
                ab.index2 = j;
                pq.push(ab);
            }
        }
        int totalCost = 0;
        int edgesRequired = pointsLength - 1;
        while(!pq.empty() && edgesRequired > 0){
            elem front = pq.top();
            pq.pop();
            
            if(findParent(front.index1) == findParent(front.index2)){
                continue;
            }
            else{
                totalCost += front.value;
                edgesRequired--;
                merge(front.index1,front.index2);
            }
        }
        return totalCost;
    }
};