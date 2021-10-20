#include<bits/stdc++.h>
using namespace std;

// 1781. Sum of Beauty of All Substrings
// The beauty of a string is the difference in 
// frequencies between the most frequent and 
// least frequent characters.

// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of
//  all of its substrings.

// Example 1:
// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty
//  are ["aab","aabc","aabcb","abcb","bcb"], each 
// with beauty equal to 1.

// Example 2:
// Input: s = "aabcbaa"
// Output: 17
 
// Constraints:
// 1 <= s.length <= 500
// s consists of only lowercase English letters.

class Solution {
public:
    int beautySum(string s) {
        int sLength = s.length();
        vector<vector<int>> frequencyCount(sLength,vector<int> (26,0));
        int ans = 0;
        for(int i=0;i<sLength;i++){
            if(i != 0){
                for(int j=0;j<26;j++){
                    frequencyCount[i][j] = frequencyCount[i - 1][j];
                }
            }
            int index = s[i] - 'a';
            frequencyCount[i][index]++;

            for(int j = -1;j<i;j++){
                if(j == -1){
                    int maxFrequency = INT_MIN;
                    int minFrequency = INT_MAX;
                    for(int it=0;it<26;it++){
                        if(frequencyCount[i][it] > 0){
                            maxFrequency = max(maxFrequency,frequencyCount[i][it]);
                            minFrequency = min(minFrequency,frequencyCount[i][it]);
                        }
                    }
                    ans += (maxFrequency - minFrequency);
                    continue;
                }
                
                int maxFrequency = INT_MIN;
                int minFrequency = INT_MAX;
                for(int it= 0;it<26;it++){
                    int count = frequencyCount[i][it] - frequencyCount[j][it];
                    if(count > 0){
                        maxFrequency = max(maxFrequency,count);
                        minFrequency = min(minFrequency,count);
                    }
                }
                
                ans += (maxFrequency - minFrequency);
            }
            
        }
        return ans;
    }
};