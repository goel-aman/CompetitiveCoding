#include<bits/stdc++.h>
using namespace std;

// 318. Maximum Product of Word Lengths
// Given a string array words, return the maximum value of
//  length(word[i]) * length(word[j]) where the two words 
// do not share common letters. If no such two words exist,
//  return 0.

// Example 1:
// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".

// Example 2:
// Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4
// Explanation: The two words can be "ab", "cd".

// Example 3:
// Input: words = ["a","aa","aaa","aaaa"]
// Output: 0
// Explanation: No such pair of words.
 
// Constraints:
// 2 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// words[i] consists only of lowercase English letters.

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> wordNumber;
        vector<int> wordLength;
        int wordsLength = words.size();
        for(int i=0;i<wordsLength;i++){
            int num = 0;
            for(int j=0;j<words[i].length();j++){
                int ch = words[i][j] - 'a' + 1;
                num = (num | (1<<ch));
            }
            wordLength.push_back(words[i].length());
            wordNumber.push_back(num);
        }
        int ans = 0;

        for(int i=0;i<wordsLength;i++){
            for(int j=0;j<wordsLength;j++){
                if((wordNumber[i]&wordNumber[j]) == 0){
                    ans = max(ans,wordLength[i]*wordLength[j]);
                }
            }
        }
        return ans;
    }
};