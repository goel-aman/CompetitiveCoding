#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll n; cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll maxStreak = 1;
    ll length = 1;
    for(ll i=1;i<n;i++){
        if(arr[i] >= arr[i-1]){
            length++;
            if(length > maxStreak){
                maxStreak = length;
            }
            continue;
        }
        length = 1;
    }
    cout<<maxStreak<<endl;
    return 0;
}