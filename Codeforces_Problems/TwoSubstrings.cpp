
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    string s;
    cin>>s;
    ll length = s.length();
    ll firstOccurence = -1,secondOccurence = -1;
    for(int i=0;i<length - 1;i++){
        if(s.substr(i,2) == "AB"){
            firstOccurence = i;
            break;
        }
    }

    for(int i=length - 2;i>=0;i--){
        if(s.substr(i,2) == "BA"){
            secondOccurence = i;
            break;
        }
    }
    
    if(abs(secondOccurence-firstOccurence) == 1){
        firstOccurence = -1;
        secondOccurence = -1;
        for(int i=0;i<length - 1;i++){
            if(s.substr(i,2) == "BA"){
                firstOccurence = i;
                break;
            }
        }

        for(int i=length-2;i>=0;i--){
            if(s.substr(i,2) == "AB"){
                secondOccurence = i;
                break;
            }
        }

        if(abs(secondOccurence-firstOccurence) == 1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    // cout<<"FirstOccurence : "<<firstOccurence<<" secondOccurence is : "<<secondOccurence<<endl;
    if(firstOccurence == -1 || secondOccurence == -1 ){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    return 0;
}