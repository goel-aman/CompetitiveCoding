#include<bits/stdc++.h>
using namespace std;

// 692. Top K Frequent Words
// Given a non-empty list of words, return
//  the k most frequent elements.
// Your answer should be sorted by frequency
//  from highest to lowest. If two words have
//  the same frequency, then the word with the
//  lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
// with the number of occurrence being 4, 3, 2 and 1 respectively.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.


class element{
    public:
    string word;
    int frequency;
};

bool compare(element& a,element& b){
    if(a.frequency > b.frequency){
        return true;
    }

    if(a.frequency == b.frequency){
        if(a.word < b.word){
            return true;
        }
    }
    return false;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int wordLength = words.size();
        unordered_map<string,int> um;
        for(int i=0;i<wordLength;i++){
            um[words[i]]++;
        }

        vector<element> vec;
        for(auto var : um){
            vec.push_back({var.first,var.second});
        }

        sort(vec.begin(),vec.end(),compare);
        vector<string> ans;
        for(int i=0;i<k;i++){
            ans.push_back(vec[i].word);
        }
        return ans;
    }
};