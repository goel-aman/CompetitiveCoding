#include<bits/stdc++.h>
using namespace std;

// 1386. Cinema Seat Allocation


// A cinema has n rows of seats, numbered from 1 to n and there are ten
//  seats in each row, labelled from 1 to 10 as shown in the figure above.

// Given the array reservedSeats containing the numbers of seats already 
// reserved, for example, reservedSeats[i] = [3,8] means the seat located 
// in row 3 and labelled with 8 is already reserved.

// Return the maximum number of four-person groups you can assign on the 
// cinema seats. A four-person group occupies four adjacent seats in one 
// single row. Seats across an aisle (such as [3,3] and [3,4]) are not 
// considered to be adjacent, but there is an exceptional case on which
//  an aisle split a four-person group, in that case, the aisle split a 
// four-person group in the middle, which means to have two people on each side.

// Example 1:
// Input: n = 3, reservedSeats = [[1,2],[1,3],[1,8],[2,6],[3,1],[3,10]]
// Output: 4
// Explanation: The figure above shows the optimal allocation for four groups, where seats mark with blue are already reserved and contiguous seats mark with orange are for one group.

// Example 2:
// Input: n = 2, reservedSeats = [[2,1],[1,8],[2,6]]
// Output: 2

// Example 3:
// Input: n = 4, reservedSeats = [[4,3],[1,4],[4,6],[1,7]]
// Output: 4
 
// Constraints:
// 1 <= n <= 10^9
// 1 <= reservedSeats.length <= min(10*n, 10^4)
// reservedSeats[i].length == 2
// 1 <= reservedSeats[i][0] <= n
// 1 <= reservedSeats[i][1] <= 10
// All reservedSeats[i] are distinct.

class Solution {
    unordered_map<int,unordered_set<int>> um;
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int reservedLength = reservedSeats.size();
        for(int i=0;i<reservedLength;i++){
            um[reservedSeats[i][0]].insert(reservedSeats[i][1]);
        }

        int ans = n * 2;
        // cout<<"value of ans is : "<<ans<<endl;
        for(auto element : um){
            int val = element.first;
            // cout<<"value of val is ; "<<val<<endl;
            bool first = true; bool second = true;
            if(element.second.count(2) || element.second.count(3) || element.second.count(4) || element.second.count(5)){
                ans -= 1;
                first = false;
            }

            if(element.second.count(6) || element.second.count(7) || element.second.count(8) || element.second.count(9)){
                ans -= 1;
                second = false;
            }

            if(!element.second.count(4) && !element.second.count(5) && !element.second.count(6) && !element.second.count(7) && first == false && second == false){
                ans += 1;
            }
            // cout<<"current value of ans is : "<<ans<<endl;
        }
        return ans;
    }
};