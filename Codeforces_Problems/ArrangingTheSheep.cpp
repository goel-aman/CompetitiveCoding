#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// Arranging The Sheep

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll length; cin>>length;
        string input;cin>>input;
        vector<ll> forward(length,0),backward(length,0);
        ll starCount = 0,dotCount = 0;
        for(ll i=0;i<length;i++){
            if(input[i] == '.'){
                dotCount++;
                if(i - 1 >= 0){
                    forward[i] = forward[i - 1] + starCount;
                }
            }else{
                starCount++;
                if(i - 1 >= 0){
                    forward[i] = forward[i - 1];
                }
            }
        }
        starCount = 0,dotCount = 0;
        for(int i=length - 1;i>=0;i--){
            if(input[i] == '.'){
                dotCount++;
                if(i + 1 < length){
                    backward[i] =  backward[i + 1] + starCount;
                }
            }else{
                starCount++;
                if(i + 1 < length){
                    backward[i] = backward[i + 1];
                }
            }
        }
        ll ans = LLONG_MAX;
        ans = min(ans,backward[0]);
        ans = min(ans,forward[length - 1]);
        for(int i=0;i<length - 1;i++){
            ans = min(ans,forward[i] + backward[i + 1]);
        }        
        cout<<ans<<endl;
    }
    return 0;
}