#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll sLength = s.length();
        unordered_map<ll,ll> frequency;
        ll ans = 0;
        for(ll i=0;i<sLength;i++){
            frequency[s[i] - '0']++;
            ans = max(ans,frequency[s[i] - '0']);
        }

        for(int i=0;i<=9;i++){
            for(int j=0;j<=9;j++){
                if(i != j){
                    bool val = true;
                    int length = 0;
                    for(int k=0;k<sLength;k++){
                        
                        if(val == true && ((s[k] - '0') == i)){
                            length++;
                            val = (!val);
                        }

                        if(val == false && ((s[k] - '0') == j)){
                            length++;
                            val = (!val);
                        }
                    }
                    ans = max(ans,(length%2 == 0) ? (long long) length : (long long) length - 1);
                }
            }
        }

        cout<<sLength - ans<<endl;
    }
}