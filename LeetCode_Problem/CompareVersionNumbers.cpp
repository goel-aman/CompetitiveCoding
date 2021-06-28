#include<bits/stdc++.h>
using namespace std;

// 165. Compare Version Numbers

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> first;
        vector<int> second;
        
        stringstream check1(version1);
      
        string intermediate;
      
        // Tokenizing w.r.t. space ' '
        while(getline(check1, intermediate, '.'))
        {
            first.push_back(stoi(intermediate));
        }

        stringstream check2(version2);
        // string intermediate;

        while(getline(check2,intermediate,'.')){
            second.push_back(stoi(intermediate));
        }

        int firstLength = first.size();
        int secondLength = second.size();
        int maxLength = max(firstLength,secondLength);
        if(firstLength < secondLength){
            for(int i=0;i<secondLength - firstLength;i++){
                first.push_back(0);
            }
        }

        if(secondLength < firstLength){
            for(int i=0;i<firstLength - secondLength;i++){
                second.push_back(0);
            }
        }

        for(int i=0;i<maxLength;i++){
            if(first[i] > second[i]){
                return 1;
            }

            if(second[i] > first[i]){
                return -1;
            }
        }
        return 0;
    }
};