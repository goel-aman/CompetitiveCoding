#include<bits/stdc++.h>
using namespace std;

// 650. 2 Keys Keyboard

// Initially on a notepad only one character 'A' is present.
//  You can perform two operations on this notepad for each step:

// Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
// Paste: You can paste the characters which are copied last time.
 
// Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum
//  number of steps permitted. Output the minimum number of steps to get n 'A'.

// Example 1:
// Input: 3
// Output: 3
// Explanation:
// Intitally, we have one character 'A'.
// In step 1, we use Copy All operation.
// In step 2, we use Paste operation to get 'AA'.
// In step 3, we use Paste operation to get 'AAA'.
 
// Note:
// The n will be in the range [1, 1000].
class Solution {
public:
    // 1 means copy, 0 means paste
    int steps(int n,int totalAInCopy,int currentSum,int prev){
        if(n == currentSum){
            return 0;
        }

        if(currentSum > n){
            return 100000;
        }
        int ans1 = INT_MAX, ans2 = INT_MAX;
        if(prev == 1){
            // currentSum += totalAInCopy;
            ans1 = 1 + steps(n,totalAInCopy,currentSum + totalAInCopy,0);
        }

        if(prev == 0){
            ans2 = 1 + min(steps(n,currentSum,currentSum,1),steps(n,totalAInCopy,currentSum + totalAInCopy,0));
        }

        return min(ans1,ans2);
    }
    int minSteps(int n) {
        if(n == 1){
            return 0;
        }

        return 1 + steps(n,1,1,1);
    }
};