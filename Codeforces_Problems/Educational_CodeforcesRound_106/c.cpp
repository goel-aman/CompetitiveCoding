#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool solve(string s,string prevstate){

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string inputs = s;
        sort(s.begin(),s.end());
        if(inputs == s){
            cout<<"YES"<<endl;
            continue;
        }
        // 1 removed              // 0 means not removed;
       vector<string> out = solve(inputs,0);
    }
    return 0;
}