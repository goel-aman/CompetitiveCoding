// 526. Beautiful Arrangement

// Suppose you have n integers labeled 1 through n. A permutation of those n integers 
// perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n),
//  either of the following is true:

// perm[i] is divisible by i.
// i is divisible by perm[i].
// Given an integer n, return the number of the beautiful arrangements that you can construct.

// Example 1:
// Input: n = 2
// Output: 2
// Explanation: 
// The first beautiful arrangement is [1,2]:
//     - perm[1] = 1 is divisible by i = 1
//     - perm[2] = 2 is divisible by i = 2
// The second beautiful arrangement is [2,1]:
//     - perm[1] = 2 is divisible by i = 1
//     - i = 2 is divisible by perm[2] = 1

// Example 2:
// Input: n = 1
// Output: 1
 
// Constraints:
// 1 <= n <= 15

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int count(vector<int> &visited,int index,int &n){
        if(index == n+1){
            return 1;
        }
        
        int tempIndex = index;
        unordered_set<int> possibleNumber;
        int counter = 1;
        while(index*counter <= n){
            possibleNumber.insert(index * counter);
            counter++;
        }
        for(int i=1;i<=sqrt(index);i++){
            if(index%i == 0){
                possibleNumber.insert(i);
                possibleNumber.insert(index / i);
            }
        }
        int answer = 0;
        for(auto x : possibleNumber){
            if(visited[x] == -1){
                visited[x] = 1;
                answer += count(visited,index + 1,n);
                visited[x] = -1; 
            }
        }
        return answer;
    }
    
    int countArrangement(int n) {
        vector<int> visited(n + 1,-1);
        return count(visited,1,n);
    }
};