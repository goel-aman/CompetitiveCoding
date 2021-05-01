#include<bits/stdc++.h>
using namespace std;

// 475. Heaters
// Winter is coming! During the contest, your first job is to design a standard 
// heater with a fixed warm radius to warm all the houses.

// Every house can be warmed, as long as the house is within the heater's warm radius
//  range. 

// Given the positions of houses and heaters on a horizontal line, return the minimum
//  radius standard of heaters so that those heaters could cover all houses.
// Notice that all the heaters follow your radius standard, and the warm radius will the same.

// Example 1:
// Input: houses = [1,2,3], heaters = [2]
// Output: 1
// Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.

// Example 2:
// Input: houses = [1,2,3,4], heaters = [1,4]
// Output: 1
// Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.

// Example 3:
// Input: houses = [1,5], heaters = [2]
// Output: 3
 
// Constraints:
// 1 <= houses.length, heaters.length <= 3 * 104
// 1 <= houses[i], heaters[i] <= 109

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int housesLength = houses.size();
        int heatersLength = heaters.size();
        int start = 0, end = INT_MAX;
        int answer = INT_MAX;
        while(start <= end){
            int mid = (start + end) / 2;
            bool issValid = true;
            for(int i=0;i<housesLength;i++){
                bool isValid = false;
                int s = 0, e = heatersLength - 1;
                while(s <= e){
                    int m = (s + e) / 2;
                    if(houses[i] <= heaters[m] + mid && houses[i] >= heaters[m] - mid){
                        isValid = true;break;
                    }

                    if(houses[i] < heaters[m] - mid){
                        e = m - 1;
                        continue;
                    }

                    if(houses[i] > heaters[m] + mid){
                        s = m + 1;
                        continue;
                    }
                }
                if(isValid == false){
                    issValid = false;
                    break;
                }
            }
            if(issValid == true){
                answer = min(answer,mid);
                end = mid - 1;
                continue;
            }

            if(issValid == false){
                start = mid + 1;
                continue;
            }
        }
        return answer;
    }
};