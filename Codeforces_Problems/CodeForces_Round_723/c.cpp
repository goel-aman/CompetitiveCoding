#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll arr[] = {11,111,1111,11111,111111,1111111,11111111,111111111};
unordered_map<string,bool> um;

bool solve(ll n,ll index){
    if(n == 0){
        return true;
    }

    if(n < 11 || n < 0){
        return false;
    }

    if(index < 0){
        return false;
    }
    string s = to_string(n) + ";" + to_string(index);
    if(um.count(s)){
        return um[s];
    }
    if(arr[index] > n){
        return solve(n,index - 1);
    }

    ll maxNum = (n / arr[index]);
    for(int i=maxNum;i>=0;i--){
        bool ans = solve(n - (arr[index] * i),index - 1);
        if(ans == true){
            return um[s] =  true;
        }
    }
    return um[s] = false;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(solve(n,6)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}