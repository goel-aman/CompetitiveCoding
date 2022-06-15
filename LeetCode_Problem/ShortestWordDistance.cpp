#include<bits/stdc++.h>
using namespace std;

// 243. Shortest Word Distance
// Given an array of strings wordsDict and two different strings 
// that already exist in the array word1 and word2, return the
//  shortest distance between these two words in the list.

// Example 1:
// Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"],
//  word1 = "coding", word2 = "practice"
// Output: 3

// Example 2:
// Input: wordsDict = ["practice", "makes", "perfect", "coding", "makes"],
//  word1 = "makes", word2 = "coding"
// Output: 1
 
// Constraints:
// 1 <= wordsDict.length <= 3 * 104
// 1 <= wordsDict[i].length <= 10
// wordsDict[i] consists of lowercase English letters.
// word1 and word2 are in wordsDict.
// word1 != word2

class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> word1Position,word2Position;
        int wordsDictLength = wordsDict.size();
        
        for(int i=0;i<wordsDictLength;i++){
            if(word1 == wordsDict[i]){
                word1Position.push_back(i);
            }else if(word2 == wordsDict[i]){
                word2Position.push_back(i);
            }
        }

        int ans = INT_MAX;
        for(int i=0;i<word1Position.size();i++){
            auto it = lower_bound(word2Position.begin(),word2Position.end(),word1Position[i]);
            int firstIndex = word1Position[i];
            int secondIndex = -1;
            if(it != word2Position.end()){
                secondIndex = it - word2Position.begin();
                ans = min(ans,abs(word2Position[secondIndex] - firstIndex));
            }
            if(it != word2Position.begin()){
                it--;
                secondIndex = it - word2Position.begin();
                ans = min(ans,abs(word2Position[secondIndex] - firstIndex));
            }
        }
        return ans;
    }
};