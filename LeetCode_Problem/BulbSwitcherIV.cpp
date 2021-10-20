#include<bits/stdc++.h>
using namespace std;

// 1529. Bulb Switcher IV
// There is a room with n bulbs, numbered from 0 to n - 1,
//  arranged in a row from left to right. Initially, all 
// the bulbs are turned off.

// Your task is to obtain the configuration represented by 
// target where target[i] is '1' if the ith bulb is turned 
// on and is '0' if it is turned off.

// You have a switch to flip the state of the bulb, a flip 
// operation is defined as follows:

// Choose any bulb (index i) of your current configuration.
// Flip each bulb from index i to index n - 1.
// When any bulb is flipped it means that if it is '0' it 
// changes to '1' and if it is '1' it changes to '0'.

// Return the minimum number of flips required to form target.

// Example 1:
// Input: target = "10111"
// Output: 3
// Explanation: Initial configuration "00000".
// flip from the third bulb:  "00000" -> "00111"
// flip from the first bulb:  "00111" -> "11000"
// flip from the second bulb:  "11000" -> "10111"
// We need at least 3 flip operations to form target.

// Example 2:
// Input: target = "101"
// Output: 3
// Explanation: "000" -> "111" -> "100" -> "101".

// Example 3:
// Input: target = "00000"
// Output: 0

// Example 4:
// Input: target = "001011101"
// Output: 5
 
// Constraints:
// 1 <= target.length <= 105
// target[i] is either '0' or '1'.

class Solution {
public:
    int minFlips(string target) {
        int targetLength = target.length();
        string current = "";
        for(int i=0;i<targetLength;i++){
            current += "0";
        }
        int flip = 0;
        bool nextState = true;
        for(int i=0;i<targetLength;i++){
            char val = current[i];
            if(nextState == false){
                if(val == '0'){
                    val = '1';
                }else{
                    val = '0';
                }
            } 

            if(target[i] == val){
                continue;
            }else{
                nextState = !nextState;
                flip++;
            }
        }
        return flip;
    }
};