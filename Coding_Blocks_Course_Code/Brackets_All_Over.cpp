#include<iostream>
#include<bit/stdc++.h>
using namespace std;
#define ll long long int

ll funct(string s,ll n,ll m){
    ll prev_count = 0;
    ll post_count = 0;
    stack<char> s;
    for(int i=0;i<m;i++){
        if(s[i] == ')'){
            if(!s.empty()){
                s.pop();
                continue;
            }
            prev_count++;
        }
        if(s[i] == '('){
            s.push_back('(');
        }
    }
    ll left = s.size();
    post_count++;
    if(post_count + prev_count > n - m){
        cout<<-1<<endl;
    }
    
}

int main(){
    ll n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    cout<<funct(s,n,m)<<endl;
    return 0;
}