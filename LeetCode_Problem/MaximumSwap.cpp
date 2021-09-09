#include<bits/stdc++.h>
using namespace std;


bool compare(char& a,char &b){
    if(a > b){
        return true;
    }
    return false;
}

class Solution {
public:
    int maximumSwap(int num) {
        string input = to_string(num);
        string dummy = input;
        sort(input.begin(),input.end(),compare);
        int inputLength = input.length();
        int index = -1;
        for(int i=0;i<inputLength;i++){
            if(input[i] == dummy[i]){
                continue;
            }else{
                index = i;
                break;
            }
        }
        
        if(index == -1){
            return num;
        }

        int breakPoint = -1;
        char target = input[index];
        
        for(int i=dummy.length() - 1;i>=0;i--){
            if(target == dummy[i]){
                breakPoint = i;
                
                swap(dummy[breakPoint],dummy[index]);
                break;
            }
        }
        return stoi(dummy);
    }
};