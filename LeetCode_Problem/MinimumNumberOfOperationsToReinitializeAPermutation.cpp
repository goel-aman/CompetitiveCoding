#include<bits/stdc++.h>
using namespace std;

// 1806. Minimum Number of Operations to Reinitialize a Permutation
// You are given an even integer n​​​​​​. You initially have a permutation
// perm of size n​​ where perm[i] == i​ (0-indexed)​​​​.

// In one operation, you will create a new array arr, and for each i:
// If i % 2 == 0, then arr[i] = perm[i / 2].
// If i % 2 == 1, then arr[i] = perm[n / 2 + (i - 1) / 2].
// You will then assign arr​​​​ to perm.

// Return the minimum non-zero number of operations you need to perform 
// on perm to return the permutation to its initial value.

// Example 1:
// Input: n = 2
// Output: 1
// Explanation: perm = [0,1] initially.
// After the 1st operation, perm = [0,1]
// So it takes only 1 operation.

// Example 2:
// Input: n = 4
// Output: 2
// Explanation: perm = [0,1,2,3] initially.
// After the 1st operation, perm = [0,2,1,3]
// After the 2nd operation, perm = [0,1,2,3]
// So it takes only 2 operations.

// Example 3:
// Input: n = 6
// Output: 4
 
// Constraints:
// 2 <= n <= 1000
// n​​​​​​ is even.


class Solution {
public:
    bool check(vector<int>& array,int &n){
        for(int i=0;i<n;i++){
            if(array[i] != i){
                return false;
            }
        }
        return true;
    }
    
    vector<int> operate(vector<int>& array,int &n){
        vector<int> newArray(n);
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                newArray[i] = array[i/2];
            }
            else{
                newArray[i] = array[n/2 + ((i - 1)/2)];
            }
        }
        return newArray;
    }

    int reinitializePermutation(int n) {
        if(n == 1){
            return 0;
        }

        vector<int> array(n);
        for(int i=0;i<n;i++){
            array[i] = i;
        }
        int operation = 1;
        array = operate(array,n);
        // cout
        while(!check(array,n)){
            array = operate(array,n);
            operation++;
        }
        return operation;      
    }
};