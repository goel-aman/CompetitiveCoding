#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = 0;
        
        int smallestLength = INT_MAX;
        for(int i=0;i<strs.size();i++){
            int value = strs[i].length();
            smallestLength = min(smallestLength,value);
        }

        for(int i=0;i<smallestLength;i++){
            char ch = strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(strs[j][i] != ch){
                    break;
                }
            }
            length++;
        }
        return strs[0].substr(0,length);
    }
};