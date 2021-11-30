#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<int> rotateRight(vector<int>& arr,int rotateBy){
    int arrLength = arr.size();
    vector<int> ans;
    int value = rotateBy%arrLength;

    for(int i=arrLength - value;i<arrLength;i++){
        ans.push_back(arr[i]);
    }

    for(int i=0;i<arrLength - value;i++){
        ans.push_back(arr[i]);
    }
    return ans;
}


vector<int> rotateLeft(vector<int>& arr,int rotateBy){
    """
        input: 

        Algorithm:  

        Ouput: 
    """
    int arrLength = arr.size();
    vector<int> ans;
    int value = rotateBy%arrLength;
    
    for(int i=value;i<arrLength;i++){
        ans.push_back(arr[i]);
    }

    for(int i=0;i<value;i++){
        ans.push_back(arr[i]);
    }

    return ans;
}

int main(){
    vector<int> arr;
    int numberOfElements;
    cin>>numberOfElements;
    for(int i=0;i<numberOfElements;i++){
        int number;
        cin>>number;
        arr.push_back(number);
    }
    int rotateBy;
    cin>>rotateBy;
    vector<int> rotateRightAns,rotateLeftAns;
    rotateRightAns = rotateRight(arr,rotateBy);
    for(auto var : rotateRightAns){
        cout<<var<<" ";
    }
    cout<<endl;
 
    rotateLeftAns = rotateLeft(arr,rotateBy);
    for(auto var : rotateLeftAns){
        cout<<var<<" ";
    }
    cout<<endl;
    return 0;
}