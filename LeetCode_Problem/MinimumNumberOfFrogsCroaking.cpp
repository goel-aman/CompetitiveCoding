#include<bits/stdc++.h>
using namespace std;

// 1419. Minimum Number of Frogs Croaking
// Given the string croakOfFrogs, which represents a 
// combination of the string "croak" from different frogs,
//  that is, multiple frogs can croak at the same time,
//  so multiple “croak” are mixed. Return the minimum number
//  of different frogs to finish all the croak in the 
// given string.

// A valid "croak" means a frog is printing 5 letters 
// ‘c’, ’r’, ’o’, ’a’, ’k’ sequentially. The frogs have
//  to print all five letters to finish a croak. If the
//  given string is not a combination of valid "croak"
//  return -1.

// Example 1:
// Input: croakOfFrogs = "croakcroak"
// Output: 1 
// Explanation: One frog yelling "croak" twice.

// Example 2:
// Input: croakOfFrogs = "crcoakroak"
// Output: 2 
// Explanation: The minimum number of frogs is two. 
// The first frog could yell "crcoakroak".
// The second frog could yell later "crcoakroak".

// Example 3:
// Input: croakOfFrogs = "croakcrook"
// Output: -1
// Explanation: The given string is an invalid combination
//  of "croak" from different frogs.

// Example 4:
// Input: croakOfFrogs = "croakcroa"
// Output: -1
 
// Constraints:
// 1 <= croakOfFrogs.length <= 10^5
// All characters in the string are: 'c', 'r', 'o', 'a' or 'k'.

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,int> um;
        vector<int> frequency(5,0);
        um['c'] = 0;
        um['r'] = 1;
        um['o'] = 2;
        um['a'] = 3;
        um['k'] = 4;
        int ans = 0;
        int length = croakOfFrogs.length();
        for(int i=0;i<length;i++){
            int index = um[croakOfFrogs[i]];
            frequency[index]++;
            ans = max(ans,frequency[um[croakOfFrogs[i]]]);
            if(frequency[0] > 0 && frequency[1] > 0 && frequency[2] > 0 && frequency[3] > 0 && frequency[4] > 0){
                frequency[0]--;frequency[1]--;frequency[2]--;frequency[3]--;frequency[4]--;
            }

            for(int j = index -1;j>=0;j--){
                if(frequency[index] > frequency[j]){
                    return -1;
                }
            }
        }
        for(int i=0;i<5;i++){
            if(frequency[i] != 0){
                return -1;
            }
        }
        return ans;
    }
};