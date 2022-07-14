#include<bits/stdc++.h>
using namespace std;

// 244. Shortest Word Distance II
// Design a data structure that will be initialized with 
// a string array, and then it should answer queries of 
// the shortest distance between two different strings
//  from the array.

// Implement the WordDistance class:
// WordDistance(String[] wordsDict) initializes the object 
// with the strings array wordsDict.
// int shortest(String word1, String word2) returns the shortest
//  distance between word1 and word2 in the array wordsDict.
 
// Example 1:
// Input
// ["WordDistance", "shortest", "shortest"]
// [[["practice", "makes", "perfect", "coding", "makes"]],
// ["coding", "practice"], ["makes", "coding"]]
// Output
// [null, 3, 1]

// Explanation
// WordDistance wordDistance = new WordDistance(["practice",
//  "makes", "perfect", "coding", "makes"]);
// wordDistance.shortest("coding", "practice"); // return 3
// wordDistance.shortest("makes", "coding");    // return 1

// Constraints:
// 1 <= wordsDict.length <= 3 * 104
// 1 <= wordsDict[i].length <= 10
// wordsDict[i] consists of lowercase English letters.
// word1 and word2 are in wordsDict.
// word1 != word2
// At most 5000 calls will be made to shortest.

class WordDistance {
    unordered_map<string,vector<int>> storePositions;
public:
    WordDistance(vector<string>& wordsDict) {
        int wordsDictLength = wordsDict.size();
        for(int i=0;i<wordsDictLength;i++){
            storePositions[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> word1Positions = storePositions[word1];
        vector<int> word2Positions = storePositions[word2];
        int i = 0, j = 0;
        int word1PositionsLength = word1Positions.size();
        int word2PositionsLength = word2Positions.size();
        
        int prevIndex = -1;
        bool prev = false;
        int ans = INT_MAX;
        while(i< word1PositionsLength && j < word2PositionsLength){
            int value1 = word1Positions[i];
            int value2 = word2Positions[j];
            if(value1 < value2){
                if(prevIndex == -1){
                    prev = true;
                    prevIndex = value1;
                }else{
                    if(prev == false){
                        ans = min(ans,value1 - prevIndex);
                    }
                    prev = true;
                    prevIndex = value1;
                }
                i++;
                if(i == word1PositionsLength){
                    ans = min(ans,abs(value2 - value1));
                }
            }else{
                if(prevIndex == -1){
                    prev = false;
                    prevIndex = value2;
                }else{
                    if(prev == true){
                        ans = min(ans,value2 - prevIndex);
                    }
                    prev = false;
                    prevIndex = value2;
                }
                j++;
                if(j == word2PositionsLength){
                    ans = min(ans,abs(value2 - value1));
                }
            }
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */