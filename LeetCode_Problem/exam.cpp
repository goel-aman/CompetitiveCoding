#include<bits/stdc++.h>
using namespace std;

//  Write an encoder to convert the string in such a 
// way that, the repeated words are converted to <<no of
//  repeated words>+Word.. If its only one word, you can 
// leave it as is.
// Example: Raghunath -> R2ag2hunt

string solve(string input){
    int inputLength = input.length();
    vector<char> arr;
    unordered_set<char> unique;
    unordered_map<char,int> frequency;


    for(int i=0;i<inputLength;i++){
        frequency[input[i]]++;

        if(!unique.count(input[i])){
            arr.push_back(input[i]);
            unique.insert(input[i]);
        }
    }

    string output = "";
    for(int i=0;i<arr.size();i++){
        if(frequency[arr[i]] > 1){
            output += to_string(frequency[arr[i]]);
        }

        output += arr[i];
    }
    return output;
}

int main(){
    string input;
    cin>>input;
    cout<<solve(input)<<endl;
    return 0;
}