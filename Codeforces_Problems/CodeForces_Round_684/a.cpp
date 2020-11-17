#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define p push
#define doublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,c0,c1,h;
        cin>>n>>c0>>c1>>h;
        string s;cin>>s;
        if(c0 == c1){
            cout<< n * c0 <<endl;
            continue;
        }
        int count_0 = 0;
        int count_1 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                count_0++;
            }
            else{
                count_1++;
            }
        }
        int ans;
        if(c0 < c1 && (h + c0) < c1){
            ans = c0 * count_0 + (c0 + h) * count_1;
            cout<<ans<<endl;
            continue;
        }

        if(c1 < c0 && (c1 + h) < c0){
            ans = (c1 + h) * count_0 + count_1 * (c1);
            cout<<ans<<endl;
            continue;
        }

        ans = c1 * count_1 + c0 * count_0;
        cout<<ans<<endl;
        continue;
    }    
    return 0;
}