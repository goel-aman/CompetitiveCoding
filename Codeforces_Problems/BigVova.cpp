#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        ll highestNumber = INT_MIN;
        ll highestIndex = -1;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i] > highestNumber){
                highestNumber = arr[i];
                highestIndex = i;
            }
        }
                
        map<ll,set<ll>> um;

        for(int i=2;i<=sqrt(highestNumber);i++){
            for(int j=0;j<n;j++){
                if(arr[j]%i == 0 && highestNumber%i == 0){
                    if(arr[j]%i == 0){
                        um[i].insert(j);
                    }
                    if(arr[j]%(highestNumber/i) == 0){
                        um[highestNumber/i].insert(j);
                    }
                    
                }
            }
        }
        
        unordered_map<int,bool> visited;
        visited[highestIndex] = true;
        cout<<highestNumber<<" ";
        // cout<<endl;
        vector<int> ans;
        for(auto it = um.rbegin();it != um.rend();++it){
            // cout<<"value is : "<<it->first<<endl;
            for(auto it2 = it->second.rbegin();it2 != it->second.rend();it2++){
                if(!visited.count(*it2)){
                    cout<<arr[*it2]<<" ";
                    visited[*it2] = true;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited.count(i)){
                cout<<arr[i]<<" ";
                visited[i] = true;
            }
        }
        cout<<endl;
    }
}