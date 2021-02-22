#include<bits/stdc++.h>
using namespace std;
#define ll long long int

unordered_map<int,int> um;

bool funct(ll &k,ll number){
    int count = 0;
    while(k > 0){
        if(k%number == 0){
            k = k / number;
            count++;
            continue;
        }
        
        if(k%number == 1){
            k = k - 1;
            um[count]++;
            if(um[count] > 1)
            {
                return false;
            }
            continue;
        }
        return false;
    }
    return true;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        um.clear();
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool ans = true;
        for(int i=0;i<n;i++){
            if(a[i] == 0){
                continue;
            }

            else{
                bool val = funct(a[i],k);
                if(val == false){
                    ans = false;
                    break;
                }
            }
        }
        if(ans){ cout<<"YES"<<endl;}
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}