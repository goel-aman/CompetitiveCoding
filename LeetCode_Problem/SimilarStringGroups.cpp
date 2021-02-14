// 839. Similar String Groups

// Two strings X and Y are similar if we can swap two letters (in different positions) of X, 
// so that it equals Y. Also two strings X and Y are similar if they are equal.

// For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and 
// "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

// Together, these form two connected groups by similarity: {"tars", "rats", "arts"} 
// and {"star"}.  Notice that "tars" and "arts" are in the same group even though they 
// are not similar.  Formally, each group is such that a word is in the group if and 
// only if it is similar to at least one other word in the group.

// We are given a list strs of strings where every string in strs is an anagram
//  of every other string in strs. How many groups are there?

// Example 1:
// Input: strs = ["tars","rats","arts","star"]
// Output: 2

// Example 2:
// Input: strs = ["omv","ovm"]
// Output: 1

// Constraints:
// 1 <= strs.length <= 300
// 1 <= strs[i].length <= 300
// strs[i] consists of lowercase letters only.
// All words in strs have the same length and are anagrams of each other.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,string> parent;
    int siz;
public:
    
    string findParent(string input){
        if(parent[input] == input){
            return input;
        }

        return parent[input] = findParent(parent[input]);
    }

    void mergeParent(string input1,string input2){
        string s1 = findParent(input1);
        string s2 = findParent(input2);

        if(s1 != s2){
            siz--;
            parent[s1] = s2;
        }
        return ;
    }

    bool isSimilar(string s1,string s2){
        if(s1 == s2){
            return true;
        }
        int length = s1.length();
        int diff = 0;
        for(int i=0;i<length;i++){
            if(s1[i] != s2[i]){
                diff++;
                if(diff > 2){
                    return false;
                }
            }
        }
        if(diff == 2){
            return true;
        }
        return false;
    }
    
    int numSimilarGroups(vector<string>& strs) {
        for(auto str: strs){
            parent[str] = str;
        }
        siz = parent.size();
    
        int strLength = strs.size();
        for(int i=0;i<=strLength - 2;i++){
            for(int j=i + 1;j<=strLength - 1;j++){
                bool val = isSimilar(strs[i],strs[j]);
                if(val){
                    mergeParent(strs[i],strs[j]);
                }
            }
        }
        
        return siz;
    }
};


