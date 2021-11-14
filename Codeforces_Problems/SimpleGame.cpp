#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// Simple Game


int main(){
    ll n,m;
    cin>>n>>m;
    ll first = n - m;
    ll left = m - 1;
    if(n == 1){
        cout<<1<<endl;
        return 0;
    }
    if(first > left){
        cout<<m + 1<<endl;
    }else{
        cout<<m - 1<<endl;
    }
    return 0;
}