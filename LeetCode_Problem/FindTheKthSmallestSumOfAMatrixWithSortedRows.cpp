#include<bits/stdc++.h>
using namespace std;

// 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows
// You are given an m * n matrix, mat, and an integer k, which 
// has its rows sorted in non-decreasing order.

// You are allowed to choose exactly 1 element from each row to 
// form an array. Return the Kth smallest array sum among all 
// possible arrays.

// Example 1:
// Input: mat = [[1,3,11],[2,4,6]], k = 5
// Output: 7
// Explanation: Choosing one element from each row, the first k
//  smallest sum are:
// [1,2], [1,4], [3,2], [3,4], [1,6]. Where the 5th sum is 7.  

// Example 2:
// Input: mat = [[1,3,11],[2,4,6]], k = 9
// Output: 17

// Example 3:
// Input: mat = [[1,10,10],[1,4,5],[2,3,6]], k = 7
// Output: 9
// Explanation: Choosing one element from each row, the first k
//  smallest sum are:
// [1,1,2], [1,1,3], [1,4,2], [1,4,3], [1,1,6], [1,5,2], [1,5,3].
//  Where the 7th sum is 9.  

// Example 4:
// Input: mat = [[1,1,10],[2,2,9]], k = 7
// Output: 12
 
// Constraints:
// m == mat.length
// n == mat.length[i]
// 1 <= m, n <= 40
// 1 <= k <= min(200, n ^ m)
// 1 <= mat[i][j] <= 5000
// mat[i] is a non decreasing array.


class element{
    public:
    vector<int> arr;
    int value = 0;

    element(int size){
        arr.resize(size,0);
    }
};

class compare{
    public:
    bool operator()(element &first,element &second){
        if(first.value < second.value){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = mat[0].size();
        int sum = 0;
        set<vector<int>> visited;
        priority_queue<element,vector<element>,compare> pq;
        
        for(int i=0;i<rows;i++){
            sum += mat[i][0];
        }
        
        element initial(rows);
        initial.value = sum;
        pq.push(initial);
        visited.insert(initial.arr);
        int count = k;
        while(!pq.empty() && k > 1){
            element front = pq.top();
            pq.pop();
            
            for(int i=0;i<rows;i++){
                element next(rows);
                next.arr = front.arr;

                if(next.arr[i] + 1 < cols){
                    next.arr[i] += 1;
                    if(visited.find(next.arr) == visited.end()){
                        next.value = front.value - mat[i][front.arr[i]] + mat[i][next.arr[i]];
                        pq.push(next);
                        visited.insert(next.arr);
                    }
                }
            }
            k--;
        }
        return pq.top().value;
    }
};