#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n; // number of university and number of students.
        unordered_map<ll,vector<ll>> um;
        ll university[n];
        for(int i=0;i<n;i++){
            cin>>university[i];
        }
    
        for(int i=0;i<n;i++){
            ll value;
            cin>>value;
            um[university[i]].push_back(value);
        }
        vector<vector<ll>> veccc;
        for(auto x : um){
            vector<ll> temp = x.second;
            sort(temp.begin(),temp.end(),greater<int>());
            for(int i = 1;i<temp.size();i++){
                temp[i] = temp[i] + temp[i - 1];
            }
            veccc.push_back(temp);
        }

        for(int i=1;i<=n;i++){
            ll answer = 0;
            for(auto &x : veccc){
                ll length = x.size();
                ll totalcase = length / i;
                ll tillWhere =(totalcase * i) - 1;
                if(tillWhere <  0){
                    answer += 0;
                    continue;
                }
                answer += x[tillWhere];
            }   
            cout<<answer<<" ";
        }
        cout<<endl;
    }
    return 0;
}