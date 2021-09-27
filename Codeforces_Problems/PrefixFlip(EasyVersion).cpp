#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(a[i] != b[i]){
                ans.push_back(i + 1);
                ans.push_back(1);
                ans.push_back(i + 1);
            }
        }
        cout<<ans.size()<<" ";
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}