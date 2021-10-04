#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){

    ll n,q;
    cin>>n>>q;
    ll array[n + 1];
    array[0] = 0;
    for(ll i=1;i<=n;i++){
        cin>>array[i];
    }
    
    ll arraycount[n + 1];
    memset(arraycount,0,sizeof(arraycount));
    for(ll i=0;i<q;i++){
        ll start,end;
        cin>>start>>end;
        arraycount[start]++;
        if(end < n){
            arraycount[end + 1]--;
        }
    }
    ll count = 0;
    for(ll i=1;i<=n;i++){
        count += arraycount[i];
        arraycount[i] = count;
    }
    sort(arraycount,arraycount + n + 1);
    sort(array,array + n + 1);
    ll ans = 0;
    for(ll i=1;i<=n;i++){
        ans += (arraycount[i] * array[i]);
    }
    cout<<ans<<endl;
    return 0;
}
