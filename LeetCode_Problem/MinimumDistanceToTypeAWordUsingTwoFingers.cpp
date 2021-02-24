// 1320. Minimum Distance to Type a Word Using Two Fingers


// You have a keyboard layout as shown above in the XY plane, where each English
// uppercase letter is located at some coordinate, for example, the letter A is 
// located at coordinate (0,0), the letter B is located at coordinate (0,1), the 
// letter P is located at coordinate (2,3) and the letter Z is located at coordinate (4,1).

// Given the string word, return the minimum total distance to type such string 
// using only two fingers. The distance between coordinates (x1,y1) and (x2,y2)
//  is |x1 - x2| + |y1 - y2|. 

// Note that the initial positions of your two fingers are considered free so don't
//  count towards your total distance, also your two fingers do not have to start at
//  the first letter or the first two letters.

// Example 1:
// Input: word = "CAKE"
// Output: 3
// Explanation: 
// Using two fingers, one optimal way to type "CAKE" is: 
// Finger 1 on letter 'C' -> cost = 0 
// Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
// Finger 2 on letter 'K' -> cost = 0 
// Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
// Total distance = 3

// Example 2:
// Input: word = "HAPPY"
// Output: 6
// Explanation: 
// Using two fingers, one optimal way to type "HAPPY" is:
// Finger 1 on letter 'H' -> cost = 0
// Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
// Finger 2 on letter 'P' -> cost = 0
// Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
// Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
// Total distance = 6

// Example 3:
// Input: word = "NEW"
// Output: 3

// Example 4:
// Input: word = "YEAR"
// Output: 7

// Constraints:
// 2 <= word.length <= 300
// Each word[i] is an English uppercase letter.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string,int> um;
    public:

    vector<int> computeIndex(char alphabet){
        int val = alphabet - 'A';
        int row = val / 6;
        int col = val % 6;
        vector<int> ans;
        ans.push_back(row);
        ans.push_back(col);
        return ans;
    }

    int getAnswer(string word,vector<int> position1,vector<int> position2){
        
        if(word.length() == 0){
            return 0;
        }

        if(position1.size() == 0 && position2.size() == 0){
            position1 = computeIndex(word[0]);
            return getAnswer(word.substr(1),position1,position2);
        }

        string s = word + ";" ;
        if(position1.size() != 0){
            s += to_string(position1[0]);
            s += to_string(position1[1]);
        }
        else{
            s += ";";
        }

        if(position2.size() != 0){
            s += to_string(position2[0]);
            s += to_string(position2[1]);
        }else{
            s += ";";
        }

        if(um.count(s) > 0){
            return um[s];
        }

        vector<int> val = computeIndex(word[0]);
        int fromPosition1 = INT_MAX;
        int fromPosition2 = INT_MAX;
        int finalAns = INT_MAX;

        if(position1.size() == 0){
            fromPosition1 = 0;
            vector<int> position11 = {val[0],val[1]};
            finalAns = min(finalAns,getAnswer(word.substr(1),position11,position2) + fromPosition1);
        }
        else{
            fromPosition1 = abs(val[0] - position1[0]) + abs(val[1] - position1[1]);
            vector<int> position11 = {val[0],val[1]};
            finalAns = min(finalAns,getAnswer(word.substr(1),position11,position2) + fromPosition1);

        }

        if(position2.size() == 0){
            fromPosition2 = 0;
            vector<int> position22 = {val[0],val[1]};
            finalAns = min(finalAns,getAnswer(word.substr(1),position1,position22) + fromPosition2);
        }else{
            fromPosition2 = abs(val[0] - position2[0]) + abs(val[1] - position2[1]);
            vector<int> position22 = {val[0],val[1]};
            finalAns = min(finalAns,getAnswer(word.substr(1),position1,position22) + fromPosition2);
        }
        return um[s] = finalAns;
    }
    
    int minimumDistance(string word) {
        vector<int> first;
        vector<int> second;
        return getAnswer(word,first,second);
    }
};

