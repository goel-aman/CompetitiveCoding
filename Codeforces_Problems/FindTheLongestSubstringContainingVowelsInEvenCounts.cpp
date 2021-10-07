#include<bits/stdc++.h>
using namespace std;

// 1371. Find the Longest Substring Containing Vowels in Even Counts
// Given the string s, return the size of the longest substring containing
//  each vowel an even number of times. That is, 'a', 'e', 'i', 'o', and 'u'
//  must appear an even number of times.

// Example 1:
// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two 
// each of the vowels: e, i and o and zero of the vowels: a and u.

// Example 2:
// Input: s = "leetcodeisgreat"
// Output: 5
// Explanation: The longest substring is "leetc" which contains two e's.

// Example 3:
// Input: s = "bcbcbc"
// Output: 6
// Explanation: In this case, the given string "bcbcbc" is the longest because
//  all vowels: a, e, i, o and u appear zero times.
 
// Constraints:
// 1 <= s.length <= 5 x 10^5
// s contains only lowercase English letters.


class Solution {
public:
    int findTheLongestSubstring(string s) {
        int sLength = s.length();
        unordered_map<char,int> um;
        um['a'] = 1;
        um['e'] = 2;
        um['i'] = 3;
        um['o'] = 4;
        um['u'] = 5;
        unordered_map<char,int> frequency;
        unordered_map<int,int> findIndex;
        int number = 0;
        number = (number | 1<<1);
        number = (number | 1<<2);
        number = (number | 1<<3);
        number = (number | 1<<4);
        number = (number | 1<<5);
        int ans = INT_MIN;
        for(int i=0;i<sLength;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i'){
                frequency[s[i]]++;
            }

            int temp = 0;
            if(frequency['a']%2 == 0){
                temp = (temp | 1<<1);
            }

            if(frequency['e']%2 == 0){
                temp = (temp | 1<<2);
            }

            if(frequency['i']%2 == 0){
                temp = (temp | 1<<3);
            }

            if(frequency['o']%2 == 0){
                temp = (temp | 1<<4);
            }

            if(frequency['u']%2 == 0){
                temp = (temp | 1<<5);
            }

            if(temp == number){
                ans = max(ans,i + 1);
            }

            if(findIndex.count(temp) > 0){
                ans = max(ans,i - findIndex[temp]);
            }

            if(!findIndex.count(temp)){
                findIndex[temp] = i;
            }          


        }
        if(ans == INT_MIN){
            return 0;
        }
        return ans;
    }
};