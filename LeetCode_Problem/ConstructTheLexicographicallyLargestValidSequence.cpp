#include<bits/stdc++.h>
using namespace std;

// 1718. Construct the Lexicographically Largest Valid Sequence

// Given an integer n, find a sequence that satisfies all of the following:
// The integer 1 occurs once in the sequence.
// Each integer between 2 and n occurs twice in the sequence.
// For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
// The distance between two numbers on the sequence, a[i] and a[j], is the absolute 
// difference of their indices, |j - i|.

// Return the lexicographically largest sequence. It is guaranteed that under the given constraints, 
// there is always a solution.
// A sequence a is lexicographically larger than a sequence b (of the same length) if in the first
//  position where a and b differ, sequence a has a number greater than the corresponding number 
// in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position
//  they differ is at the third number, and 9 is greater than 5.

// Example 1:
// Input: n = 3
// Output: [3,1,2,3,2]
// Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the
//  lexicographically largest valid sequence.

// Example 2:
// Input: n = 5
// Output: [5,3,1,4,3,5,2,4,2]
 
// Constraints:
// 1 <= n <= 20

class Solution {
    bool isAnswer;
    int length;
    int nn;
public:
    Solution(){
        isAnswer = false;
    }

    void constructDistancedSequence(vector<int>& vec,int index,vector<vector<int>> &res,vector<int>& visited){
        if(isAnswer == true){
            return;
        }
        if(index > length){
            return ;
        }
        
        if(index == length){
            bool gotAnswer = true;
            for(int i=0;i<length;i++){
                if(vec[i] == -1){
                    gotAnswer = false;
                    break;
                }
            }
            if(gotAnswer){
                res.push_back(vec);
                isAnswer = true;
            }
            return ;
        }
        
        if(vec[index] == -1){
            for(int i=nn;i>=1;i--){
                if(i != 1){
                    if(visited[i] == -1 && index + i <length && vec[index + i] == -1){
                        vec[index] = i;
                        vec[index + i] = i;
                        visited[i] = 1;
                        constructDistancedSequence(vec,index + 1,res,visited);
                        visited[i] = -1;
                        vec[index] = -1;
                        vec[index + i] = -1;
                    }
                    continue;
                }
                
                if(i == 1){
                    if(visited[i] == -1){
                        vec[index] = i;
                        visited[i] = 1;
                        constructDistancedSequence(vec,index +1,res,visited);
                        vec[index] = -1;
                        visited[i] = -1;
                    }
                    continue;
                }
            }
        }
        constructDistancedSequence(vec,index + 1,res,visited);
        return;
        
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> vec(2*n - 1, -1);
        length = 2*n - 1;
        nn = n;
        vector<int> visited(n+1,-1);
        vector<vector<int>> res;
        constructDistancedSequence(vec,0,res,visited);
        return res[0];
    }
};