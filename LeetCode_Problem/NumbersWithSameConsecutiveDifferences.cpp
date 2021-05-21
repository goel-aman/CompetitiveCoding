#include<bits/stdc++.h>
using namespace std;


// 967. Numbers With Same Consecutive Differences
// Return all non-negative integers of length n such that the absolute 
// difference between every two consecutive digits is k.

// Note that every number in the answer must not have leading zeros. 
// For example, 01 has one leading zero and is invalid.

// You may return the answer in any order.

// Example 1:
// Input: n = 3, k = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.

// Example 2:
// Input: n = 2, k = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

// Example 3:
// Input: n = 2, k = 0
// Output: [11,22,33,44,55,66,77,88,99]

// Example 4:
// Input: n = 2, k = 2
// Output: [13,20,24,31,35,42,46,53,57,64,68,75,79,86,97]
 
// Constraints:
// 2 <= n <= 9
// 0 <= k <= 9

class Solution {
    set<int> s;
public:

    void answer(int &n,int &k,int index,vector<int> &res){
        if(index == n){
            int p = 1;
            int value = 0;
            for(int i = index - 1;i>=0;i--){
                value += res[i] * p;
                p = p * 10;
            }
            s.insert(value);
            return ;
        }

        if(index == 0){
            for(int i=1;i<=9;i++){
                res[index] = i;
                answer(n,k,index + 1,res);
            }
            return ;
        }

        if(res[index - 1] + k <= 9 && res[index - 1] + k >= 0){
            res[index] = res[index - 1] + k;
            answer(n,k,index + 1,res);
        }

        if(res[index - 1] - k <= 9 && res[index - 1] - k >= 0){
            res[index] = res[index - 1] -k;
            answer(n,k,index + 1,res);
        }

        return ;
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res(n);
        answer(n,k,0,res);
        vector<int> ret;
        for(auto element : s){
            ret.push_back(element);
        }
        return ret;
    }
};