#include<bits/stdc++.h>
using namespace std;

// 465. Optimal Account Balancing
// You are given an array of transactions transactions where
//  transactions[i] = [fromi, toi, amounti] indicates that the 
// person with ID = fromi gave amounti $ to the person with 
// ID = toi.
// Return the minimum number of transactions required to settle
//  the debt.

// Example 1:
// Input: transactions = [[0,1,10],[2,0,5]]
// Output: 2
// Explanation:
// Person #0 gave person #1 $10.
// Person #2 gave person #0 $5.
// Two transactions are needed. One way to settle the debt is 
// person #1 pays person #0 and #2 $5 each.

// Example 2:
// Input: transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
// Output: 1
// Explanation:
// Person #0 gave person #1 $10.
// Person #1 gave person #0 $1.
// Person #1 gave person #2 $5.
// Person #2 gave person #0 $5.
// Therefore, person #1 only need to give person #0 $4, and 
// all debt is settled.
 
// Constraints:
// 1 <= transactions.length <= 8
// transactions[i].length == 3
// 0 <= fromi, toi < 12
// fromi != toi
// 1 <= amounti <= 100


class Solution {
    unordered_map<int,int> netValues;
    vector<int> array;
    int arrayLength = 0;
public:
    int solve(int index){
        if(index == arrayLength){
            return 0;
        }

        if(array[index] == 0){
            return solve(index + 1);
        }

        int result = INT_MAX;

        for(int i = index + 1;i<arrayLength;i++){
            if(array[index] * array[i] < 0){
                array[i] += array[index];

                result = min(result,1 + solve(index + 1));
                array[i] -= array[index];
            }
        }

        return result;
    }

    int minTransfers(vector<vector<int>>& transactions) {
        int transactionsLength = transactions.size();
        for(int i=0;i<transactionsLength;i++){
            netValues[transactions[i][0]] -= transactions[i][2];
            netValues[transactions[i][1]] += transactions[i][2];
        }

        for(auto var : netValues){
            if(var.second != 0){
                array.push_back(var.second);
            }
        }
        arrayLength = array.size();
        return solve(0);
    }
};