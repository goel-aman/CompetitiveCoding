// 1170. Compare Strings by Frequency of the Smallest Character

// Let the function f(s) be the frequency of the lexicographically smallest character 
// in a non-empty string s. For example, if s = "dcce" then f(s) = 2 because the 
// lexicographically smallest character is 'c', which has a frequency of 2.

// You are given an array of strings words and another array of query strings queries.
//  For each query queries[i], count the number of words in words such that 
// f(queries[i]) < f(W) for each W in words.

// Return an integer array answer, where each answer[i] is the answer to the ith query.

// Example 1:
// Input: queries = ["cbd"], words = ["zaaaz"]
// Output: [1]
// Explanation: On the first query we have f("cbd") = 1, f("zaaaz") = 3 so f("cbd") < f("zaaaz").

// Example 2:
// Input: queries = ["bbb","cc"], words = ["a","aa","aaa","aaaa"]
// Output: [1,2]
// Explanation: On the first query only f("bbb") < f("aaaa"). On the second query both f("aaa") and f("aaaa") are both > f("cc").
 
// Constraints:
// 1 <= queries.length <= 2000
// 1 <= words.length <= 2000
// 1 <= queries[i].length, words[i].length <= 10
// queries[i][j], words[i][j] consist of lowercase English letters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateFrequencyOflexographicallySmallestCharacter(string s){
        char compare = 'z' + 1;
        int frequency = 0;
        int sLength = s.length();
        for(int i=0;i < sLength;i++){
            if(s[i] < compare){
                compare = s[i];
                frequency = 1;
                continue;
            }
            if(s[i] == compare){
                frequency++;
                continue;
            }
        }
        return frequency;
    }
    int greaterThanMe(vector<int> &word,int num){
        int wordLength = word.size();
        int answer = wordLength;
        int start = 0;
        int end = wordLength - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(word[mid] > num){
                answer = mid;
                end = mid - 1;
                continue;
            }

            if(word[mid] <= num){
                start = mid + 1;
                continue;
            }
        }
        int value = wordLength  - answer;
        return value;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> querie;
        vector<int> word;
        int queriesLength = queries.size();
        int wordsLength = words.size();
        for(int i=0;i<queriesLength;i++){
            querie.push_back(calculateFrequencyOflexographicallySmallestCharacter(queries[i]));
        }
        for(int i=0;i<wordsLength;i++){
            word.push_back(calculateFrequencyOflexographicallySmallestCharacter(words[i]));
        }
        sort(word.begin(),word.end());
        vector<int> ans;
        for(int i=0;i<queriesLength;i++){
            int val = greaterThanMe(word,querie[i]);
            ans.push_back(val);
        }
        return ans;
    }
};