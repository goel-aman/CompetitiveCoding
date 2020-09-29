#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
#define ll long long int

ll funct(ll x,string s,set<long long int> se){
    if(s.length() == 1){
        if( s[0] == '>'){
            set<long long int>::iterator it = se.begin();
            if(x > *it){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        set<long long int>::iterator it = se.begin();
        if( x < *it){
            return 1;
        }
        else{
            return 0;
        }
    }

    ll sum = 0;

    if(s[0] == '<'){
        for(auto y : se){
            if( x < y){
                set<long long int> ss = se;
                ss.erase(y);
                sum += funct(y,s.substr(1),ss);
            }
        }
    }

    if(s[0] == '>'){
        for(auto y : se){
            if( x > y){
                set<long long int> ss = se;
                ss.erase(y);
                sum += funct(y,s.substr(1),ss);
            }
        }
    }

    return sum;
}

int main(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    set<long long int> se;
    for(ll i=1;i<=n;i++){
        se.insert(i);
    }
    ll value = 0;
    for(auto x : se){
        set<long long int> newset = se;
        newset.erase(x);
        value += funct(x,s,newset);
    }
    cout<<value<<endl;
    return 0;
}