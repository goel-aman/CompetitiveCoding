// 854. K-Similar Strings

// Strings A and B are K-similar (for some non-negative integer K) if we can swap the 
// positions of two letters in A exactly K times so that the resulting string equals B.

// Given two anagrams A and B, return the smallest K for which A and B are K-similar.

// Example 1:
// Input: A = "ab", B = "ba"
// Output: 1

// Example 2:
// Input: A = "abc", B = "bca"
// Output: 2

// Example 3:
// Input: A = "abac", B = "baca"
// Output: 2

// Example 4:
// Input: A = "aabc", B = "abca"
// Output: 2
// Note:

// 1 <= A.length == B.length <= 20
// A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,bool> um;
public:
    vector<string> getMeaningfulNeighbours(string s,string b){
        vector<string> v;

        int i=0;
        int sLength = s.length();
        for(;i<sLength;i++){
            if(s[i] != b[i]){
                break;
            }
        }

        for(int j=i + 1;j<sLength;j++){
            if(s[j] == b[i]){
                string temp = s;
                char store = temp[i];
                temp[i] = temp[j];
                temp[j] = store;
                v.push_back(temp);
            }
        }
        return v;
    }

    int kSimilarity(string A, string B) {
        if(A == B){
            return 0;
        }

        int level = 0;
        
        queue<string> q;
        q.push(A);
        um[A] = true;
        while(!q.empty()){
            level++;
            int len = q.size();
            while(len--){
                string front = q.front();
                q.pop();
                int frontLength = front.length();
                if(front == B){
                    return level - 1; 
                }

                vector<string> get = getMeaningfulNeighbours(front,B);
                for(auto var : get){
                    if(!um.count(var)){
                        if(var == B){
                            return level;
                        }
                        um[var] = true;
                        q.push(var);
                    }
                }
            }
        }
        return level;
    }
};