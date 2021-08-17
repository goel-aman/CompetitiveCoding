#include<bits/stdc++.h>
using namespace std;

// 1156. Swap For Longest Repeated Character Substring
// Given a string text, we are allowed to swap two of the 
// characters in the string. Find the length of the longest
//  substring with repeated characters.

// Example 1:
// Input: text = "ababa"
// Output: 3
// Explanation: We can swap the first 'b' with the last 'a', 
// or the last 'b' with the first 'a'. Then, the longest 
// repeated character substring is "aaa", which its length is 3.

// Example 2:
// Input: text = "aaabaaa"
// Output: 6
// Explanation: Swap 'b' with the last 'a' (or the first 'a'), and 
// we get longest repeated character substring "aaaaaa", which its
//  length is 6.

// Example 3:
// Input: text = "aaabbaaa"
// Output: 4

// Example 4:
// Input: text = "aaaaa"
// Output: 5
// Explanation: No need to swap, longest repeated character 
// substring is "aaaaa", length is 5.

// Example 5:
// Input: text = "abcdef"
// Output: 1

// Constraints:
// 1 <= text.length <= 20000
// text consist of lowercase English characters only.

class Solution {
public:
    int maxRepOpt1(string text) {
        int textLength = text.length();
        vector<pair<char,int>> vec;
        unordered_map<char,int> count;
        int ans = 1;
        char current = text[0];
        int currentStreak = 1;
        count[current]++;
        for(int i=1;i<textLength;i++){
            count[text[i]]++;
            if(text[i] != current){
                ans = max(ans,currentStreak);
                vec.push_back({current,currentStreak});
                current = text[i];
                currentStreak = 1;
            }
            else{
                currentStreak++;
                ans = max(ans,currentStreak);
            }
        }            
        vec.push_back({current,currentStreak});
        int vecLength = vec.size();
        for(int i=0;i<=vecLength-1;i++){
            if(i + 2 >= vecLength){
                if(vec[i].second < count[vec[i].first]){
                    ans = max(ans,vec[i].second + 1);
                }
                continue;
            }
            if(vec[i].first == vec[i + 2].first && vec[i + 1].second == 1 && count[vec[i].first] >= vec[i].second + vec[i + 2].second + 1){
                ans = max(ans,1 + vec[i].second + vec[i + 2].second);
                continue;
            }
            
            if(vec[i].first == vec[i + 2].first && vec[i + 1].second == 1){

                ans = max(ans,vec[i].second + vec[i + 2].second);
                continue;
            }
            
            if(count[vec[i].first] > vec[i].second){
                ans = max(ans,vec[i].second + 1);
            }
        }
        return ans;
    }
};