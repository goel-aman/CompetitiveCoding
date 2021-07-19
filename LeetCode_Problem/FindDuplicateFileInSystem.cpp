#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        int pathsLength = paths.size();
        unordered_map<string,vector<string>> um;
        vector<vector<string>> temp;
        for(int i=0;i<pathsLength;i++){
            vector<string> tokens;
            string intermediate;
            stringstream check1(paths[i]);

            while(getline(check1,intermediate,' ')){
                tokens.push_back(intermediate);
            }
            string fileContent;
            int tokensLength = tokens.size();
            
            for(int i=1;i<tokensLength;i++){
                int breakPoint = 0;
                
                for(int j=0;j<tokens[i].length();j++){
                    if(tokens[i][j] == '('){
                        breakPoint = j;
                    }
                }
                fileContent = tokens[i].substr(breakPoint);
                string directory = tokens[i].substr(0,breakPoint);
                string temp = tokens[0] + "/" + directory;
                um[fileContent].push_back(temp);
            }
        }
        for(auto var : um){
            if(var.second.size() > 1){
                ans.push_back(var.second);    
            }
        }
        return ans;
    }
};