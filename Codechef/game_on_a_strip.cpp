#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// chance is 1 then nayeon
// chance 0 is nyuzu.
bool game_strip(ll* a,ll &n,bool chance,unordered_map<bool,bool> isfirst,unordered_map<bool,long long int> umpos){
    if(isfirst[chance]){
        isfirst[chance] = false;
        for(ll i=0;i<n;i++){
            if(a[i] == 0){
                a[i] = 1;
                umpos[chance] = i;
                bool w = game_strip(a,n,!chance,isfirst,umpos);
                if(w == false){
                    return true;
                }
                a[i] = 0;
            }
        }
        return false;
    }

    ll w = umpos[chance];
    if( umpos[chance] + 1 < n && umpos[chance] + 1 >= 0 && a[umpos[chance] + 1] == 0){
        a[umpos[chance]  + 1]= 1;
        umpos[chance] = umpos[chance] + 1;
        bool k = game_strip(a,n,!chance,isfirst,umpos);
        if(k == false){
            return true;
        }
        a[w+1] = 0;
        umpos[chance] = w;
    }

    if(umpos[chance] - 1 < n && umpos[chance] - 1 >= 0 && a[umpos[chance] - 1] == 0){
        a[umpos[chance] - 1] = 1;
        umpos[chance] = umpos[chance] - 1;
        bool k = game_strip(a,n,!chance,isfirst,umpos);
        if(k == false){
            return true;
        }
    }
    return false;
}
//8
//1 0 1 1 1 0 0 1


5
1 0 0 0 1



int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++) { cin>>a[i]; }
        unordered_map<bool,bool> um;
        unordered_map<bool,long long int> umpos;
        um[true] = true;
        um[false] = true;
        bool x = game_strip(a,n,true,um,umpos); // if n is 1 then it is turn of nayeon
        if(x == true){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}