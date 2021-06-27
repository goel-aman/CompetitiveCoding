#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll n;
    cin>>n;
    vector<ll> b;
    for(int i=0;i<n;i++){
        ll val;
        cin>>val;
        b.push_back(val);
    }
    sort(b.begin(),b.end());
    ll minElement = b[0];
    ll maxElement = b[n - 1];

    ll minOccurence = 1;
    ll maxOccurence = 1;
    
    for(int i=1;i<n;i++){
        if(b[i] == minElement){
            minOccurence++;
        }else{
            break;
        }
    }

    for(int i=n-2;i>=0;i--){
        if(b[i] == maxElement){
            maxOccurence++;
        }else{
            break;
        }
    }
    if(maxElement == minElement){
        ll value = ((maxOccurence - 1)* (maxOccurence) )/ 2;
        cout<<"0 "<<value<<endl;
        return 0;
    }
    cout<<maxElement - minElement<<" "<<minOccurence * maxOccurence<<endl;
    return 0;
}