// 1202. Smallest String With Swaps

// You are given a string s, and an array of pairs of indices in the string
//  pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
// You can swap the characters at any pair of indices in the given pairs any 
// number of times.
// Return the lexicographically smallest string that s can be changed to after
//  using the swaps.

// Example 1:
// Input: s = "dcab", pairs = [[0,3],[1,2]]
// Output: "bacd"
// Explaination: 
// Swap s[0] and s[3], s = "bcad"
// Swap s[1] and s[2], s = "bacd"

// Example 2:
// Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
// Output: "abcd"
// Explaination: 
// Swap s[0] and s[3], s = "bcad"
// Swap s[0] and s[2], s = "acbd"
// Swap s[1] and s[2], s = "abcd"

// Example 3:
// Input: s = "cba", pairs = [[0,1],[1,2]]
// Output: "abc"
// Explaination: 
// Swap s[0] and s[1], s = "bca"
// Swap s[1] and s[2], s = "bac"
// Swap s[0] and s[1], s = "abc"
 

// Constraints:
// 1 <= s.length <= 10^5
// 0 <= pairs.length <= 10^5
// 0 <= pairs[i][0], pairs[i][1] < s.length
// s only contains lower case English letters.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findParent(vector<int> &parent,int x){
        if(parent[x] == -1){
            return x;
        }

        return parent[x] = findParent(parent,parent[x]);
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int sLength = s.size();
        vector<int> parent(sLength, -1);

        // an unorderd map which will contain all the parents as key and all its childrens as value (vector)
        unordered_map<int,vector<int>> um;
        for(auto pair : pairs){
            int xpar = findParent(parent,pair[0]);
            int ypar = findParent(parent,pair[1]);
            if(xpar != ypar){
                parent[xpar] = ypar;
            }
        }

        for(int i=0;i<sLength;i++){
            um[findParent(parent,i)].push_back(i);
        }

        for(auto x : um){
            string ss = "";
            for(auto m : x.second){
                ss += s[m];
            }
            sort(ss.begin(),ss.end());
            int counter = 0;
            for(auto m : x.second){
                s[m] = ss[counter];
                counter++;
            }
        }
        return s;
    }
};