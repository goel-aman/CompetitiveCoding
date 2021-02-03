// 1615. Maximal Network Rank

// There is an infrastructure of n cities with some number of roads connecting these cities.
//  Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.

// The network rank of two different cities is defined as the total number of directly 
// connected roads to either city. If a road is directly connected to both cities, it 
// is only counted once.

// The maximal network rank of the infrastructure is the maximum network rank of all
//  pairs of different cities.

// Given the integer n and the array roads, return the maximal network rank of the
//  entire infrastructure.

 

// Example 1:

// Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
// Output: 4
// Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads that are connected to either 0 or 1. The road between 0 and 1 is only counted once.


// Example 2:
// Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
// Output: 5
// Explanation: There are 5 roads that are connected to cities 1 or 2.

// Example 3:
// Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
// Output: 5
// Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do not have to be connected.
 

// Constraints:
// 2 <= n <= 100
// 0 <= roads.length <= n * (n - 1) / 2
// roads[i].length == 2
// 0 <= ai, bi <= n-1
// ai != bi
// Each pair of cities has at most one road connecting them.

#include<bits/stdc++.h>
using namespace std;
class elem{
    public:
    int nodeNumber;
    int degree;
};

bool compare(elem a,elem b){
    if(a.degree > b.degree){
        return true;
    }
    return false;
}

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int maxx = INT_MIN;
        unordered_map<int,vector<int>> um;
        map<pair<int,int>,bool> m;

        for(auto temp : roads){
            m[{temp[0],temp[1]}] = true;
            m[{temp[1],temp[0]}] = true;
            um[temp[0]].push_back(temp[1]);
            um[temp[1]].push_back(temp[0]);
        }

        vector<elem> vv;

        for(auto temp: um){
            elem a;
            a.nodeNumber = temp.first;
            a.degree = temp.second.size();
            vv.push_back(a);
        }
        sort(vv.begin(),vv.end(),compare);
        int maximumValue = vv[0].degree;
        int secondMaxValue = INT_MIN;
        vector<elem> second;
        for(int i=0;i<vv.size();i++){
            if(vv[i].degree < maximumValue ){
                secondMaxValue = vv[i].degree;
                break;
            }
        }
        for(int i=0;i<vv.size();i++){
            if(vv[i].degree < secondMaxValue){
                break;
            }
            if(vv[i].degree == maximumValue || vv[i].degree == secondMaxValue){
                second.push_back(vv[i]);
            }
        }
        int ans = INT_MIN;
        for(int i=0;i<second.size() - 1;i++){
            for(int j=i + 1;j<second.size();j++){
                if(m.count({second[i].nodeNumber,second[j].nodeNumber})){
                    ans = max(ans,second[i].degree + second[j].degree - 1);
                }
                else{
                    ans = max(ans,second[i].degree + second[j].degree);
                }              
            }
        }
        return ans;
    }
};