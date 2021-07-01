#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll a[n];
        ll unique = 0;
        unordered_set<ll> um;
        unordered_map<ll,ll> umm;
        vector<ll> elements;
        for(int i=0;i<n;i++){
            // cout<<"hi"<<endl;
            cin>>a[i];
            umm[a[i]]++;
            if(!um.count(a[i])){
                um.insert(a[i]);
                unique++;
                elements.push_back(a[i]);
            }
        }
        // cout<<"Value of unique is : "<<unique<<endl;
        
        
        ll maxFreq = 0;
        for(auto var : umm){
            // elements.push_back(var.first);
            maxFreq = max(var.second,maxFreq);
        }
        // cout<<"value of uniqque is : "<<unique<<endl;
        if(unique > k){
            cout<<-1<<endl;
            continue;
        }

        
        ll toBeAdded = k - elements.size();
        for(int i=1;i<=n && toBeAdded > 0;i++){
            if(!um.count(i)){
                um.insert(i);
                elements.push_back(i);
                toBeAdded -= 1;
            }
        }
        cout<<(n * elements.size())<<endl;
        ll elementsSize = elements.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<elementsSize;j++){
                cout<<elements[j]<<" ";
            }
        }       
        cout<<endl;
    }
    return 0;
}