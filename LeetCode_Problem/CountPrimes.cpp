// Count the number of prime numbers less than a non-negative number, n.

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
 

// Constraints:

// 0 <= n <= 5 * 106
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int * arr;
public:
    void solve(int n){
        arr = new int[n + 5];
        for(long long int i=1;i<=n;i++){
            arr[i] = 1;
        }
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 1;
        for(int i = 2;i*i <= n;i++){
            int j = i*i;
            while(j < n){
                arr[j] = 0;
                j = j + i;
            }
        }
    }
    bool isPrime(int x){
        if(arr[x] == 1){
            return true;
        }
        return false;
    }
    int countPrimes(int n) {
        solve(n);
        int count = 0;
        for(int i=1;i<n;i++){
            // cout<<i<<" "<<arr[i]<<endl;
            if(isPrime(i)){
                // cout<<i<<endl;
                count++;
            }
        }
        return count;
    }
};