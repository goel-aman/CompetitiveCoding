#include<bits/stdc++.h>
using namespace std;

// 1239. Maximum Length of a Concatenated String with Unique Characters
// Given an array of strings arr. String s is a 
// concatenation of a sub-sequence of arr which
//  have unique characters.
// Return the maximum possible length of s.

// Example 1:
// Input: arr = ["un","iq","ue"]
// Output: 4
// Explanation: All possible concatenations are 
// "","un","iq","ue","uniq" and "ique".
// Maximum length is 4.

// Example 2:
// Input: arr = ["cha","r","act","ers"]
// Output: 6
// Explanation: Possible solutions are
//  "chaers" and "acters".

// Example 3:
// Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
// Output: 26
 
// Constraints:
// 1 <= arr.length <= 16
// 1 <= arr[i].length <= 26
// arr[i] contains only lower case English letters.



class Solution {
    int vecLength;
    int ans = 0;
public:
    void solve(vector<int>& vec,int index,int prevValue){
        if(index == vecLength){
            int temp = prevValue;
            int count = 0;
            while(temp > 0){
                int lastDigit = (temp&1);
                if(lastDigit == 1){
                    count++;
                }
                temp = (temp>>1);
            }
            ans = max(ans,count);
            return ;
        }

        // lets try to include the current index
        int val = (prevValue&vec[index]);
        if(val == 0){
            int next = (prevValue | vec[index]);
            solve(vec,index + 1,next);
        }

        // lets try skipping the current index
        solve(vec,index + 1,prevValue);
        return ;
    }

    int maxLength(vector<string>& arr) {
        int arrLength = arr.size();
        vector<int> vec;
        for(int i=0;i<arrLength;i++){
            int number = 0;
            int gotAnswer = true;
            unordered_map<char,int> um;
            for(int j=0;j<arr[i].length();j++){
                int val = arr[i][j] - 'a';
                um[val]++;
                if(um[val] > 1){
                    gotAnswer = false;
                    break;
                }
                int value = (1<<val);
                number = (number | value);
            }
            if(gotAnswer == true){
                vec.push_back(number);
            }
        }
        vecLength = vec.size();
        solve(vec,0,0);
        return ans;
    }
};