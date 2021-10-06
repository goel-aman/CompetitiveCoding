#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    ll n;
    cin>>n;
    vector<ll> frequency(10,1);
    ll resultOfMultiplication = 1;
    ll position = 0;
    while(resultOfMultiplication < n){
        position = position%10;
        ll prev = frequency[position];
        frequency[position]++;
        resultOfMultiplication /= prev;
        resultOfMultiplication *= frequency[position];
        position++;
    }

    string ans = "codeforces";
    for(int i=0;i<10;i++){
        for(int j=0;j<frequency[i];j++){
            cout<<ans[i];
        }
    }
    cout<<endl;
}