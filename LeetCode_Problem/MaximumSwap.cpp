#include<bits/stdc++.h>
using namespace std;

// 670. Maximum Swap
// You are given an integer num. You can swap two
//  digits at most once to get the maximum valued number.
// Return the maximum valued number you can get.

// Example 1:
// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.

// Example 2:
// Input: num = 9973
// Output: 9973
// Explanation: No swap.
 
// Constraints:
// 0 <= num <= 108

bool compare(char& a,char &b){
    if(a > b){
        return true;
    }
    return false;
}

class Solution {
public:
    int maximumSwap(int num) {
        string input = to_string(num);
        string dummy = input;
        sort(input.begin(),input.end(),compare);
        int inputLength = input.length();
        int index = -1;
        for(int i=0;i<inputLength;i++){
            if(input[i] == dummy[i]){
                continue;
            }else{
                index = i;
                break;
            }
        }
        
        if(index == -1){
            return num;
        }

        int breakPoint = -1;
        char target = input[index];
        
        for(int i=dummy.length() - 1;i>=0;i--){
            if(target == dummy[i]){
                breakPoint = i;
                
                swap(dummy[breakPoint],dummy[index]);
                break;
            }
        }
        return stoi(dummy);
    }
};