#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// B. Sort the Array

int main(){
    ll n;
    cin>>n;
    vector<ll> a;
    for(int i=0;i<n;i++){
        ll element;
        cin>>element;
        
        a.push_back(element);
    }

    int l = 0;
    while(l + 1 < n && a[l] < a[l + 1]){
        l++;
    }
    int r = l + 1;
    while(r < n && a[r] < a[r - 1]){
        r++;
    }

    reverse(a.begin() + l,a.begin() + r);
    for(int i=1;i<n;i++){
        if(a[i] < a[i - 1]){
            cout<<"no"<<endl;
            return 0;
        }
    }

    cout<<"yes"<<endl;
    cout<<l + 1 << " "<<r<<endl;
    return 0;
}