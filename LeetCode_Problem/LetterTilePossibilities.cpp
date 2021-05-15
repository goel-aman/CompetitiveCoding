#include<bits/stdc++.h>
using namespace std;

// 1079. Letter Tile Possibilities

// You have n  tiles, where each tile has one letter
//  tiles[i] printed on it.
// Return the number of possible non-empty sequences of letters
//  you can make using the letters printed on those tiles.

// Example 1:
// Input: tiles = "AAB"
// Output: 8
// Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".

// Example 2:
// Input: tiles = "AAABBC"
// Output: 188

// Example 3:
// Input: tiles = "V"
// Output: 1
 
// Constraints:
// 1 <= tiles.length <= 7
// tiles consists of uppercase English letters.



class Solution {
    int tilesLength;
public:
    void Tile(string &tiles,int index,string &current,set<string> &s,unordered_map<char,int> &um){
        if(index == tilesLength){
            if(current.length() != 0){
                // cout<<"value of current is : "<<current<<endl;
                s.insert(current);
            }
            return ;
        }

        for(auto element : um){
            if(element.second > 0){
                current += element.first;
                um[element.first]--;
                Tile(tiles,index + 1,current,s,um);
                um[element.first]++;
                current.pop_back();
            }
        }
        
        Tile(tiles,index + 1, current,s,um);
        return ;
    }

    int numTilePossibilities(string tiles) {
        unordered_map<char,int> um;
        for(auto element : tiles){
            um[element]++;
        }
        tilesLength = tiles.length();
        int index = 0;
        set<string> s;
        string current = "";
        Tile(tiles,0,current,s,um);
        return s.size();
    }
};