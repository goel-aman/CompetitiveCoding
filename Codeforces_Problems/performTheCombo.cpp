#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        string s;cin>>s;
        ll arr[26];

        for(ll i=0;i<26;i++){
            arr[i] = 0;
        }
        
        unordered_map<ll,vector<ll>> um;
        vector<ll> temp(26,0);
        for(int i=0;i<n;i++){
            temp[s[i] - 'a']++;
            um[i + 1] = temp;
        }

        for(ll i=0;i<m;i++){
            ll right;cin>>right;
            for(int j=0;j<26;j++){
                arr[j] += um[right][j];
            }
        }

        for(int i=0;i<s.length();i++){
            arr[s[i] - 'a']++;
        }

        for(int i=0;i<26;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}