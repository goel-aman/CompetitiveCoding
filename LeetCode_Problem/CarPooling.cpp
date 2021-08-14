#include<bits/stdc++.h>
using namespace std;

// 1094. Car Pooling
// There is a car with capacity empty seats.
// The vehicle only drives east (i.e., it cannot 
// turn around and drive west).

// You are given the integer capacity and an array
//  trips where trip[i] = [numPassengersi, fromi, toi] 
// indicates that the ith trip has numPassengersi 
// passengers and the locations to pick them up and 
// drop them off are fromi and toi respectively. The 
// locations are given as the number of kilometers due
//  east from the car's initial location.

// Return true if it is possible to pick up and drop off all
// passengers for all the given trips, or false otherwise.

// Example 1:
// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false

// Example 2:
// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true

// Example 3:
// Input: trips = [[2,1,5],[3,5,7]], capacity = 3
// Output: true

// Example 4:
// Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
// Output: true
 
// Constraints:
// 1 <= trips.length <= 1000
// trips[i].length == 3
// 1 <= numPassengersi <= 100
// 0 <= fromi < toi <= 1000
// 1 <= capacity <= 105


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int tripsLength = trips.size();
        unordered_map<int,int> onBoard;
        unordered_map<int,int> leave;

        set<int> position;
        for(int i=0;i<tripsLength;i++){
            onBoard[trips[i][1]] += trips[i][0];
            leave[trips[i][2]] += trips[i][0];
            position.insert(trips[i][1]);
            position.insert(trips[i][2]);
        }

        int current = 0;
        for(auto &var : position){
            if(leave.count(var)){
                current -= leave[var];
            }

            if(onBoard.count(var)){
                current += onBoard[var];
            }

            if(current > capacity){
                return false;
            }
        }
        return true;
    }
};