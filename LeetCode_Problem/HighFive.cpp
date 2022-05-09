#include<bits/stdc++.h>
using namespace std;

// 1086. High Five
// Given a list of the scores of different students, items,
//  where items[i] = [IDi, scorei] represents one score from a
//  student with IDi, calculate each student's top five average.

// Return the answer as an array of pairs result, where
//  result[j] = [IDj, topFiveAveragej] represents the student 
// with IDj and their top five average. Sort result by IDj in
//  increasing order.

// A student's top five average is calculated by taking the sum
//  of their top five scores and dividing it by 5 usine
// division.

// Example 1:
// Input: items = [[1,91],[1,92],[2,93],[2,97],[1,60],e
// [1,87],[1,100],[2,100],[2,76]]
// Output: [[1,87],[2,88]]
// Explanation: 
// The student with ID = 1 got scores 91, 92, 60, 65, e
//  average is (100 + 92 + 91 + 87 + 65) / 5 = 87.
// The student with ID = 2 got scores 93, 97, 77, 100, and 76. Their top
// five average is (100 + 97 + 93 + 77 + 76) / 5 = 88.6, but with integer division
//  their average converts to 88.

// Example 2:
// Input: items = [[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100],[1,100],[7,100]]
// Output: [[1,100],[7,100]]
 
// Constraints:
// 1 <= items.length <= 1000
// items[i].length == 2
// 1 <= IDi <= 1000
// 0 <= scorei <= 100
// For each IDi, there will be at least five scores.


class Solution {
    map<int,vector<int>> temp;
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int itemsLength = items.size();

        for(int i=0;i<itemsLength;i++){
            temp[items[i][0]].push_back(items[i][1]);
        }
        vector<vector<int>> ret;
        for(auto var : temp){
            sort(var.second.begin(),var.second.end(),greater<int>());
            int sum = 0;
            for(int i=0;i<5;i++){
                sum += var.second[i];
            }

            ret.push_back({var.first,sum/5});
        }
        return ret;
    }
};

